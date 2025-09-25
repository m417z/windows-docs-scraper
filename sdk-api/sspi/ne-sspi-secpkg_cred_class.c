typedef enum _SECPKG_CRED_CLASS {
  SecPkgCredClass_None = 0,
  SecPkgCredClass_Ephemeral = 10,
  SecPkgCredClass_PersistedGeneric = 20,
  SecPkgCredClass_PersistedSpecific = 30,
  SecPkgCredClass_Explicit
} SECPKG_CRED_CLASS, *PSECPKG_CRED_CLASS;