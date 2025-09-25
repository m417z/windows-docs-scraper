# ITfDisplayAttributeProvider::GetDisplayAttributeInfo

## Description

Obtains a display attribute provider object for a particular display attribute.

## Parameters

### `guid` [in]

Contains a GUID value that identifies the display attribute to obtain the display attribute information object for. The text service must publish these values and what they indicate. This identifier can also be obtained by enumerating the display attributes for a range of text.

### `ppInfo` [out]

Pointer to an [ITfDisplayAttributeInfo](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfdisplayattributeinfo) interface pointer that receives the display attribute information object.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## See also

[ITfCategoryMgr::RegisterCategory](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcategorymgr-registercategory)

[ITfDisplayAttributeInfo](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfdisplayattributeinfo)

[ITfDisplayAttributeProvider](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfdisplayattributeprovider)

[Providing Display Attributes](https://learn.microsoft.com/windows/desktop/TSF/providing-display-attributes)