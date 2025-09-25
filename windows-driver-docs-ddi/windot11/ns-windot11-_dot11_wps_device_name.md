# _DOT11_WPS_DEVICE_NAME structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The **DOT11_WPS_DEVICE_NAME** structure contains a friendly name of the P2P device.

## Members

### `uDeviceNameLength`

The length, in bytes, of the device name.

### `ucDeviceName`

A UTF-8–encoded descriptive name of the device.

## Syntax

```cpp
typedef struct _DOT11_WPS_DEVICE_NAME {
   ULONG
uDeviceNameLength;
  UCHAR   ucDeviceName[DOT11_WPS_DEVICE_NAME_MAX_LENGTH];
} DOT11_WPS_DEVICE_NAME, *PDOT11_WPS_DEVICE_NAME;
```