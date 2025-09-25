typedef enum StringFormatFlags {
  StringFormatFlagsDirectionRightToLeft = 0x00000001,
  StringFormatFlagsDirectionVertical = 0x00000002,
  StringFormatFlagsNoFitBlackBox = 0x00000004,
  StringFormatFlagsDisplayFormatControl = 0x00000020,
  StringFormatFlagsNoFontFallback = 0x00000400,
  StringFormatFlagsMeasureTrailingSpaces = 0x00000800,
  StringFormatFlagsNoWrap = 0x00001000,
  StringFormatFlagsLineLimit = 0x00002000,
  StringFormatFlagsNoClip = 0x00004000,
  StringFormatFlagsBypassGDI = 0x80000000
} ;