typedef struct tagRICHEDIT_IMAGE_PARAMETERS {
  LONG    xWidth;
  LONG    yHeight;
  LONG    Ascent;
  LONG    Type;
  LPCWSTR pwszAlternateText;
  IStream *pIStream;
} RICHEDIT_IMAGE_PARAMETERS;