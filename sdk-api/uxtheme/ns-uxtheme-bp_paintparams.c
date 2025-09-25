typedef struct _BP_PAINTPARAMS {
  DWORD               cbSize;
  DWORD               dwFlags;
  const RECT          *prcExclude;
  const BLENDFUNCTION *pBlendFunction;
} BP_PAINTPARAMS, *PBP_PAINTPARAMS;