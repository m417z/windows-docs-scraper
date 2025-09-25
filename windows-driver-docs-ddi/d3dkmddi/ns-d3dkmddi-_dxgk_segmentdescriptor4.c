typedef struct _DXGK_SEGMENTDESCRIPTOR4 {
  DXGK_SEGMENTFLAGS Flags;
  PHYSICAL_ADDRESS  BaseAddress;
  SIZE_T            Size;
  SIZE_T            CommitLimit;
  SIZE_T            SystemMemoryEndAddress;
  union {
    PHYSICAL_ADDRESS     CpuTranslatedAddress;
    DXGK_CPUHOSTAPERTURE CpuHostAperture;
  };
  UINT              NumInvalidMemoryRanges;
  SIZE_T            VprRangeStartOffset;
  SIZE_T            VprRangeSize;
  UINT              VprAlignment;
  UINT              NumVprSupported;
  UINT              VprReserveSize;
  UINT              NumUEFIFrameBufferRanges;
} DXGK_SEGMENTDESCRIPTOR4;