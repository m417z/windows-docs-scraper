# IAppxBundleReader::GetPayloadPackage

## Description

Retrieves an appx file object for the payload package with the specified file name.

## Parameters

### `fileName` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the payload file to be retrieved.

### `payloadPackage` [out, retval]

Type: **[IAppxFile](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxfile)****

The payload file object the that corresponds to *fileName*.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)** | There is no payload file with the specified file name. |

## Remarks

You can pass the file object’s stream into [IAppxFactory::CreatePackageReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxfactory-createpackagereader) to get a package reader object over the appx file.

## See also

[IAppxBundleReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxbundlereader)