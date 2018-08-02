struct particle_inj {
  int n;
  char name[32];
  int pdg;
  double maxpt;
  double maxy;
};

AliGenerator *
GeneratorCustom()
{
  AliGenCocktail *ctl = GeneratorCocktail("Monash2013_TestInjection");

  // pythia8
  AliGenerator   *py8 = GeneratorPythia8(kPythia8Tune_Monash2013);
  ctl->AddGenerator(py8, "Pythia8 (Monash2013)", 1.);

  particle_ing part{1,"ing-proton",2212,6,0.8};

  ctl->UseSingleInjectionPerEvent();
  AliGenerator *inj = GeneratorInjector(particle.n, particle.pdg, 0., particle.maxpt,-particle.maxy, particle.maxy);
  ctl->AddGenerator(inj, (TString(particle.name) + " injector").Data(), 1.);

  return ctl;
}

