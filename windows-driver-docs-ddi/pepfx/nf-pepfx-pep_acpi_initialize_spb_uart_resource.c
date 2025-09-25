VOID PEP_ACPI_INITIALIZE_SPB_UART_RESOURCE(
  [in]  ULONG              BaudRate,
  [in]  UCHAR              BitsPerByte,
  [in]  UCHAR              StopBits,
  [in]  UCHAR              LinesInUse,
  [in]  UCHAR              IsBigEndian,
  [in]  UCHAR              Parity,
  [in]  UCHAR              FlowControl,
  [in]  USHORT             RxSize,
  [in]  USHORT             TxSize,
  [in]  PUNICODE_STRING    ResourceSource,
  [in]  UCHAR              ResourceSourceIndex,
  [in]  BOOLEAN            ResourceUsage,
  [in]  BOOLEAN            SharedMode,
  [in]  PCHAR              VendorData,
  [in]  USHORT             VendorDataLength,
  [out] PPEP_ACPI_RESOURCE Resource
);