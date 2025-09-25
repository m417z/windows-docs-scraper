# IFaxServer::RegisterInboundRoutingExtension

## Description

The **IFaxServer::RegisterInboundRoutingExtension** method registers a fax inbound routing extension with the fax service. Registration takes place after the fax service restarts.

## Parameters

### `bstrExtensionName`

Type: **BSTR**

String that specifies the internal name of the fax routing extension DLL.

### `bstrFriendlyName`

Type: **BSTR**

String to associate with the fax routing extension DLL. This is the routing extension's user-friendly name, suitable for display.

### `bstrImageName`

Type: **BSTR**

String that specifies the full path and file name for the fax routing extension DLL. The path can include valid environment variables, for example, %SYSTEMDRIVE% and %SYSTEMROOT%.

### `vMethods`

Type: **VARIANT**

[VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) that specifies a safearray of **BSTR**s. The array must be unidimensional, it cannot be empty, and it must have a lower limit of zero. Each item (string) in the array must identify a routing method. The string must have the following format: Method name; Friendly name; Function Name; Method GUID

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Only an administrator can register a routing extension. Also, this method works only on the local fax server.

This property is not supported in Windows XP, and will return the error: [FAX_E_NOT_SUPPORTED_ON_THIS_SKU](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-error-codes).

To use this method, a user must have the [farMANAGE_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver)

[IFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver)