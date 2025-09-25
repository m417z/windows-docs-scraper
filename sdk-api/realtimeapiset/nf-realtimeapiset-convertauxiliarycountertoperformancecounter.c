HRESULT ConvertAuxiliaryCounterToPerformanceCounter(
  [in]            ULONGLONG  ullAuxiliaryCounterValue,
  [out]           PULONGLONG lpPerformanceCounterValue,
  [out, optional] PULONGLONG lpConversionError
);