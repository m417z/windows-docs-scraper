typedef struct _DXVA_PicEntry_HEVC {
  union {
    struct {
      UCHAR  Index7Bits  :7;
      UCHAR  AssociatedFlag   :1;
    };
    UCHAR  bPicEntry;
  };
} DXVA_PicEntry_HEVC, *PDXVA_PicEntry_HEVC;