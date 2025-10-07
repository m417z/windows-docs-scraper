# DOT11\_SSID structure

A **DOT11\_SSID** structure contains the SSID of an interface.

## Members

**uSSIDLength**

The length, in bytes, of the **ucSSID** array.

**ucSSID**

The SSID. DOT11\_SSID\_MAX\_LENGTH is set to 32.

## Remarks

The SSID that is specified by the **ucSSID** member is not a null-terminated ASCII string. The length of the SSID is determined by the **uSSIDLength** member.

A wildcard SSID is an SSID whose **uSSIDLength** member is set to zero. When the desired SSID is set to the wildcard SSID, the 802.11 station can connect to any basic service set (BSS) network.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista, Windows XP with SP3 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Redistributable<br> | Wireless LAN API for Windows XP with SP2<br> |
| Header<br> | Wlantypes.h (include Windot11.h) |

## See also

[**WLAN\_CONNECTION\_PARAMETERS**](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_connection_parameters)

[**WlanGetNetworkBssList**](https://learn.microsoft.com/windows/desktop/api/Wlanapi/nf-wlanapi-wlangetnetworkbsslist)

[**WlanScan**](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanscan)

