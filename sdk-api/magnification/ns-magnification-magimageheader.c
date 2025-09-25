typedef struct tagMAGIMAGEHEADER {
  UINT               width;
  UINT               height;
  WICPixelFormatGUID format;
  UINT               stride;
  UINT               offset;
  SIZE_T             cbSize;
} MAGIMAGEHEADER, *PMAGIMAGEHEADER;