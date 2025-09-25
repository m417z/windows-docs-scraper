struct DWRITE_GLYPH_IMAGE_DATA {
  void const    *imageData;
  UINT32        imageDataSize;
  UINT32        uniqueDataId;
  UINT32        pixelsPerEm;
  D2D1_SIZE_U   pixelSize;
  D2D1_POINT_2L horizontalLeftOrigin;
  D2D1_POINT_2L horizontalRightOrigin;
  D2D1_POINT_2L verticalTopOrigin;
  D2D1_POINT_2L verticalBottomOrigin;
};