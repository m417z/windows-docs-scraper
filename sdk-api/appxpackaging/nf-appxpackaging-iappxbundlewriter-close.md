# IAppxBundleWriter::Close

## Description

Finalizes the bundle package by writing footprint files at the end of the package, and closes the writer’s output stream.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **E_NOT_VALID_STATE** | The writer is closed. |

## See also

[IAppxBundleWriter](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxbundlewriter)