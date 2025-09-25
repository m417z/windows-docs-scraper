HRESULT FileRangesTransferred(
  IBackgroundCopyJob     *job,
  IBackgroundCopyFile    *file,
  DWORD                  rangeCount,
  const BG_FILE_RANGE [] ranges
);