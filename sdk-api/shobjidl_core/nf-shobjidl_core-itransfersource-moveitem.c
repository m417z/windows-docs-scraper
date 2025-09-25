HRESULT MoveItem(
  [in]  IShellItem            *psi,
  [in]  IShellItem            *psiParentDst,
  [in]  LPCWSTR               pszNameDst,
        TRANSFER_SOURCE_FLAGS flags,
  [out] IShellItem            **ppsiNew
);