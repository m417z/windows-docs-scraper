typedef struct _FORMATOP {
  [in]  D3DDDIFORMAT Format;
  [out] UINT         Operations;
  [out] UINT         FlipMsTypes;
  [out] UINT         BltMsTypes;
  [out] UINT         PrivateFormatBitCount;
} FORMATOP;