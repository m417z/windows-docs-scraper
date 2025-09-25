HRESULT GetClaimsToken2(
  [in]          BSTR  bstrClaimsHint,
  [in]          BSTR  bstrUserHint,
  [in]          ULONG claimCookie,
  [in]          ULONG hwndCredUiParent,
  [in]          RECT  rectCredUiParent,
  [out, retval] BSTR  *pbstrAccessToken
);