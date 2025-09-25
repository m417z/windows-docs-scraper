HRESULT ActivateAudioInterfaceAsync(
  [in] LPCWSTR                                  deviceInterfacePath,
  [in] REFIID                                   riid,
  [in] PROPVARIANT                              *activationParams,
  [in] IActivateAudioInterfaceCompletionHandler *completionHandler,
       IActivateAudioInterfaceAsyncOperation    **activationOperation
);