HRESULT SerializeWithOptions(
  [in]      SYNC_SERIALIZATION_VERSION targetFormatVersion,
  [in]      DWORD                      dwFlags,
  [in, out] BYTE                       *pbBuffer,
  [in, out] DWORD                      *pdwSerializedSize
);