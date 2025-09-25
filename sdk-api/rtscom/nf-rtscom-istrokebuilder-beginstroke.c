HRESULT BeginStroke(
  [in]      TABLET_CONTEXT_ID tcid,
  [in]      STYLUS_ID         sid,
  [in]      const LONG        *pPacket,
  [in]      ULONG             cPacketProperties,
  [in]      PACKET_PROPERTY   *pPacketProperties,
  [in]      FLOAT             fInkToDeviceScaleX,
  [in]      FLOAT             fInkToDeviceScaleY,
  [in, out] IInkStrokeDisp    **ppIInkStroke
);