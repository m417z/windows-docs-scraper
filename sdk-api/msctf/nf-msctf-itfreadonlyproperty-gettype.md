# ITfReadOnlyProperty::GetType

## Description

Obtains the property identifier.

## Parameters

### `pguid` [out]

Pointer to a **GUID** value that receives the property type identifier. This is the value that the property provider passed to [ITfCategoryMgr::RegisterCategory](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcategorymgr-registercategory) when the property was registered. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **GUID_TFCAT_PROPSTYLE_STATIC** | The property is a static property. |
| **GUID_TFCAT_PROPSTYLE_STATICCOMPACT** | The property is a static-compact property. |
| **GUID_TFCAT_PROPSTYLE_CUSTOM** | The property is a custom property. |

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pguid* is invalid. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITfCategoryMgr::RegisterCategory](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcategorymgr-registercategory)

[ITfReadOnlyProperty](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfreadonlyproperty)

[Properties](https://learn.microsoft.com/windows/desktop/TSF/properties)