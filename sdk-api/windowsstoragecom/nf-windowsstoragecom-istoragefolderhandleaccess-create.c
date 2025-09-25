HRESULT Create(
  [in]           LPCWSTR                 fileName,
  [in]           HANDLE_CREATION_OPTIONS creationOptions,
  [in]           HANDLE_ACCESS_OPTIONS   accessOptions,
  [in]           HANDLE_SHARING_OPTIONS  sharingOptions,
  [in]           HANDLE_OPTIONS          options,
  [in, optional] IOplockBreakingHandler  *oplockBreakingHandler,
  [out, retval]  HANDLE                  *interopHandle
);