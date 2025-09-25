BOOL SetThreadIdealProcessorEx(
  [in]            HANDLE            hThread,
  [in]            PPROCESSOR_NUMBER lpIdealProcessor,
  [out, optional] PPROCESSOR_NUMBER lpPreviousIdealProcessor
);