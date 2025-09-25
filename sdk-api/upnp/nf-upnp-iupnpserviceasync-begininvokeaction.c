HRESULT BeginInvokeAction(
  [in]           BSTR             bstrActionName,
  [in]           VARIANT          vInActionArgs,
  [in, optional] IUPnPAsyncResult *pAsyncResult,
  [out]          PULONG64         pullRequestID
);