PLOAD_IMAGE_NOTIFY_ROUTINE PloadImageNotifyRoutine;

VOID PloadImageNotifyRoutine(
  [in, optional] PUNICODE_STRING FullImageName,
  [in]           HANDLE ProcessId,
  [in]           PIMAGE_INFO ImageInfo
)
{...}