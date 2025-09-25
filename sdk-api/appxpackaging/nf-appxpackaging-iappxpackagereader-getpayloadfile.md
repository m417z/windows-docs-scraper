# IAppxPackageReader::GetPayloadFile

## Description

Retrieves a payload file from the package.

## Parameters

### `fileName` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the payload file to be retrieved.

### `file` [out, retval]

Type: **[IAppxFile](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxfile)****

The file object that corresponds to *fileName*.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)** | There is no payload file with the specified file name. |

## Remarks

The specified *fileName* must include the path relative to the package root directory.

## See also

[IAppxFile](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxfile)

[IAppxPackageReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxpackagereader)

[IAppxPackageReader::GetFootprintFile](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxpackagereader-getfootprintfile)

[IAppxPackageReader::GetPayloadFiles](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxpackagereader-getpayloadfiles)