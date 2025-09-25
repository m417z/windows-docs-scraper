HRESULT StylusDown(
  [in]      IRealTimeStylus  *piRtsSrc,
  [in]      const StylusInfo *pStylusInfo,
  [in]      ULONG            cPropCountPerPkt,
  [in]      LONG             *pPacket,
  [in, out] LONG             **ppInOutPkt
);