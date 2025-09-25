NTSTATUS EntropyProvideData(
  ENTROPY_SOURCE_HANDLE hEntropySource,
  PCBYTE                pbData,
  SIZE_T                cbData,
  ULONG                 entropyEstimateInMilliBits
);