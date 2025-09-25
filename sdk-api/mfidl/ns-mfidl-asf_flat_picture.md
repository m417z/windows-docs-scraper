# ASF_FLAT_PICTURE structure

## Description

Contains an image that is stored as metadata for a media source. This structure is used as the data item for the [WM/Picture](https://learn.microsoft.com/windows/desktop/wmformat/wmpicture) metadata attribute.

## Members

### `bPictureType`

Specifies the type of image. This member is equivalent to the **bPictureType** member in the [WM_PICTURE](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wm_picture) structure.

### `dwDataLen`

Size, in bytes, of the image data.

## Remarks

The [WM/Picture](https://learn.microsoft.com/windows/desktop/wmformat/wmpicture) attribute is defined in the Windows Media Format SDK. The attribute contains a picture related to the content, such as album art.

To get this attribute from a media source, call [IMFMetadata::GetProperty](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmetadata-getproperty), passing in the constant g_wszWMPicture for the *pwszName* parameter. The method retrieves a **PROPVARIANT** that contains a binary array (VT_BLOB). The layout of the array is as follows:

* **ASF_FLAT_PICTURE** structure.
* Null-terminated wide-character string that contains the MIME type.
* Null-terminated wide-character string that contains a description.
* Image data.

This format differs from the [WM_PICTURE](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wm_picture) structure used in the Windows Media Format SDK. The **WM_PICTURE** structure contains internal pointers to two strings and the image data. If the structure is copied, these pointers become invalid. The **ASF_FLAT_PICTURE** structure does not contain internal pointers, so it is safe to copy the structure.

## See also

[IMFMetadata](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmetadata)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)