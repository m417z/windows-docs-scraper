# IAppxPackageReader::GetFootprintFile

## Description

Retrieves a footprint file from the package.

## Parameters

### `type` [in]

Type: **[APPX_FOOTPRINT_FILE_TYPE](https://learn.microsoft.com/windows/desktop/api/appxpackaging/ne-appxpackaging-appx_footprint_file_type)**

The type of footprint file to be retrieved.

### `file` [out, retval]

Type: **[IAppxFile](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxfile)****

The file object that corresponds to the footprint file of *type*.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *type* parameter is not a member of the [APPX_FOOTPRINT_FILE_TYPE](https://learn.microsoft.com/windows/desktop/api/appxpackaging/ne-appxpackaging-appx_footprint_file_type) enumeration. |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)** | The package does not contain a footprint file of the specified type.<br><br>[GetFootprintFile](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxpackagereader-getfootprintfile) can return this error for [APPX_FOOTPRINT_FILE_TYPE_SIGNATURE](https://learn.microsoft.com/windows/desktop/api/appxpackaging/ne-appxpackaging-appx_footprint_file_type) and [APPX_FOOTPRINT_FILE_TYPE_CODEINTEGRITY](https://learn.microsoft.com/windows/desktop/api/appxpackaging/ne-appxpackaging-appx_footprint_file_type) types. |

## See also

[IAppxFile](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxfile)

[IAppxPackageReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxpackagereader)

[IAppxPackageReader::GetPayloadFile](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxpackagereader-getpayloadfile)

[IAppxPackageReader::GetPayloadFiles](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxpackagereader-getpayloadfiles)