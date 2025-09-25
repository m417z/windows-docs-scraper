# IMFAttributes::GetAllocatedString

## Description

Gets a wide-character string associated with a key. This method allocates the memory for the string.

## Parameters

### `guidKey` [in]

A GUID that identifies which value to retrieve. The attribute type must be **MF_ATTRIBUTE_STRING**.

### `ppwszValue` [out]

If the key is found and the value is a string type, this parameter receives a copy of the string. The caller must free the memory for the string by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `pcchLength` [out]

Receives the number of characters in the string, excluding the terminating **NULL** character. This parameter must not be **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_ATTRIBUTENOTFOUND** | The specified key was not found. |
| **MF_E_INVALIDTYPE** | The attribute value is not a string. |

## Remarks

To copy a string value into a caller-allocated buffer, use the [IMFAttributes::GetString](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-getstring) method.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

**Note** An earlier version of the documentation incorrectly stated that the *pcchLength* parameter can be **NULL**. Setting this parameter to **NULL** might succeed in some cases, but is not guaranteed. The caller must pass a non-**NULL** pointer for this parameter.

## See also

[Attributes and Properties](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes)

[MF_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mf_attribute_type)