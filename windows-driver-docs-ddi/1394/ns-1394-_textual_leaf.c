typedef struct _TEXTUAL_LEAF {
  USHORT TL_CRC;
  USHORT TL_Length;
  ULONG  TL_Spec_Id;
  ULONG  TL_Language_Id;
  UCHAR  TL_Data;
} TEXTUAL_LEAF, *PTEXTUAL_LEAF;