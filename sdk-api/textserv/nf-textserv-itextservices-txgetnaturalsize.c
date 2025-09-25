HRESULT TxGetNaturalSize(
            DWORD          dwAspect,
            HDC            hdcDraw,
            HDC            hicTargetDev,
            DVTARGETDEVICE *ptd,
            DWORD          dwMode,
            const SIZEL    *psizelExtent,
  [in, out] LONG           *pwidth,
  [in, out] LONG           *pheight
);