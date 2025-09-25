BOOL GetUrlCacheGroupAttributeA(
  [in]      GROUPID                      gid,
  [in]      DWORD                        dwFlags,
  [in]      DWORD                        dwAttributes,
  [out]     LPINTERNET_CACHE_GROUP_INFOA lpGroupInfo,
  [in, out] LPDWORD                      lpcbGroupInfo,
  [in, out] LPVOID                       lpReserved
);