typedef enum _HTTP_DATA_CHUNK_TYPE {
  HttpDataChunkFromMemory,
  HttpDataChunkFromFileHandle,
  HttpDataChunkFromFragmentCache,
  HttpDataChunkFromFragmentCacheEx,
  HttpDataChunkTrailers,
  HttpDataChunkFromWinHttpFastForwarding,
  HttpDataChunkMaximum
} HTTP_DATA_CHUNK_TYPE, *PHTTP_DATA_CHUNK_TYPE;