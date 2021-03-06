#include "SiPMCrystalPrimaryGeneratorAction.hh"
#include "SiPMCrystalPrimaryGeneratorMessenger.hh"

#include "Randomize.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"

SiPMCrystalPrimaryGeneratorAction::SiPMCrystalPrimaryGeneratorAction()
 : G4VUserPrimaryGeneratorAction(), fParticleGun(0) {
  G4int n_particle = 1;
  fParticleGun = new G4ParticleGun(n_particle);

  //create a messenger for this class
  fGunMessenger = new SiPMCrystalPrimaryGeneratorMessenger(this);

  //default kinematic
  //
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4ParticleDefinition* particle = particleTable->FindParticle("e+");

  fParticleGun->SetParticleDefinition(particle);
  fParticleGun->SetParticleTime(0.0*ns);
  fParticleGun->SetParticlePosition(G4ThreeVector(0.0*cm,0.0*cm,0.0*cm));
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(1.,0.,0.));
  fParticleGun->SetParticleEnergy(500.0*keV);
}

SiPMCrystalPrimaryGeneratorAction::~SiPMCrystalPrimaryGeneratorAction() {
  delete fParticleGun;
  delete fGunMessenger;
}

void SiPMCrystalPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent) {
  fParticleGun->GeneratePrimaryVertex(anEvent);
}

void SiPMCrystalPrimaryGeneratorAction::SetOptPhotonPolar() {
 G4double angle = G4UniformRand() * 360.0*deg;
 SetOptPhotonPolar(angle);
}

void SiPMCrystalPrimaryGeneratorAction::SetOptPhotonPolar(G4double angle) {
  G4cout << "WARNING WARNIG WARNING" << G4endl;
  if (fParticleGun->GetParticleDefinition()->GetParticleName()!="opticalphoton")
   {
     G4cout << "--> warning from PrimaryGeneratorAction::SetOptPhotonPolar() :"
               "the particleGun is not an opticalphoton" << G4endl;
     return;
   }

 G4ThreeVector normal (1., 0., 0.);
 G4ThreeVector kphoton = fParticleGun->GetParticleMomentumDirection();
 G4ThreeVector product = normal.cross(kphoton);
 G4double modul2       = product*product;
 
 G4ThreeVector e_perpend (0., 0., 1.);
 if (modul2 > 0.) e_perpend = (1./std::sqrt(modul2))*product;
 G4ThreeVector e_paralle    = e_perpend.cross(kphoton);
 
 G4ThreeVector polar = std::cos(angle)*e_paralle + std::sin(angle)*e_perpend;
 fParticleGun->SetParticlePolarization(polar);
}

