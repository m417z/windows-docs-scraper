typedef struct {
  LARGE_INTEGER StartingLcn;
  LARGE_INTEGER BitmapSize;
  UCHAR         Buffer[1];
} VOLUME_BITMAP_BUFFER, *PVOLUME_BITMAP_BUFFER;