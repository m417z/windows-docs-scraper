# MBN_DATA_CLASS enumeration

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_DATA_CLASS** enumerated type specifies the data classes that a provider supports.

## Constants

### `MBN_DATA_CLASS_NONE:0`

No data class.

### `MBN_DATA_CLASS_GPRS:0x1`

The GPRS data class implemented by GSM providers.

### `MBN_DATA_CLASS_EDGE:0x2`

 The EDGE data class implemented by GSM providers.

### `MBN_DATA_CLASS_UMTS:0x4`

The UMTS data class implemented by mobile radio providers.

### `MBN_DATA_CLASS_HSDPA:0x8`

The HSDPA data class implemented by mobile radio providers.

### `MBN_DATA_CLASS_HSUPA:0x10`

The HSUPA (High Speed Uplink Packet Access) data class.

### `MBN_DATA_CLASS_LTE:0x20`

The LTE data class implemented by mobile radio providers.

### `MBN_DATA_CLASS_1XRTT:0x10000`

The 1xRTT data class implemented by CDMA providers.

### `MBN_DATA_CLASS_1XEVDO:0x20000`

The IxEV-DO data class implemented by CDMA providers.

### `MBN_DATA_CLASS_1XEVDO_REVA:0x40000`

The IxEV-DO RevA data class implemented by CDMA providers.

### `MBN_DATA_CLASS_1XEVDV:0x80000`

The 1xXEV-DV data class.

### `MBN_DATA_CLASS_3XRTT:0x100000`

The 3xRTT data class.

### `MBN_DATA_CLASS_1XEVDO_REVB:0x200000`

 The 1xEV-DO RevB data class, which is defined for future use.

### `MBN_DATA_CLASS_UMB:0x400000`

 The UMB data class.

### `MBN_DATA_CLASS_CUSTOM:0x80000000`

 The custom data class.