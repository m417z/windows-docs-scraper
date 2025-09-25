# OleLoadPictureEx function

## Description

Creates a new picture object and initializes it from the contents of a stream. This is equivalent to calling [OleCreatePictureIndirect](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-olecreatepictureindirect) with **NULL** as the first parameter, followed by a call to [IPersistStream::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststream-load).

## Parameters

### `lpstream` [in]

Pointer to the stream that contains the picture's data.

### `lSize` [in]

The number of bytes that should be read from the stream, or zero if the entire stream should be read.

### `fRunmode` [in]

The opposite of the initial value of the [KeepOriginalFormat](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipicture-get_keeporiginalformat) property. If **TRUE**, [KeepOriginalFormat](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipicture-put_keeporiginalformat) is set to **FALSE** and vice versa.

### `riid` [in]

Reference to the identifier of the interface describing the type of interface pointer to return in *ppvObj*.

### `xSizeDesired` [in]

Desired width of icon or cursor. Valid values are 16, 32, and 48. Pass LP_DEFAULT to both size parameters to use system default size.

### `ySizeDesired` [in]

Desired height of icon or cursor. Valid values are 16, 32, and 48. Pass LP_DEFAULT to both size parameters to use system default size.

### `dwFlags` [in]

Desired color depth for icon or cursor. Values are LP_MONOCHROME (monochrome), LP_VGACOLOR (16 colors), LP_COLOR (256 colors), or LP_DEFAULT (selects best depth for current display).

### `lplpvObj` [out]

Address of pointer variable that receives the interface pointer requested in riid. Upon successful return, **ppvObj* contains the requested interface pointer on the storage of the object identified by the moniker. If **ppvObj* is non-**NULL**, this function calls [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the interface; it is the caller's responsibility to call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). If an error occurs, **ppvObj* is set to **NULL**.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **E_NOINTERFACE** | The object does not support the interface specified in riid. |
| **E_POINTER** | The address in *pPictDesc* or *ppvObj* is not valid. For example, it may be **NULL**. |

## Remarks

The stream must be in BMP (bitmap), WMF (metafile), or ICO (icon) format. A picture object created using **OleLoadPictureEx** always has ownership of its internal resources (*fOwn*==**TRUE** is implied).

In addition to allowing specification of icon or cursor size, **OleLoadPictureEx** supports loading of color cursors.

## See also

[OleCreatePictureIndirect](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-olecreatepictureindirect)

[PICTDESC](https://learn.microsoft.com/windows/desktop/api/olectl/ns-olectl-pictdesc)