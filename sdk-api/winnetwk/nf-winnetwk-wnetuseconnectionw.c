DWORD WNetUseConnectionW(
  [in]      HWND           hwndOwner,
  [in]      LPNETRESOURCEW lpNetResource,
  [in]      LPCWSTR        lpPassword,
  [in]      LPCWSTR        lpUserId,
  [in]      DWORD          dwFlags,
  [out]     LPWSTR         lpAccessName,
  [in, out] LPDWORD        lpBufferSize,
  [out]     LPDWORD        lpResult
);