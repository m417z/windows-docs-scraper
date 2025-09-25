HRESULT Initialize(
  [in]           IMFCaptureEngineOnEventCallback *pEventCallback,
  [in, optional] IMFAttributes                   *pAttributes,
  [in, optional] IUnknown                        *pAudioSource,
  [in, optional] IUnknown                        *pVideoSource
);