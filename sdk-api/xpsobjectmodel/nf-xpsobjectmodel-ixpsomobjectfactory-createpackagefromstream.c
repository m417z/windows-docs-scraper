HRESULT CreatePackageFromStream(
  [in]          IStream       *stream,
  [in]          BOOL          reuseObjects,
  [out, retval] IXpsOMPackage **package
);