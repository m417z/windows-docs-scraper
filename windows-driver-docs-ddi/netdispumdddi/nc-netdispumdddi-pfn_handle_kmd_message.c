PFN_HANDLE_KMD_MESSAGE PfnHandleKmdMessage;

NTSTATUS PfnHandleKmdMessage(
  [in]  PVOID pMiracastContext,
  [in]  UINT InputBufferSize,
  [in]  VOID *pInputBuffer,
  [in]  UINT OutputBufferSize,
  [out] VOID *pOutputBuffer,
  [out] UINT *pBytesReturned
)
{...}