HRESULT SetDpiCompensatedEffectInput(
  [in]           ID2D1DeviceContext      *deviceContext,
  [in]           ID2D1Effect             *effect,
                 UINT32                  inputIndex,
  [in, optional] ID2D1Bitmap             *inputBitmap,
                 D2D1_INTERPOLATION_MODE interpolationMode,
                 D2D1_BORDER_MODE        borderMode
);