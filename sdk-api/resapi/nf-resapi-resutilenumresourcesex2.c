DWORD ResUtilEnumResourcesEx2(
  [in]           HCLUSTER               hCluster,
  [in, optional] HRESOURCE              hSelf,
  [in]           LPCWSTR                lpszResTypeName,
  [in]           LPRESOURCE_CALLBACK_EX pResCallBack,
  [in]           PVOID                  pParameter,
  [in]           DWORD                  dwDesiredAccess
);