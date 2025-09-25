# IAppxFile::GetCompressionOption

## Description

Retrieves the compression option that is used to store the file in the package.

## Parameters

### `compressionOption` [out, retval]

Type: **[APPX_COMPRESSION_OPTION](https://learn.microsoft.com/windows/desktop/api/appxpackaging/ne-appxpackaging-appx_compression_option)***

A compression option that describes how the file is stored in the package.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[APPX_COMPRESSION_OPTION](https://learn.microsoft.com/windows/desktop/api/appxpackaging/ne-appxpackaging-appx_compression_option)

[IAppxFile](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxfile)