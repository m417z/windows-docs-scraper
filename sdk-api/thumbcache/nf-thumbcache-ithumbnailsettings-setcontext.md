# IThumbnailSettings::SetContext

## Description

Enables a thumbnail provider to return a thumbnail specific to the user's context.

Initially, a thumbnail provider receives a request for a thumbnail image through a call to the [IThumbnailCache::GetThumbnail](https://learn.microsoft.com/windows/desktop/api/thumbcache/nf-thumbcache-ithumbnailcache-getthumbnail) method. In response, before the provider calls [IExtractImage::Extract](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iextractimage-extract) or [IThumbnailProvider::GetThumbnail](https://learn.microsoft.com/windows/desktop/api/thumbcache/nf-thumbcache-ithumbnailprovider-getthumbnail), the thumbnail cache can call **IThumbnailSettings::SetContext** to ensure that the thumbnail that is returned is appropriate to the user's context. For example, the provider could detect the new **WTS_APPSTYLE** flag and return a thumbnail that conforms to the Windows 8 UI guidelines.

## Parameters

### `dwContext` [in]

Type: **[WTS_CONTEXTFLAGS](https://learn.microsoft.com/windows/desktop/api/thumbcache/ne-thumbcache-wts_contextflags)**

One or more flags that specify the context. This value is based on the [WTS_FLAGS](https://learn.microsoft.com/windows/desktop/api/thumbcache/ne-thumbcache-wts_flags) values that are received by the thumbnail provider through the call to [IThumbnailProvider::GetThumbnail](https://learn.microsoft.com/windows/desktop/api/thumbcache/nf-thumbcache-ithumbnailprovider-getthumbnail).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IThumbnailSettings](https://learn.microsoft.com/windows/desktop/api/thumbcache/nn-thumbcache-ithumbnailsettings)