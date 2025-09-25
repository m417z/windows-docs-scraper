# IAppxPackageEditor::UpdatePackageManifest

## Description

Updates an app package manifest.

## Parameters

### `packageStream` [in]

An [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) that provides the contents of the app package associated with the manifest to be updated.

### `updatedManifestStream` [in]

An [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) that provides the contents of the updated app package manifest.

### `isPackageEncrypted` [in]

Flag to specify whether the package is encrypted.

### `options` [in]

Options for app package manifest validation.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAppxPackageEditor](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxpackageeditor)