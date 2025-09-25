struct TestInvokeFunctor {
  void                TestInvokeFunctor(
    T &        instance,
    TestMethod pTestMethod
  );
  bool                operator()();
  void                TestInvokeFunctor(
    const TestInvokeFunctor & unnamedParam1
  );
  TestInvokeFunctor & operator=(
    const TestInvokeFunctor & unnamedParam1
  );
  TestMethod          m_pTestMethod;
  T &                 m_instance;
};