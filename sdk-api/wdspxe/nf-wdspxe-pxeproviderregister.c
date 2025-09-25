DWORD PXEAPI PxeProviderRegister(
  [in]  LPCWSTR       pszProviderName,
  [in]  LPCWSTR       pszModulePath,
  [in]  PXE_REG_INDEX Index,
  [in]  BOOL          bIsCritical,
  [out] PHKEY         phProviderKey
);