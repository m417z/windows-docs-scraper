typedef struct _WHEA_ERROR_PACKET_V1 {
  ULONG                   Signature;
  WHEA_ERROR_PACKET_FLAGS Flags;
  ULONG                   Size;
  ULONG                   RawDataLength;
  ULONGLONG               Reserved1;
  ULONGLONG               Context;
  WHEA_ERROR_TYPE         ErrorType;
  WHEA_ERROR_SEVERITY     ErrorSeverity;
  ULONG                   ErrorSourceId;
  WHEA_ERROR_SOURCE_TYPE  ErrorSourceType;
  ULONG                   Reserved2;
  ULONG                   Version;
  ULONGLONG               Cpu;
  union {
    WHEA_PROCESSOR_GENERIC_ERROR_SECTION ProcessorError;
    WHEA_MEMORY_ERROR_SECTION            MemoryError;
    WHEA_NMI_ERROR_SECTION               NmiError;
    WHEA_PCIEXPRESS_ERROR_SECTION        PciExpressError;
    WHEA_PCIXBUS_ERROR_SECTION           PciXBusError;
    WHEA_PCIXDEVICE_ERROR_SECTION        PciXDeviceError;
    WHEA_PMEM_ERROR_SECTION              PmemError;
  } u;
  WHEA_RAW_DATA_FORMAT    RawDataFormat;
  ULONG                   RawDataOffset;
  UCHAR                   RawData[1];
} WHEA_ERROR_PACKET_V1, *PWHEA_ERROR_PACKET_V1, WHEA_ERROR_PACKET, *PWHEA_ERROR_PACKET;