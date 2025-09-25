HRESULT ReadPackageFromStream(
  [in]          IStream        *stream,
  [in]          OPC_READ_FLAGS flags,
  [out, retval] IOpcPackage    **package
);