## Description

Retrieves the DNS settings from the interface specified in the *Interface* parameter. When you are done with the returned settings object, you must call [FreeInterfaceDnsSettings](https://learn.microsoft.com/windows/win32/api/netioapi/nf-netioapi-freeinterfacednssettings) to free it.

## Parameters

### `Interface`

Type: \_In\_ **[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)**

The **GUID** of the COM interface that the settings refer to.

### `Settings`

Type: \_Inout\_ const **[DNS_INTERFACE_SETTINGS](https://learn.microsoft.com/windows/win32/api/netioapi/ns-netioapi-dns_interface_settings)\***

**GetInterfaceDnsSettings** populates all the settings in this structure.

You should set only the *Version* member; the *Flags* field must be empty.

If you set the *Version* member to **DNS_INTERFACE_SETTINGS_VERSION1**, then the *Settings* parameter must point to a valid [**DNS_INTERFACE_SETTINGS**](https://learn.microsoft.com/windows/win32/api/netioapi/ns-netioapi-dns_interface_settings) structure.

If you set the *Version* member to **DNS_INTERFACE_SETTINGS_VERSION2**, then the *Settings* parameter must point to a valid [**DNS_INTERFACE_SETTINGS_EX**](https://learn.microsoft.com/windows/win32/api/netioapi/ns-netioapi-dns_interface_settings_ex) structure.

If you set the *Version* member to **DNS_INTERFACE_SETTINGS_VERSION3**, then the *Settings* parameter must point to a valid [**DNS_INTERFACE_SETTINGS3**](https://learn.microsoft.com/windows/win32/api/netioapi/ns-netioapi-dns_interface_settings3) structure.

## Return value

Returns **NO_ERROR** if successful. A non-zero return value indicates failure.

## Remarks

## See also

* [SetInterfaceDnsSettings](https://learn.microsoft.com/windows/win32/api/netioapi/nf-netioapi-setinterfacednssettings)
* [FreeInterfaceDnsSettings](https://learn.microsoft.com/windows/win32/api/netioapi/nf-netioapi-freeinterfacednssettings)