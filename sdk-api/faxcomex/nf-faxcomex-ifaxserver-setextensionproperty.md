# IFaxServer::SetExtensionProperty

## Description

The **IFaxServer::SetExtensionProperty** method stores an extension configuration property at the server level.

## Parameters

### `bstrGUID` [in]

Type: **BSTR**

Specifies a string GUID that identifies the data to set.

### `vProperty` [in]

Type: **VARIANT**

[VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) that specifies the data to be set.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The extension configuration property is a blob of bytes represented as a variant safe array of unsigned chars (VT_UI1 | VT_ARRAY). The data is only relevant to the specific extension that uses it. For more information see [About the Fax Extension Configuration API](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-about-the-fax-extension-configuration-api).

To use this method, a user must have the [farMANAGE_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver)

[IFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-extension-configuration-properties)