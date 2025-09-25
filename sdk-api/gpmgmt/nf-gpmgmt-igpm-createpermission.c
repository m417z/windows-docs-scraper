HRESULT CreatePermission(
  [in]  BSTR              bstrTrustee,
  [in]  GPMPermissionType perm,
  [in]  VARIANT_BOOL      bInheritable,
  [out] IGPMPermission    **ppPerm
);