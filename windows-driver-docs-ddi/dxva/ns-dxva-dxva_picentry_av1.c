typedef struct _DXVA_PicEntry_AV1 {
  UINT   width;
  UINT   height;
  INT    wmmat[6];
  union {
    struct {
      UCHAR wminvalid : 1;
      UCHAR wmtype : 2;
      UCHAR Reserved : 5;
    };
    UCHAR GlobalMotionFlags;
  } DUMMYUNIONNAME;
  UCHAR  Index;
  UINT16 Reserved16Bits;
} DXVA_PicEntry_AV1, *LPDXVA_PicEntry_AV1;