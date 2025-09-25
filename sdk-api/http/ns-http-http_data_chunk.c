typedef struct _HTTP_DATA_CHUNK {
  HTTP_DATA_CHUNK_TYPE DataChunkType;
  union {
    struct {
      PVOID pBuffer;
      ULONG BufferLength;
    } FromMemory;
    struct {
      HTTP_BYTE_RANGE ByteRange;
      HANDLE          FileHandle;
    } FromFileHandle;
    struct {
      USHORT FragmentNameLength;
      PCWSTR pFragmentName;
    } FromFragmentCache;
    struct {
      HTTP_BYTE_RANGE ByteRange;
      PCWSTR          pFragmentName;
    } FromFragmentCacheEx;
    struct {
      USHORT               TrailerCount;
      PHTTP_UNKNOWN_HEADER pTrailers;
    } Trailers;
    struct {
      HTTP_WINHTTP_FAST_FORWARDING_DATA WhFastForwardingData;
    } FromWinHttpFastForwarding;
  };
} HTTP_DATA_CHUNK, *PHTTP_DATA_CHUNK;