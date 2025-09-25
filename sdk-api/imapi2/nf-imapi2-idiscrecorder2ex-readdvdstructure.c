HRESULT ReadDvdStructure(
  [in]  ULONG                      format,
  [in]  ULONG                      address,
  [in]  ULONG                      layer,
  [in]  ULONG                      agid,
  [out] BYTE                       **data,
  [out] ULONG_IMAPI2_DVD_STRUCTURE *count
);