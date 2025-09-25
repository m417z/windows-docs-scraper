# IMFMediaType::IsEqual

## Description

Compares two media types and determines whether they are identical. If they are not identical, the method indicates how the two formats differ.

## Parameters

### `pIMediaType` [in]

Pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of the media type to compare.

### `pdwFlags` [out]

Receives a bitwise **OR** of zero or more flags, indicating the degree of similarity between the two media types. The following flags are defined.

| Value | Meaning |
| --- | --- |
| **MF_MEDIATYPE_EQUAL_MAJOR_TYPES**<br><br>0x00000001 | The major types are the same. The major type is specified by the [MF_MT_MAJOR_TYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-major-type-attribute) attribute. |
| **MF_MEDIATYPE_EQUAL_FORMAT_TYPES**<br><br>0x00000002 | The subtypes are the same, or neither media type has a subtype. The subtype is specified by the [MF_MT_SUBTYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-subtype-attribute) attribute. |
| **MF_MEDIATYPE_EQUAL_FORMAT_DATA**<br><br>0x00000004 | The attributes in one of the media types are a subset of the attributes in the other, and the values of these attributes match, excluding the value of the [MF_MT_USER_DATA](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-user-data-attribute), [MF_MT_FRAME_RATE_RANGE_MIN](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-frame-rate-range-min), and [MF_MT_FRAME_RATE_RANGE_MAX](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-frame-rate-range-max) attributes.<br><br>Specifically, the method takes the media type with the smaller number of attributes and checks whether each attribute from that type is present in the other media type and has the same value (not including [MF_MT_USER_DATA](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-user-data-attribute), [MF_MT_FRAME_RATE_RANGE_MIN](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-frame-rate-range-min), and [MF_MT_FRAME_RATE_RANGE_MAX](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-frame-rate-range-max)). <br><br>To perform other comparisons, use the [IMFAttributes::Compare](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-compare) method. For example, the **Compare** method can test for identical attributes, or test the intersection of the two attribute sets. For more information, see [MF_ATTRIBUTES_MATCH_TYPE](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mf_attributes_match_type). |
| **MF_MEDIATYPE_EQUAL_FORMAT_USER_DATA**<br><br>0x00000008 | The user data is identical, or neither media type contains user data. User data is specified by the [MF_MT_USER_DATA](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-user-data-attribute) attribute. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The types are not equal. Examine the *pdwFlags* parameter to determine how the types differ. |
| **S_OK** | The types are equal. |
| **E_INVALIDARG** | One or both media types are invalid. |

## Remarks

Both of the media types must have a major type, or the method returns **E_INVALIDARG**.

If the method succeeds and all of the comparison flags are set in *pdwFlags*, the return value is **S_OK**. If the method succeeds but one or more comparison flags are not set, the method returns **S_FALSE**.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFAttributes::Compare](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-compare)

[IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype)