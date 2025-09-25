HRESULT CreateImageBrush(
  [in]           ID2D1Image                        *image,
  [in]           const D2D1_IMAGE_BRUSH_PROPERTIES *imageBrushProperties,
  [in, optional] const D2D1_BRUSH_PROPERTIES       *brushProperties,
  [out]          ID2D1ImageBrush                   **imageBrush
);