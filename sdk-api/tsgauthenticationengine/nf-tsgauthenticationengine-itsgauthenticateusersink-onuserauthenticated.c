HRESULT OnUserAuthenticated(
  [in]           BSTR       userName,
  [in]           BSTR       userDomain,
  [in]           ULONG_PTR  context,
  [in, optional] HANDLE_PTR userToken
);