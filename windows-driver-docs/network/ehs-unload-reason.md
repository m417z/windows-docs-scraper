# eHS\_UNLOAD\_REASON enumeration

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **eHS\_UNLOAD\_REASON** enumeration indicates the reason for the plugin to get unloaded.

## Constants

**HS\_UNLOAD\_REASON\_NONE**
No specific reason for the unload operation.

**HS\_UNLOAD\_REASON\_PLUGN\_INIT\_FAILED**
The plugin is being unloaded because it failed to initialize successfully.

**HS\_UNLOAD\_REASON\_NO\_NETWORKS\_SUPPORTED**
The plugin is being unloaded because the plugin's [**HS\_PLUGIN\_PROFILE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-profile) structure did not indicate a valid value for **dwNumNetworksSupported**.

**HS\_UNLOAD\_REASON\_NO\_PROVIDE\_NAME\_ID**
The plugin is being unloaded because the plugin's [**HS\_PLUGIN\_PROFILE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-profile) structure did not specify a string ID for **dwProviderNameStringID**.

**HS\_UNLOAD\_REASON\_ZERO\_SIM\_COUNT**
The plugin is being unloaded because there are no SIM cards present.

**HS\_UNLOAD\_REASON\_DISPLAY\_FLAG\_BUT\_NO\_DISPLAY\_STRING\_ID**
The plugin is being unloaded because the plugin's [**HS\_PLUGIN\_PROFILE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-profile) structure requires HTTP or EAP SIM-based authentication but did not specify a value for **dwSupportedSIMCount.**

**HS\_UNLOAD\_REASON\_CUSTOM\_REALM\_FLAG\_BUT\_NO\_REALM\_STRING**
The plugin is being unloaded because the plugin's [**HS\_PLUGIN\_PROFILE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-profile) structure specified the **HS\_FLAG\_CAPABILITY\_NETWORK\_CUSTOM\_REALM** capability but did not provide a valid string for **szRealm**.

**HS\_UNLOAD\_REASON\_DUPLICATE\_PLUGIN\_LOADED**
The plugin is being unloaded because another plugin is using the same DLL.

**HS\_UNLOAD\_REASON\_RELOAD\_REQUESTED\_BY\_PLUGIN**
The plugin is being unloaded because the plugin requested to be unloaded and reloaded by specifying the **HS\_UPDATE\_RESULT\_ACTION\_RELOAD** action with the [**eHS\_UPDATE\_RESULT**](https://learn.microsoft.com/windows-hardware/drivers/network/ehs-update-result) enumeration.

**HS\_UNLOAD\_REASON\_EXCEPTION\_DURING\_PLUGIN\_CALL**
The plugin is being unloaded because the host process encountered an exception while in a call to the plugin.

**HS\_UNLOAD\_REASON\_EXCEPTION\_IN\_PLUGIN\_HOST**
The plugin is being unloaded because the hotspot host encountered an exception.

**HS\_UNLOAD\_REASON\_ASYNC\_INITIALIZATION\_FAILED**
The plugin is being unloaded because the hotspot service failed to register for notifications from the plugin.

**HS\_UNLOAD\_REASON\_UNSUPPORTED\_AUTH\_CAPABILITY\_REQUESTED**
The plugin is being unloaded because none of the authentication capabilities requested by the plugin are available.

**HS\_UNLOAD\_REASON\_FAILED\_TO\_LOAD\_PROVIDER\_NAME\_STRING**
The plugin is being unloaded because the hotspot service could not map the **dwProviderNameStringID** string ID provided in the plugin's [**HS\_PLUGIN\_PROFILE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-profile) structure to a valid string.

**HS\_UNLOAD\_REASON\_FAILED\_TO\_LOAD\_ADVANCED\_PAGE\_STRING**
The plugin is being unloaded because the plugin's [**HS\_PLUGIN\_PROFILE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-profile) structure specified an (optional) **dwAdvancedPageStringID** string ID but it did not map to a valid string.

**HS\_UNLOAD\_REASON\_FAILED\_TO\_LOAD\_NETWORK\_NAME\_STRING**
The plugin is being unloaded because the plugin's [**HS\_PLUGIN\_PROFILE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-profile) structure specified an (optional) **dwGenericNetworkNameStringID** string ID, but it did not map to a valid string.

**HS\_UNLOAD\_REASON\_FAILED\_TO\_CONFIGURE\_HIDDEN\_NETWORK**
The plugin is being unloaded because the plugin specified a hidden network (via the **HS\_FLAG\_CAPABILITY\_NETWORK\_TYPE\_HIDDEN** capability), but the hotspot service was unable to configure the hidden network.

**HS\_UNLOAD\_REASON\_HIDDEN\_NETWORK\_ALREADY\_CONFIGURED**
The plugin is being unloaded because the plugin specified a hidden network via the **HS\_FLAG\_CAPABILITY\_NETWORK\_TYPE\_HIDDEN** capability but another plugin has already claimed the hidden network slot.

**HS\_UNLOAD\_REASON\_FAILED\_TO\_QUERY\_SIMS**
The plugin is being unloaded because the call to [**HS\_PLUGIN\_QUERY\_SUPPORTED\_SIMS**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-query-supported-sims) failed.

**HS\_UNLOAD\_REASON\_PLUGIN\_REQUIRED\_SIM\_NOT\_PRESENT**
The plugin is being unloaded because the SIMs required by the plugin are not present in the device.

**HS\_UNLOAD\_REASON\_SIM\_CONFIG\_CHANGED**
The plugin is being unloaded because the SIM configuration changed, which requires the plugins to be unloaded and reloaded.

**HS\_UNLOAD\_REASON\_WIFI\_SWITCHED\_OFF\_IN\_OS**
The plugin is being unloaded because Wi-Fi functionality was switched off in the OS.

**HS\_UNLOAD\_REASON\_MAX**
Indicates an out-of-range value.

## Requirements

|  |  |
| --- | --- |
| Version | Windows 10 Mobile |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

## See also

[**HS\_PLUGIN\_PROFILE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-profile)

[**eHS\_UPDATE\_RESULT**](https://learn.microsoft.com/windows-hardware/drivers/network/ehs-update-result)

[**HS\_PLUGIN\_QUERY\_SUPPORTED\_SIMS**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-query-supported-sims)

