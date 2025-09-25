# MFCreateMediaTypeFromRepresentation function

## Description

Creates a Media Foundation media type from another format representation.

## Parameters

### `guidRepresentation` [in]

GUID that specifies which format representation to convert. The following value is defined.

| GUID | Description |
| --- | --- |
| AM_MEDIA_TYPE_REPRESENTATION | Convert a DirectShow **AM_MEDIA_TYPE** structure. |

### `pvRepresentation` [in]

Pointer to a buffer that contains the format representation to convert. The layout of the buffer depends on the value of *guidRepresentation*.

### `ppIMediaType` [out]

Receives a pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |
| **MF_E_UNSUPPORTED_REPRESENTATION** | The GUID specified in *guidRepresentation* is not supported. |

## Remarks

If the original format is a DirectShow audio media type, and the format type is not recognized, the function sets the following attributes on the converted media type.

| Attribute | Description |
| --- | --- |
| [MF_MT_AM_FORMAT_TYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-am-format-type-attribute) | Contains the format type GUID. |
| [MF_MT_USER_DATA](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-user-data-attribute) | Contains the format block. |

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)