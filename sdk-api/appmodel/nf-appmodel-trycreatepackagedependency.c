HRESULT TryCreatePackageDependency(
  PSID                                    user,
  PCWSTR                                  packageFamilyName,
  PACKAGE_VERSION                         minVersion,
  PackageDependencyProcessorArchitectures packageDependencyProcessorArchitectures,
  PackageDependencyLifetimeKind           lifetimeKind,
  PCWSTR                                  lifetimeArtifact,
  CreatePackageDependencyOptions          options,
  PWSTR                                   *packageDependencyId
);