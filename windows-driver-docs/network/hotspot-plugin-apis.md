# HOTSPOT\_PLUGIN\_APIS structure

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HOTSPOT\_PLUGIN\_APIS** structure contains the Hotspot plugin APIs function table. This function table is returned by the plugin when [**HSPluginInitPlugin**](https://learn.microsoft.com/windows-hardware/drivers/network/hsplugininitplugin) is called to initialize the plugin. The table contains functions that are called by the hotspot host to communicate with the plugin.

## Members

**HSPluginQuerySupportedSIMs**
API called during plugin initialization.

Called by the hotspot host to retrieve the list of SIMs that the plugin supports. It can be called to retrieve the complete list of supported SIMs, or just the SIMs for a specific network. For more information, see [**HS\_PLUGIN\_QUERY\_SUPPORTED\_SIMS**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-query-supported-sims).

**HSPluginQueryCellularExceptionHosts**
API called during plugin initialization.

Called by the hotspot host if the plugin has specified the **HS\_FLAG\_CAPABILITY\_NETWORK\_TYPE\_HIDDEN** capability by way of the [**HS\_PLUGIN\_PROFILE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-profile) structure. For more information, see [**HS\_PLUGIN\_QUERY\_HIDDEN\_NETWORK**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-query-hidden-network).

**HSPluginIsHotspotNetwork**
API called while processing scan results.

Called by the hotspot host to request the plugin to identify if the network passed in the *pHiddenNetworkIdentity* parameter is a hotspot network. For more information, see [**HS\_PLUGIN\_IS\_HOTSPOT\_NETWORK**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-is-hotspot-network).

**HSPluginPreConnectInit**
Connection-process API.

Called by the hotspot host to notify the plugin to initialize its state when a connection is in progress. For more information, see [**HS\_PLUGIN\_PRE\_CONNECT\_INIT**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-pre-connect-init).

**HSPluginStartPostConnectAuth**
Connection-process API.

Called by the hotspot host to request the plugin to perform any post-connect authentication required to authenticate the device over the network. For more information, see [**HS\_PLUGIN\_START\_POST\_CONNECT\_AUTH**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-start-post-connect-auth).

**HSPluginStopPostConnectAuth**
Connection-process API.

Called by the hotspot host to notify the plugin to stop the authentication process. For more information, see [**HS\_PLUGIN\_STOP\_POST\_CONNECT\_AUTH**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-stop-post-connect-auth).

**HSPluginDisconnectFromNetwork**
Connection-process API.

Called by the hotspot host to notify the plugin of disconnection from network. For more information, see [**HS\_PLUGIN\_DISCONNECT\_FROM\_NETWORK**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-disconnect-from-network).

**HSPluginReset**
API to reset the plugin. If the plugin does not release any pending calls before returning from this call, the plugin will be unloaded.

Called by the hotspot host to reset the plugin. For more information, see [**HS\_PLUGIN\_RESET**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-reset).

**HSPluginSendKeepAlive**
API for plugin to do periodic updates.

Called by the hotspot host to send a keep-alive message to the plugin. For more information, see [**HS\_PLUGIN\_SEND\_KEEP\_ALIVE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-send-keep-alive).

**HSPluginCheckForUpdates**
API for plugin to do periodic updates.

Called by the hotspot host to check for updates. For more information, see [**HS\_PLUGIN\_CHECK\_FOR\_UPDATES**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-check-for-updates).

**HSPluginDeinit**
API called to de-initialize and clean up the plugin before unloading.

Called by the hotspot host to notify the plugin that it is about to be unloaded. For more information, see [**HS\_PLUGIN\_DEINIT**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-deinit).

## Requirements

|  |  |
| --- | --- |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

## See also

[**HSPluginInitPlugin**](https://learn.microsoft.com/windows-hardware/drivers/network/hsplugininitplugin)

[**HS\_PLUGIN\_QUERY\_SUPPORTED\_SIMS**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-query-supported-sims)

[**HS\_PLUGIN\_PROFILE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-profile)

[**HS\_PLUGIN\_QUERY\_HIDDEN\_NETWORK**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-query-hidden-network)

[**HS\_PLUGIN\_IS\_HOTSPOT\_NETWORK**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-is-hotspot-network)

[**HS\_PLUGIN\_PRE\_CONNECT\_INIT**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-pre-connect-init)

[**HS\_PLUGIN\_START\_POST\_CONNECT\_AUTH**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-start-post-connect-auth)

[**HS\_PLUGIN\_STOP\_POST\_CONNECT\_AUTH**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-stop-post-connect-auth)

[**HS\_PLUGIN\_DISCONNECT\_FROM\_NETWORK**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-disconnect-from-network)

[**HS\_PLUGIN\_RESET**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-reset)

[**HS\_PLUGIN\_SEND\_KEEP\_ALIVE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-send-keep-alive)

[**HS\_PLUGIN\_CHECK\_FOR\_UPDATES**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-check-for-updates)

[**HS\_PLUGIN\_DEINIT**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-deinit)

