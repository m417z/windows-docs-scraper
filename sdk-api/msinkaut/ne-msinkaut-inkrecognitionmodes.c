typedef enum InkRecognitionModes {
  IRM_None = 0,
  IRM_WordModeOnly = 0x1,
  IRM_Coerce = 0x2,
  IRM_TopInkBreaksOnly = 0x4,
  IRM_PrefixOk = 0x8,
  IRM_LineMode = 0x10,
  IRM_DisablePersonalization = 0x20,
  IRM_AutoSpace = 0x40,
  IRM_Max = 0x80
} ;