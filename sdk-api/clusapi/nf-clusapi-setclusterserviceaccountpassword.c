DWORD SetClusterServiceAccountPassword(
  [in]           LPCWSTR                      lpszClusterName,
  [in]           LPCWSTR                      lpszNewPassword,
  [in, optional] DWORD                        dwFlags,
  [out]          PCLUSTER_SET_PASSWORD_STATUS lpReturnStatusBuffer,
  [in, out]      LPDWORD                      lpcbReturnStatusBufferSize
);