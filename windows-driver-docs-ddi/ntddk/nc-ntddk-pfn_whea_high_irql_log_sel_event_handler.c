PFN_WHEA_HIGH_IRQL_LOG_SEL_EVENT_HANDLER PfnWheaHighIrqlLogSelEventHandler;

NTSTATUS PfnWheaHighIrqlLogSelEventHandler(
  PVOID Context,
  PIPMI_OS_SEL_RECORD OsSelRecord
)
{...}