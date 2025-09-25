# IThumbnailCapture::CaptureThumbnail

## Description

Retrieves a thumbnail representation of an [IHTMLDocument2](https://learn.microsoft.com/dotnet/api/mshtml.ihtmldocument2?view=powershellsdk-1.1.0&preserve-view=true) document.

**Note** This method is deprecated as of Windows 7. The feature it supported is no longer present in Windows.

## Parameters

### `pMaxSize` [in]

Type: **const [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)***

A pointer to a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure that specifies the maximum size of the bitmap, in pixels.

### `pHTMLDoc2` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to an [IHTMLDocument2](https://learn.microsoft.com/dotnet/api/mshtml.ihtmldocument2?view=powershellsdk-1.1.0&preserve-view=true) interface's [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface.

### `phbmThumbnail` [out]

Type: **HBITMAP***

A handle to a bitmap that represents the document object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IHTMLDocument2](https://learn.microsoft.com/dotnet/api/mshtml.ihtmldocument2?view=powershellsdk-1.1.0&preserve-view=true)

[IThumbnailCapture](https://learn.microsoft.com/windows/desktop/api/shlobj/nn-shlobj-ithumbnailcapture)