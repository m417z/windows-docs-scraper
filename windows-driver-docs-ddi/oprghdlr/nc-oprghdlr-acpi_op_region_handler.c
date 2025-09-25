ACPI_OP_REGION_HANDLER AcpiOpRegionHandler;

NTSTATUS AcpiOpRegionHandler(
  ULONG AccessType,
  PVOID OperationRegionObject,
  ULONG Address,
  ULONG Size,
  PULONG Data,
  ULONG_PTR Context,
  PACPI_OP_REGION_CALLBACK CompletionHandler,
  PVOID CompletionContext
)
{...}