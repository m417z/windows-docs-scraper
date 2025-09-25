HRESULT SetBackgroundProcessingMode(
  [in]  D3D12_BACKGROUND_PROCESSING_MODE Mode,
  [in]  D3D12_MEASUREMENTS_ACTION        MeasurementsAction,
  [in]  HANDLE                           hEventToSignalUponCompletion,
  [out] BOOL                             *pbFurtherMeasurementsDesired
);