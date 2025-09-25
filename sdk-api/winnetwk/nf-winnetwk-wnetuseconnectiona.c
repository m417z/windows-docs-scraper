DWORD WNetUseConnectionA(
  [in]      HWND           hwndOwner,
  [in]      LPNETRESOURCEA lpNetResource,
  [in]      LPCSTR         lpPassword,
  [in]      LPCSTR         lpUserId,
  [in]      DWORD          dwFlags,
  [out]     LPSTR          lpAccessName,
  [in, out] LPDWORD        lpBufferSize,
  [out]     LPDWORD        lpResult
);