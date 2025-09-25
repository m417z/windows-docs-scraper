HRESULT CreatePartition(
  [in]  ULONGLONG                   ullOffset,
  [in]  ULONGLONG                   ullSize,
  [in]  CREATE_PARTITION_PARAMETERS *para,
  [out] IVdsAsync                   **ppAsync
);