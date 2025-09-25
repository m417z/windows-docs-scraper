DXGKDDI_NOTIFY_ACPI_EVENT DxgkddiNotifyAcpiEvent;

NTSTATUS DxgkddiNotifyAcpiEvent(
  [in]  IN_CONST_PVOID MiniportDeviceContext,
  [in]  IN_DXGK_EVENT_TYPE EventType,
  [in]  IN_ULONG Event,
  [in]  IN_PVOID Argument,
  [out] OUT_PULONG AcpiFlags
)
{...}