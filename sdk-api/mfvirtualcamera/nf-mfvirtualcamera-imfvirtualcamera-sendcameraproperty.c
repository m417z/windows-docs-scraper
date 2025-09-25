HRESULT SendCameraProperty(
  REFGUID propertySet,
  ULONG   propertyId,
  ULONG   propertyFlags,
  void    *propertyPayload,
  ULONG   propertyPayloadLength,
  void    *data,
  ULONG   dataLength,
  ULONG   *dataWritten
);