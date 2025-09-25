PVIDEO_BUGCHECK_CALLBACK PvideoBugcheckCallback;

VOID PvideoBugcheckCallback(
  [in] IN PVOID HwDeviceExtension,
  [in] IN ULONG BugcheckCode,
  [in] IN PUCHAR Buffer,
  [in] IN ULONG BufferSize
)
{...}