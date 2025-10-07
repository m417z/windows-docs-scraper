HRESULT WINAPI MpUpdateStart(
  _In_     MPHANDLE         hMpHandle,
  _In_     DWORD            dwUpdateOptions,
  _In_opt_ PMPCALLBACK_INFO pCallbackInfo,
  _Out_    PMPHANDLE        phUpdateHandle
);