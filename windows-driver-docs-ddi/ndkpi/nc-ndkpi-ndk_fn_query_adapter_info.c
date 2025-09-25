NDK_FN_QUERY_ADAPTER_INFO NdkFnQueryAdapterInfo;

NTSTATUS NdkFnQueryAdapterInfo(
  [in] NDK_ADAPTER *pNdkAdapter,
       NDK_ADAPTER_INFO *pInfo,
       ULONG *pBufferSize
)
{...}