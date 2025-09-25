HRESULT CreateDeltaPackageUsingBaselineBlockMap(
  [in] IStream *updatedPackageStream,
  [in] IStream *baselineBlockMapStream,
  [in] LPCWSTR baselinePackageFullName,
  [in] IStream *deltaPackageStream
);