# IAppxFactory2::CreateContentGroupMapReader

## Description

Creates an [IAppxContentGroupMapReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxcontentgroupmapreader).

## Parameters

### `inputStream` [in]

The stream that delivers the content group map XML for reading.

### `contentGroupMapReader` [out, retval]

The content group map reader.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAppxFactory2](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxfactory2)