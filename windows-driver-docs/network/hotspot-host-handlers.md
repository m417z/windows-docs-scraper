# HOTSPOT\_HOST\_HANDLERS structure

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HOTSPOT\_HOST\_HANDLERS** structure contains the hotspot host handlers function table. This function table is passed to the plugin when [**HSPluginInitPlugin**](https://learn.microsoft.com/windows-hardware/drivers/network/hsplugininitplugin) is called to initialize it. The table contains functions that are called by the plugin to communicate with the hotspot host.

## Members

**HSHostAllocateMemory**
Optional memory management handler.

Handle to the function that is called by the plugin to allocate any memory needed by the plugin. For more information, see [**HS\_HOST\_ALLOCATE\_MEMORY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-host-allocate-memory).

**HSHostFreeMemory**
Optional memory management handler.

Handle to the function that is called by the plugin to free any memory that had been allocated earlier by the call to [**HS\_HOST\_ALLOCATE\_MEMORY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-host-allocate-memory). For more information, see [**HS\_HOST\_FREE\_MEMORY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-host-free-memory).

**HSHostPostConnectAuthCompletion**
Required connection-process handler.

Handle to the function that is called by the plugin to indicate the success or failure status resulting from the authentication attempt following a Wi-Fi connection setup at layer 2. For more information, see [**HS\_PLUGIN\_START\_POST\_CONNECT\_AUTH**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-start-post-connect-auth).

**HSHostSendKeepAliveCompletion**
Optional periodic request.

Handle to the function that is called by the plugin to indicate the success or failure status resulting from the Send Keep Alive request. For more information, see [**HS\_PLUGIN\_SEND\_KEEP\_ALIVE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-send-keep-alive).

**HSHostUpdateConfigurationCompletion**
Optional periodic request.

Handle to the function that is called by the plugin to indicate the success or failure of a call to check for updates. For more information, see [**HS\_PLUGIN\_CHECK\_FOR\_UPDATES**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-check-for-updates).

**HSHostSendUserMessage**
Optional periodic request.

Handle to the function that is called to communicate with the user. For more information see [**HS\_HOST\_SEND\_USER\_MESSAGE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-host-send-user-message).

## Requirements

|  |  |
| --- | --- |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

## See also

[**HSPluginInitPlugin**](https://learn.microsoft.com/windows-hardware/drivers/network/hsplugininitplugin)

[**HS\_HOST\_ALLOCATE\_MEMORY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-host-allocate-memory)

[**HS\_HOST\_FREE\_MEMORY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-host-free-memory)

[**HS\_PLUGIN\_START\_POST\_CONNECT\_AUTH**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-start-post-connect-auth)

[**HS\_PLUGIN\_SEND\_KEEP\_ALIVE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-send-keep-alive)

[**HS\_PLUGIN\_CHECK\_FOR\_UPDATES**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-check-for-updates)

[**HS\_HOST\_SEND\_USER\_MESSAGE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-host-send-user-message)

