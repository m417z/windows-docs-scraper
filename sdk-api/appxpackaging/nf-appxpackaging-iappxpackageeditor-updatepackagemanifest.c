HRESULT UpdatePackageManifest(
  [in] IStream                                             *packageStream,
  [in] IStream                                             *updatedManifestStream,
  [in] BOOL                                                isPackageEncrypted,
  [in] APPX_PACKAGE_EDITOR_UPDATE_PACKAGE_MANIFEST_OPTIONS options
);