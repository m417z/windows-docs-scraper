typedef struct _NDIS_RECEIVE_SCALE_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  USHORT             Flags;
  USHORT             BaseCpuNumber;
  ULONG              HashInformation;
  USHORT             IndirectionTableSize;
  ULONG              IndirectionTableOffset;
  USHORT             HashSecretKeySize;
  ULONG              HashSecretKeyOffset;
  ULONG              ProcessorMasksOffset;
  ULONG              NumberOfProcessorMasks;
  ULONG              ProcessorMasksEntrySize;
  PROCESSOR_NUMBER   DefaultProcessorNumber;
} NDIS_RECEIVE_SCALE_PARAMETERS, *PNDIS_RECEIVE_SCALE_PARAMETERS;