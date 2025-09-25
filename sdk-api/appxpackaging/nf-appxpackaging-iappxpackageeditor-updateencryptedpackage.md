# IAppxPackageEditor::UpdateEncryptedPackage

## Description

Updates an encrypted app package.

## Parameters

### `baselineEncryptedPackageStream` [in]

An [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) that provides the contents of the baseline encrypted app package.

### `deltaPackageStream` [in]

An [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) that provides the contents of the delta (difference) app package.

### `updateOption` [in]

The update options.

### `settings` [in]

The encrypted app package settings.

### `keyInfo` [in]

App package key information.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAppxPackageEditor](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxpackageeditor)