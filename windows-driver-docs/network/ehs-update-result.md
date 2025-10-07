# eHS\_UPDATE\_RESULT enumeration

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **eHS\_UPDATE\_RESULT** enumeration indicates the result of a “check for updates” request.

## Constants

**HS\_UPDATE\_RESULT\_SUCCESS**
Indicates the update was successful.

**HS\_UPDATE\_RESULT\_ACTION\_RECONNECT**
The result of the update request requires the service to disconnect and reconnect.

**HS\_UPDATE\_RESULT\_ACTION\_RELOAD**
The result of the update request requires the service to unload and reload the plugin.

**HS\_UPDATE\_RESULT\_MAX**
Indicates an out-of-range value.

## Remarks

The plugin passes this enumeration value to the hotspot plugin host through the [**HS\_HOST\_UPDATE\_CONFIGURATION\_COMPLETION**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-host-update-configuration-completion) function, which is used to inform the hotspot plugin host of the results of a call to [**HS\_PLUGIN\_CHECK\_FOR\_UPDATES**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-check-for-updates).

## Requirements

|  |  |
| --- | --- |
| Version | Windows 10 Mobile |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

## See also

[**HS\_HOST\_UPDATE\_CONFIGURATION\_COMPLETION**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-host-update-configuration-completion)

[**HS\_PLUGIN\_CHECK\_FOR\_UPDATES**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-check-for-updates)

