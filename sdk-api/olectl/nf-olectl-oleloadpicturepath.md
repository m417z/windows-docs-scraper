# OleLoadPicturePath function

## Description

Creates a new picture object and initializes it from the contents of a stream. This is equivalent to calling [OleCreatePictureIndirect(NULL, ...)](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-olecreatepictureindirect) followed by [IPersistStream::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststream-load).

## Parameters

### `szURLorPath` [in]

The path or URL to the file you want to open.

### `punkCaller` [in]

Points to [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) for COM aggregation.

### `dwReserved` [in]

Reserved.

### `clrReserved` [in]

The color you want to reserve to be transparent.

### `riid` [in]

Reference to the identifier of the interface describing the type of interface pointer to return in ppvRet.

### `ppvRet` [out]

Address of pointer variable that receives the interface pointer requested in riid. Upon successful return, **ppvRet* contains the requested interface pointer on the storage of the object identified by the moniker. If **ppvRet* is non-**NULL**, this function calls [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the interface; it is the caller's responsibility to call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). If an error occurs, **ppvRet* is set to **NULL**.

## Return value

This function supports the standard return values E_OUTOFMEMORY and E_UNEXPECTED, as well as the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The dialog box was created successfully. |
| **E_FAIL** | Unable to load picture stream. |
| **E_POINTER** | The address in *ppvRet* is **NULL**. |
| **E_NOINTERFACE** | The object does not support the interface specified in *riid*. |

## Remarks

The stream must be in BMP (bitmap), JPEG, WMF (metafile), ICO (icon), or GIF format.

## See also

[OleLoadPicture](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-oleloadpicture)