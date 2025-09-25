## Description

Sets the per-interface DNS settings specified in the *Settings* parameter.

## Parameters

### `Interface`

Type: \_In\_ **[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)**

The **GUID** of the COM interface that the settings refer to.

### `Settings`

Type: \_In\_ const **[DNS_INTERFACE_SETTINGS](https://learn.microsoft.com/windows/win32/api/netioapi/ns-netioapi-dns_interface_settings)\***

A pointer to a **DNS_INTERFACE_SETTINGS**-type structure that contains the DNS interface settings.

If this parameter points to a [**DNS_INTERFACE_SETTINGS**](https://learn.microsoft.com/windows/win32/api/netioapi/ns-netioapi-dns_interface_settings) structure, then the **DNS_INTERFACE_SETTINGS::Version** member must be set to **DNS_INTERFACE_SETTINGS_VERSION1**.

If this parameter points to a [**DNS_INTERFACE_SETTINGS_EX**](https://learn.microsoft.com/windows/win32/api/netioapi/ns-netioapi-dns_interface_settings_ex) structure, then the version must be set to **DNS_INTERFACE_SETTINGS_VERSION2**.

If this parameter points to a [**DNS_INTERFACE_SETTINGS3** ](https://learn.microsoft.com/windows/win32/api/netioapi/ns-netioapi-dns_interface_settings3) structure, then the version must to be set to **DNS_INTERFACE_SETTINGS_VERSION3**.

You must set appropriately all the desired options in the **DNS_INTERFACE_SETTINGS::Flags** field, and populate only the fields for which an option was set. You must zero out all other fields that don't have a corresponding option.

## Return value

Returns **NO_ERROR** if successful. A non-zero return value indicates failure.

## Remarks

## See also

* [GetInterfaceDnsSettings](https://learn.microsoft.com/windows/win32/api/netioapi/nf-netioapi-getinterfacednssettings)