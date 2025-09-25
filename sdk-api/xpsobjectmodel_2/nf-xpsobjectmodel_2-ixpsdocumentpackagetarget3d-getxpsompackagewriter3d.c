HRESULT GetXpsOMPackageWriter3D(
  [in]           IOpcPartUri           *documentSequencePartName,
  [in, optional] IOpcPartUri           *discardControlPartName,
  [in]           IOpcPartUri           *modelPartName,
  [in]           IStream               *modelData,
  [out]          IXpsOMPackageWriter3D **packageWriter
);