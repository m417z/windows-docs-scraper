PCW_CALLBACK PcwCallback;

NTSTATUS PcwCallback(
  [in]           PCW_CALLBACK_TYPE Type,
  [in]           PPCW_CALLBACK_INFORMATION Info,
  [in, optional] PVOID Context
)
{...}