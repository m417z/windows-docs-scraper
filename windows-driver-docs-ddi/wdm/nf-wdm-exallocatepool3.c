DECLSPEC_RESTRICT PVOID ExAllocatePool3(
  POOL_FLAGS                Flags,
  SIZE_T                    NumberOfBytes,
  ULONG                     Tag,
  PCPOOL_EXTENDED_PARAMETER ExtendedParameters,
  ULONG                     ExtendedParametersCount
);