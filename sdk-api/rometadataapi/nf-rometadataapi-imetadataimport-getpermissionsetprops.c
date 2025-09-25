HRESULT GetPermissionSetProps(
  [in]  mdPermission tk,
  [out] DWORD        *pdwAction,
  [out] const BYTE   **ppvPermission,
  [out] ULONG        *pcbPermission
);