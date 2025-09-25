# IMFAttributes::GetStringLength

## Description

Retrieves the length of a string value associated with a key.

## Parameters

### `guidKey` [in]

GUID that identifies which value to retrieve. The attribute type must be **MF_ATTRIBUTE_STRING**.

### `pcchLength` [out]

If the key is found and the value is a string type, this parameter receives the number of characters in the string, not including the terminating **NULL** character. To get the string value, call [IMFAttributes::GetString](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-getstring).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_ATTRIBUTENOTFOUND** | The specified key was not found. |
| **MF_E_INVALIDTYPE** | The attribute value is not a string. |

## Remarks

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Attributes and Properties](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes)

[MF_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mf_attribute_type)