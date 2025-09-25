BOOL GetUrlCacheGroupAttributeW(
  [in]      GROUPID                      gid,
  [in]      DWORD                        dwFlags,
  [in]      DWORD                        dwAttributes,
  [out]     LPINTERNET_CACHE_GROUP_INFOW lpGroupInfo,
  [in, out] LPDWORD                      lpcbGroupInfo,
  [in, out] LPVOID                       lpReserved
);