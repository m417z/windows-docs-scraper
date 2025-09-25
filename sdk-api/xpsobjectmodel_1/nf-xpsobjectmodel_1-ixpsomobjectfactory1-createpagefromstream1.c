HRESULT CreatePageFromStream1(
  IStream             *pageMarkupStream,
  IOpcPartUri         *partUri,
  IXpsOMPartResources *resources,
  BOOL                reuseObjects,
  IXpsOMPage1         **page
);