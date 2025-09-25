LSTATUS SHRegSetUSValueW(
                 LPCWSTR    pwzSubKey,
                 LPCWSTR    pwzValue,
  [in]           DWORD      dwType,
  [in, optional] const void *pvData,
  [in, optional] DWORD      cbData,
  [in, optional] DWORD      dwFlags
);