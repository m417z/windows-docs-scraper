# FAX_PROVIDER_STATUS_ENUM enumeration

## Description

The **FAX_PROVIDER_STATUS_ENUM** enumeration defines the status values for a fax extension (a fax service provider (FSP) or a fax inbound routing extension).

## Constants

### `fpsSUCCESS:0`

The extension loaded, linked, and initialized successfully.

### `fpsSERVER_ERROR`

A server-related error occurred while the fax service was trying to load, link, and initialize the extension; for example, there may have been insufficient memory resources. Call the [IFaxDeviceProvider::get_InitErrorCode](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdeviceprovider-initerrorcode-vb) method or the [IFaxInboundRoutingExtension::get_InitErrorCode](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxinboundroutingextension-initerrorcode-vb) method to return the last error code.

### `fpsBAD_GUID`

An error occurred while the fax service was parsing the extension's installation data; the extension's GUID is invalid. Refer to the **InitErrorCode** property to get the error code.

### `fpsBAD_VERSION`

An error occurred while the fax service was parsing the extension's installation data; the extension reports an invalid version of the FSP or routing extension API; the routing extension is the non-default MS routing extension for a desktop computer installation. Call the [IFaxDeviceProvider::get_InitErrorCode](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdeviceprovider-initerrorcode-vb) method or the [IFaxInboundRoutingExtension::get_InitErrorCode](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxinboundroutingextension-initerrorcode-vb) method to return the last error code.

### `fpsCANT_LOAD`

An error occurred while the fax service was loading the FSP or routing extension's DLL. Call the [IFaxDeviceProvider::get_InitErrorCode](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdeviceprovider-initerrorcode-vb) method or the [IFaxInboundRoutingExtension::get_InitErrorCode](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxinboundroutingextension-initerrorcode-vb) method to return the last error code.

### `fpsCANT_LINK`

An error occurred when the fax service attempted to dynamically link to one of the functions that the FSP or routing extension's DLL must export. Call the [IFaxDeviceProvider::get_InitErrorCode](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdeviceprovider-initerrorcode-vb) method or the [IFaxInboundRoutingExtension::get_InitErrorCode](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxinboundroutingextension-initerrorcode-vb) method to return the last error code.

### `fpsCANT_INIT`

An error occurred when the fax service called the extension's initialization function. For virtual devices, the **InitErrorCode** property is an **HRESULT** value; otherwise, it is a Win32 error code. Call the [IFaxDeviceProvider::get_InitErrorCode](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdeviceprovider-initerrorcode-vb) method or the [IFaxInboundRoutingExtension::get_InitErrorCode](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxinboundroutingextension-initerrorcode-vb) method to return the last error code.

## See also

[IFaxDeviceProvider::get_Status](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nf-faxcomex-ifaxdeviceprovider-get_status)

[IFaxInboundRoutingExtension::get_Status](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxinboundroutingextension-status-vb)