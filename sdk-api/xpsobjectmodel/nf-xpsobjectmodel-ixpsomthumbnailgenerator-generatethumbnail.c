HRESULT GenerateThumbnail(
  [in]          IXpsOMPage          *page,
  [in]          XPS_IMAGE_TYPE      thumbnailType,
  [in]          XPS_THUMBNAIL_SIZE  thumbnailSize,
  [in]          IOpcPartUri         *imageResourcePartName,
  [out, retval] IXpsOMImageResource **imageResource
);