HRESULT GetPacketDescriptionData(
  [in]      TABLET_CONTEXT_ID tcid,
  [in, out] FLOAT             *pfInkToDeviceScaleX,
  [in, out] FLOAT             *pfInkToDeviceScaleY,
  [in, out] ULONG             *pcPacketProperties,
  [out]     PACKET_PROPERTY   **ppPacketProperties
);