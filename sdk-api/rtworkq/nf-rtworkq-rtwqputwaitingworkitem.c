HRESULT RtwqPutWaitingWorkItem(
  [in]            HANDLE           hEvent,
  [in]            LONG             lPriority,
  [in]            IRtwqAsyncResult *result,
  [out, optional] RTWQWORKITEM_KEY *key
);