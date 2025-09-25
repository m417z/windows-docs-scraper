# IMFMediaType::GetMajorType

## Description

Gets the major type of the format.

## Parameters

### `pguidMajorType` [out]

Receives the major type **GUID**. The major type describes the broad category of the format, such as audio or video. For a list of possible values, see [Major Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-type-guids).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_ATTRIBUTENOTFOUND** | The major type is not set. |

## Remarks

This method is equivalent to getting the [MF_MT_MAJOR_TYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-major-type-attribute) attribute from the media type.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype)