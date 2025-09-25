HRESULT CreatePartitionEx(
  [in]  ULONGLONG                   ullOffset,
  [in]  ULONGLONG                   ullSize,
  [in]  ULONG                       ulAlign,
  [in]  CREATE_PARTITION_PARAMETERS *para,
  [out] IVdsAsync                   **ppAsync
);