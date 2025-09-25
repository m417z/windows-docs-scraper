HRESULT GetSeekPositionForValue(
  [in]  const PROPVARIANT    *pvarValue,
  [in]  ASF_INDEX_IDENTIFIER *pIndexIdentifier,
  [out] QWORD                *pcbOffsetWithinData,
  [out] MFTIME               *phnsApproxTime,
  [out] DWORD                *pdwPayloadNumberOfStreamWithinPacket
);