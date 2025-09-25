# IMFAttributes::GetUINT64

## Description

Retrieves a **UINT64** value associated with a key.

## Parameters

### `guidKey` [in]

GUID that identifies which value to retrieve. The attribute type must be **MF_ATTRIBUTE_UINT64**.

### `punValue` [out]

Receives a **UINT64** value. If the key is found and the data type is **UINT64**, the method copies the value into this parameter. Otherwise, the original value of this parameter is not changed.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_ATTRIBUTENOTFOUND** | The specified key was not found. |
| **MF_E_INVALIDTYPE** | The attribute value is not a **UINT64**. |

## Remarks

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Attributes and Properties](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes)

[MFGetAttributeUINT64](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfgetattributeuint64)

[MF_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mf_attribute_type)