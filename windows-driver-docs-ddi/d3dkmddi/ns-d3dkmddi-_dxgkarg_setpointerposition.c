typedef struct _DXGKARG_SETPOINTERPOSITION {
  [in] D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [in] INT                            X;
  [in] INT                            Y;
  [in] DXGK_SETPOINTERPOSITIONFLAGS   Flags;
} DXGKARG_SETPOINTERPOSITION;