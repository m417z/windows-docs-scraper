# IFaxDevice::GetExtensionProperty

## Description

The **IFaxDevice::get_GetExtensionProperty** method retrieves an extension configuration property stored at the device level.

## Parameters

### `bstrGUID` [in]

Type: **BSTR**

Specifies a string GUID that uniquely identifies the data to be retrieved.

### `pvProperty`

Type: **VARIANT***

**VARIANT** that specifies the data.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** The returned data is a blob of bytes represented as a variant safe array of unsigned chars (VT_UI1 | VT_ARRAY). The data is relevant only to the specific extension that uses it. For more information see [About the Fax Extension Configuration API](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-about-the-fax-extension-configuration-api).

To use this method, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxDevice](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevice)

[IFaxDevice](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdevice)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-extension-configuration-properties)