HRESULT CreatePageFromStream(
  [in]          IStream             *pageMarkupStream,
  [in]          IOpcPartUri         *partUri,
  [in]          IXpsOMPartResources *resources,
  [in]          BOOL                reuseObjects,
  [out, retval] IXpsOMPage          **page
);