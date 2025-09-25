# _DOT11_WFD_DISCOVER_TYPE enumeration

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The **DOT11_WFD_DISCOVER_TYPE** enumeration indicates the mode of Wi-Fi Direct device discovery.

## Constants

### `dot11_wfd_discover_type_scan_only`

Device discovery occurs only during the scan phase. During the scan phase, Wi-Fi Direct devices should scan each social channel at least once every 250ms.

### `dot11_wfd_discover_type_find_only`

Device discovery occurs only during the find phase.

### `dot11_wfd_discover_type_auto`

Discovery mode is determined by the driver.

### `dot11_wfd_discover_type_scan_social_channels`

The WFD device must perform device discovery by scanning only P2P social channels. In this setting, the device should scan each social channel at least once every 250ms.

### `dot11_wfd_discover_type_forced`

A flag indicating that a complete device discovery is required. If this flag is not set, a partial discovery can be performed.

## Syntax

```cpp
typedef enum _DOT11_WFD_DISCOVER_TYPE {
  dot11_wfd_discover_type_scan_only             = 1,
  dot11_wfd_discover_type_find_only             = 2,
  dot11_wfd_discover_type_auto                  = 3,
  dot11_wfd_discover_type_scan_social_channels  = 4,
  dot11_wfd_discover_type_forced                = 0x80000000
} DOT11_WFD_DISCOVER_TYPE;
```

## Remarks

The **dot11_wfd_discover_type_forced** flag may be set along with only one of the other discovery modes.

## See also

[OID_DOT11_WFD_DISCOVER_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-discover-request)

[DOT11_WFD_DISCOVER_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_wfd_discover_request)