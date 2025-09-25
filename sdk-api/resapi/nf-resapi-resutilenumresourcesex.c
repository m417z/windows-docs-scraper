DWORD ResUtilEnumResourcesEx(
  [in]           HCLUSTER               hCluster,
  [in, optional] HRESOURCE              hSelf,
  [in]           LPCWSTR                lpszResTypeName,
  [in]           LPRESOURCE_CALLBACK_EX pResCallBack,
  [in]           PVOID                  pParameter
);