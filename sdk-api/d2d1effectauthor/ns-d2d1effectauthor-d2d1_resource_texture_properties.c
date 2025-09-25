typedef struct D2D1_RESOURCE_TEXTURE_PROPERTIES {
  const UINT32           *extents;
  UINT32                 dimensions;
  D2D1_BUFFER_PRECISION  bufferPrecision;
  D2D1_CHANNEL_DEPTH     channelDepth;
  D2D1_FILTER            filter;
  const D2D1_EXTEND_MODE *extendModes;
} D2D1_RESOURCE_TEXTURE_PROPERTIES;