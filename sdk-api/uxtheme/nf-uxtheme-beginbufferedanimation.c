HANIMATIONBUFFER BeginBufferedAnimation(
        HWND               hwnd,
        HDC                hdcTarget,
        const RECT         *prcTarget,
        BP_BUFFERFORMAT    dwFormat,
  [in]  BP_PAINTPARAMS     *pPaintParams,
  [in]  BP_ANIMATIONPARAMS *pAnimationParams,
  [out] HDC                *phdcFrom,
  [out] HDC                *phdcTo
);