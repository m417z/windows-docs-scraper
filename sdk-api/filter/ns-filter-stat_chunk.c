typedef struct tagSTAT_CHUNK {
  ULONG           idChunk;
  CHUNK_BREAKTYPE breakType;
  CHUNKSTATE      flags;
  LCID            locale;
  FULLPROPSPEC    attribute;
  ULONG           idChunkSource;
  ULONG           cwcStartSource;
  ULONG           cwcLenSource;
} STAT_CHUNK;