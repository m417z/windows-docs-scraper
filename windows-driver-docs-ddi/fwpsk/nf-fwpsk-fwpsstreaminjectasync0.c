NTSTATUS FwpsStreamInjectAsync0(
  [in]           HANDLE                injectionHandle,
  [in, optional] HANDLE                injectionContext,
  [in]           UINT32                flags,
  [in]           UINT64                flowId,
  [in]           UINT32                calloutId,
  [in]           UINT16                layerId,
  [in]           UINT32                streamFlags,
  [in, out]      NET_BUFFER_LIST       *netBufferList,
  [in]           SIZE_T                dataLength,
  [in]           FWPS_INJECT_COMPLETE0 completionFn,
  [in, optional] HANDLE                completionContext
);