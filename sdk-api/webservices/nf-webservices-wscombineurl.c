HRESULT WsCombineUrl(
  [in]           const WS_STRING *baseUrl,
  [in]           const WS_STRING *referenceUrl,
  [in]           ULONG           flags,
  [in]           WS_HEAP         *heap,
  [out]          WS_STRING       *resultUrl,
  [in, optional] WS_ERROR        *error
);