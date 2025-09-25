# IShellImageData::Decode

## Description

Decodes the image file, setting state.

## Parameters

### `dwFlags` [in]

Type: **DWORD**

One of the following flags.

#### SHIMGDEC_DEFAULT (0x00)

Create a full image.

#### SHIMGDEC_THUMBNAIL (0x01)

Decode only the thumbnail image.

#### SHIMGDEC_LOADFULL (0x02)

Load the entire image file into memory.

### `cxDesired` [in]

Type: **ULONG**

The desired horizontal size of the decoded image. This parameter is only used if the **SHIMGDEC_THUMBNAIL** flag is set. If the **SHIMGDEC_DEFAULT** flag is set instead, this value is ignored.

### `cyDesired` [in]

Type: **ULONG**

The desired vertical size of the decoded image. This parameter is only used if the **SHIMGDEC_THUMBNAIL** flag is set. If the **SHIMGDEC_DEFAULT** flag is set instead, this value is ignored.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_FAIL** | The file could not be loaded or the calling application stopped the decode process through a call to a registered [IShellImageDataAbort](https://learn.microsoft.com/windows/desktop/api/shimgdata/nn-shimgdata-ishellimagedataabort) (see [IShellImageData::RegisterAbort](https://learn.microsoft.com/windows/desktop/api/shimgdata/nf-shimgdata-ishellimagedata-registerabort) for more information). |
| **E_OUTOFMEMORY** | The internal object cannot be instantiated. |
| **E_NOTIMPL** | The path used to create this instance of [IShellImageData](https://learn.microsoft.com/windows/desktop/api/shimgdata/nn-shimgdata-ishellimagedata) was a URL. |
| **S_FALSE** | The image has already been decoded. |

## Remarks

**IShellImageData::Decode** must be called prior to calling most [IShellImageData](https://learn.microsoft.com/windows/desktop/api/shimgdata/nn-shimgdata-ishellimagedata) methods. Not doing so causes those methods to fail.

**IShellImageData::Decode** attempts to maintain the aspect ratio of the original image, so one of the values passed in *cxDesired* or *cyDesired* might be overridden to do so.