struct DSTORAGE_REQUEST_OPTIONS {
  DSTORAGE_COMPRESSION_FORMAT       CompressionFormat : 8;
  DSTORAGE_REQUEST_SOURCE_TYPE      SourceType : 1;
  DSTORAGE_REQUEST_DESTINATION_TYPE DestinationType : 7;
  UINT64                            Reserved : 48;
};