# MFInitAMMediaTypeFromMFMediaType function

## Description

Initializes a DirectShow **AM_MEDIA_TYPE** structure from a Media Foundation media type.

## Parameters

### `pMFType`

Pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of the media type to convert.

### `guidFormatBlockType`

Format type GUID. This value corresponds to the **formattype** member of the **AM_MEDIA_TYPE** structure and specifies the type of format block to allocate. If the value is GUID_NULL, the function attempts to deduce the correct format block, based on the major type and subtype.

### `pAMType`

Pointer to an **AM_MEDIA_TYPE** structure. The function allocates memory for the format block. The caller must release the format block by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) on the **pbFormat** member.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |
| **MF_E_INVALIDMEDIATYPE** | The media type is not valid. |

## Remarks

This function can also be used with the following format structures that are equivalent to **AM_MEDIA_TYPE**:

* **DMO_MEDIA_TYPE** (DirectX Media Objects)
* **WM_MEDIA_TYPE** (Windows Media Format SDK)

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)