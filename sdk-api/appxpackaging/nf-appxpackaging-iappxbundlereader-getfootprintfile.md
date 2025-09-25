# IAppxBundleReader::GetFootprintFile

## Description

Retrieves the specified type of footprint file from the bundle.

## Parameters

### `fileType` [in]

Type: **[APPX_BUNDLE_FOOTPRINT_FILE_TYPE](https://learn.microsoft.com/windows/desktop/api/appxpackaging/ne-appxpackaging-appx_bundle_footprint_file_type)**

The type of footprint file to be retrieved.

### `footprintFile` [out, retval]

Type: **[IAppxFile](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxfile)****

The file object that corresponds to the footprint file of *fileType*.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *fileType* parameter is not a valid value in the [APPX_BUNDLE_FOOTPRINT_FILE_TYPE](https://learn.microsoft.com/windows/desktop/api/appxpackaging/ne-appxpackaging-appx_bundle_footprint_file_type) enumeration. |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)** | The bundle doesn't contain a footprint file of the specified type.<br><br>[GetFootprintFile](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxbundlereader-getfootprintfile) can return this error for the [APPX_BUNDLE_FOOTPRINT_FILE_TYPE_SIGNATURE](https://learn.microsoft.com/windows/desktop/api/appxpackaging/ne-appxpackaging-appx_bundle_footprint_file_type) type. |

## See also

[IAppxBundleReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxbundlereader)