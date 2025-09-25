HRESULT Free(
  [in] ICallFrame       *pframeArgsDest,
  [in] ICallFrameWalker *pWalkerDestFree,
  [in] ICallFrameWalker *pWalkerCopy,
  [in] DWORD            freeFlags,
  [in] ICallFrameWalker *pWalkerFree,
  [in] DWORD            nullFlags
);