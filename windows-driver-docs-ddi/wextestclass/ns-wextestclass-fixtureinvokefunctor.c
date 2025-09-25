struct FixtureInvokeFunctor {
  void                   FixtureInvokeFunctor(
    T &           instance,
    FixtureMethod pFixtureMethod
  );
  bool                   operator()();
  void                   FixtureInvokeFunctor(
    const FixtureInvokeFunctor & unnamedParam1
  );
  FixtureInvokeFunctor & operator=(
    const FixtureInvokeFunctor & unnamedParam1
  );
  FixtureMethod          m_pFixtureMethod;
  T &                    m_instance;
};