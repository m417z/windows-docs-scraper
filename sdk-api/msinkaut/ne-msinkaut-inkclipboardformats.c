typedef enum InkClipboardFormats {
  ICF_None = 0,
  ICF_InkSerializedFormat = 0x1,
  ICF_SketchInk = 0x2,
  ICF_TextInk = 0x6,
  ICF_EnhancedMetafile = 0x8,
  ICF_Metafile = 0x20,
  ICF_Bitmap = 0x40,
  ICF_PasteMask = 0x7,
  ICF_CopyMask = 0x7f,
  ICF_Default
} ;