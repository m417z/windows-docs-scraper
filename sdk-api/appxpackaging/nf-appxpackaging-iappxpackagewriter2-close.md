# IAppxPackageWriter2::Close

## Description

Closes the package writer object's output stream.

## Parameters

### `manifest` [in]

The stream that provides the contents of the manifest for the package. The stream must support [Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read), [Seek](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-seek), and [Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-stat).

### `contentGroupMap` [in]

The stream that provides the contents of the content group map for the package.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **E_NOT_VALID_STATE** | The writer is closed. |
| **APPX_E_INVALID_MANIFEST** | The input stream contains a manifest that is not valid. |

## See also

[IAppxPackageWriter2](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxpackagewriter2)