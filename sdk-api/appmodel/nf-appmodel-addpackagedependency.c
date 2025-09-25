HRESULT AddPackageDependency(
  PCWSTR                      packageDependencyId,
  INT32                       rank,
  AddPackageDependencyOptions options,
  PACKAGEDEPENDENCY_CONTEXT   *packageDependencyContext,
  PWSTR                       *packageFullName
);