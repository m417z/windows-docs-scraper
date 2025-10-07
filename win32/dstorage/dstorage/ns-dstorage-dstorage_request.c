struct DSTORAGE_REQUEST {
  DSTORAGE_REQUEST_OPTIONS Options;
  DSTORAGE_SOURCE          Source;
  DSTORAGE_DESTINATION     Destination;
  UINT32                   UncompressedSize;
  UINT64                   CancellationTag;
  const CHAR               *Name;
};