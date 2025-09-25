UINT32 ConvertWeightStretchStyleToFontAxisValues(
  DWRITE_FONT_AXIS_VALUE const *inputAxisValues,
  UINT32                       inputAxisCount,
  DWRITE_FONT_WEIGHT           fontWeight,
  DWRITE_FONT_STRETCH          fontStretch,
  DWRITE_FONT_STYLE            fontStyle,
  float                        fontSize,
  DWRITE_FONT_AXIS_VALUE       *outputAxisValues
);