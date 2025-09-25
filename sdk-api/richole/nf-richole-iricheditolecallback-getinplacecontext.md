# IRichEditOleCallback::GetInPlaceContext

## Description

Provides the application and document-level interfaces and information required to support in-place activation.

## Parameters

### `lplpFrame`

Type: **LPOLEINPLACEFRAME***

The address of the [IOleInPlaceFrame](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceframe) interface that represents the frame window of a rich edit control client. Use the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method to increment the reference count. The rich edit control releases the interface when it is no longer needed.

### `lplpDoc`

Type: **LPOLEINPLACEUIWINDOW***

The address of the [IOleInPlaceUIWindow](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceuiwindow) interface that represents the document window of the rich edit control client. An interface need not be returned if the frame and document windows are the same. Use the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method to increment the reference count. The rich edit control releases the interface when it is no longer needed.

### `lpFrameInfo`

Type: **LPOLEINPLACEFRAMEINFO**

The accelerator information.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **S_OK** on success. If the method fails, it can return the following value.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | There was an invalid argument. |

## See also

[IRichEditOleCallback](https://learn.microsoft.com/windows/desktop/api/richole/nn-richole-iricheditolecallback)