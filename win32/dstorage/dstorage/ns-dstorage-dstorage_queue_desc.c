struct DSTORAGE_QUEUE_DESC {
  DSTORAGE_REQUEST_SOURCE_TYPE SourceType;
  UINT16                       Capacity;
  DSTORAGE_PRIORITY            Priority;
  const CHAR                   *Name;
  ID3D12Device                 *Device;
};