typedef struct _D3DDDI_RESOURCEFLAGS {
  union {
    struct {
      UINT RenderTarget : 1;
      UINT ZBuffer : 1;
      UINT Dynamic : 1;
      UINT HintStatic : 1;
      UINT AutogenMipmap : 1;
      UINT DMap : 1;
      UINT WriteOnly : 1;
      UINT NotLockable : 1;
      UINT Points : 1;
      UINT RtPatches : 1;
      UINT NPatches : 1;
      UINT SharedResource : 1;
      UINT DiscardRenderTarget : 1;
      UINT Video : 1;
      UINT CaptureBuffer : 1;
      UINT Primary : 1;
      UINT Texture : 1;
      UINT CubeMap : 1;
      UINT Volume : 1;
      UINT VertexBuffer : 1;
      UINT IndexBuffer : 1;
      UINT DecodeRenderTarget : 1;
      UINT DecodeCompressedBuffer : 1;
      UINT VideoProcessRenderTarget : 1;
      UINT CpuOptimized : 1;
      UINT MightDrawFromLocked : 1;
      UINT Overlay : 1;
      UINT MatchGdiPrimary : 1;
      UINT InterlacedRefresh : 1;
      UINT TextApi : 1;
      UINT RestrictedContent : 1;
      UINT RestrictSharedAccess : 1;
    };
    UINT Value;
  };
} D3DDDI_RESOURCEFLAGS;