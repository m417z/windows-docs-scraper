typedef struct _SecPkgContext_EapKeyBlock {
  BYTE rgbKeys[128];
  BYTE rgbIVs[64];
} SecPkgContext_EapKeyBlock, *PSecPkgContext_EapKeyBlock;