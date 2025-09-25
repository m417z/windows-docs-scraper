NTSTATUS WdfDriverErrorReportApiMissing(
  WDFDRIVER Driver,
  PCWSTR    FrameworkExtensionName,
  ULONG     ApiIndex,
  BOOLEAN   DoesApiReturnNtstatus
);