HRESULT GetEffectRequiredInputRectangles(
  [in]           ID2D1Effect                         *renderEffect,
  [in, optional] const D2D1_RECT_F                   *renderImageRectangle,
  [in]           const D2D1_EFFECT_INPUT_DESCRIPTION *inputDescriptions,
  [out]          D2D1_RECT_F                         *requiredInputRects,
                 UINT32                              inputCount
);