HRESULT Packets(
  [in]      IRealTimeStylus  *piRtsSrc,
  [in]      const StylusInfo *pStylusInfo,
  [in]      ULONG            cPktCount,
  [in]      ULONG            cPktBuffLength,
  [in]      LONG             *pPackets,
  [in, out] ULONG            *pcInOutPkts,
  [in, out] LONG             **ppInOutPkts
);