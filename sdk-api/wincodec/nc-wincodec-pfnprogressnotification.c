PFNProgressNotification Pfnprogressnotification;

HRESULT Pfnprogressnotification(
  LPVOID pvData,
  ULONG uFrameNum,
  WICProgressOperation operation,
  double dblProgress
)
{...}