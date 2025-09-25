# IAppxFactory2::CreateContentGroupMapWriter

## Description

Creates an [IAppxContentGroupMapWriter](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxcontentgroupmapwriter).

## Parameters

### `stream`

The stream that receives the content group map.

### `contentGroupMapWriter` [out, retval]

Provides a write-only object model for a content group map.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAppxFactory2](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxfactory2)