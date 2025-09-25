HRESULT MFCreateMediaEvent(
  MediaEventType    met,
  REFGUID           guidExtendedType,
  HRESULT           hrStatus,
  const PROPVARIANT *pvValue,
  IMFMediaEvent     **ppEvent
);