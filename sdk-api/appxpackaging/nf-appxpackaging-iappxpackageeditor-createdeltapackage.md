# IAppxPackageEditor::CreateDeltaPackage

## Description

Creates a delta package from the differences in the updated package and the baseline package.

## Parameters

### `updatedPackageStream` [in]

An [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) that provides the contents of the updated app package.

### `baselinePackageStream` [in]

An [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) that provides the contents of the baseline app package.

### `deltaPackageStream` [in]

An [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) that provides the contents of the delta (difference) app package.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAppxPackageEditor](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxpackageeditor)