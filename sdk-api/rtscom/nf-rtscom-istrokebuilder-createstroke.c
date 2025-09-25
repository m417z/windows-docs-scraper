HRESULT CreateStroke(
  [in]      ULONG                 cPktBuffLength,
  [in]      const LONG            *pPackets,
  [in]      ULONG                 cPacketProperties,
  [in]      const PACKET_PROPERTY *pPacketProperties,
  [in]      FLOAT                 fInkToDeviceScaleX,
  [in]      FLOAT                 fInkToDeviceScaleY,
  [in, out] IInkStrokeDisp        **ppIInkStroke
);