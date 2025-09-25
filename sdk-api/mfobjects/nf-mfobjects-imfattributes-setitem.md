# IMFAttributes::SetItem

## Description

Adds an attribute value with a specified key.

## Parameters

### `guidKey` [in]

A GUID that identifies the value to set. If this key already exists, the method overwrites the old value.

### `Value` [in]

A **PROPVARIANT** that contains the attribute value. The method copies the value. The **PROPVARIANT** type must be one of the types listed in the [MF_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mf_attribute_type) enumeration.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **MF_E_INVALIDTYPE** | Invalid attribute type. |

## Remarks

This method checks whether the **PROPVARIANT** type is one of the attribute types defined in [MF_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mf_attribute_type), and fails if an unsupported type is used. However, this method does not check whether the **PROPVARIANT** is the correct type for the specified attribute GUID. (There is no programmatic way to associate attribute GUIDs with property types.) For a list of Media Foundation attributes and their data types, see [Media Foundation Attributes](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-attributes).

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Attributes and Properties](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes)