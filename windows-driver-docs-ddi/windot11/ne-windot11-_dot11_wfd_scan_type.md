# _DOT11_WFD_SCAN_TYPE enumeration

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The **DOT11_WFD_SCAN_TYPE** enumeration indicates the type of scan used during the scan phase of device discovery.

## Constants

### `dot11_wfd_scan_type_active`

Use active scanning for device discovery.

### `dot11_wfd_scan_type_passive`

Use passive scanning during device discovery.

### `dot11_wfd_scan_type_auto`

Driver selected scanning is used.

## Syntax

```cpp
typedef enum _DOT11_WFD_SCAN_TYPE {
  dot11_wfd_scan_type_active   = 1,
  dot11_wfd_scan_type_passive  = 2,
  dot11_wfd_scan_type_auto     = 3
} DOT11_WFD_SCAN_TYPE;
```

## Remarks

The system will set only one scan type at a time. The driver should use this setting to determine how it scans during device discovery.

## See also

[OID_DOT11_WFD_DISCOVER_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-discover-request)

[DOT11_WFD_DISCOVER_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_wfd_discover_request)