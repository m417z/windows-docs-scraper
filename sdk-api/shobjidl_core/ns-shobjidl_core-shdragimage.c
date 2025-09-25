typedef struct SHDRAGIMAGE {
  SIZE     sizeDragImage;
  POINT    ptOffset;
  HBITMAP  hbmpDragImage;
  COLORREF crColorKey;
} SHDRAGIMAGE, *LPSHDRAGIMAGE;