# _DOT11_SUPPORTED_ANTENNA structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_SUPPORTED_ANTENNA structure defines an antenna entry in a
[DOT11_SUPPORTED_ANTENNA_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_supported_antenna_list) structure.

## Members

### `uAntennaListIndex`

A value, from 1 through 255, that uniquely identifies the antenna.

### `bSupportedAntenna`

A Boolean value that indicates, if **TRUE**, that the antenna referenced by the
**uAntennaListIndex** value supports transmit and receive operations.

## Syntax

```cpp
typedef struct _DOT11_SUPPORTED_ANTENNA {
  ULONG   uAntennaListIndex;
  BOOLEAN bSupportedAntenna;
} DOT11_SUPPORTED_ANTENNA, *PDOT11_SUPPORTED_ANTENNA;
```

## Remarks

The meaning of the
**bSupportedAntenna** member depends on the OID that it is used with. For example, if
**bSupportedAntenna** is **TRUE** when an antenna list is queried through
[OID_DOT11_SUPPORTED_RX_ANTENNA](https://learn.microsoft.com/previous-versions/ms893804(v=msdn.10)),
the antenna referenced by the
**uAntennaListIndex** member is supported for receive operations.

## See also

[DOT11_SUPPORTED_ANTENNA_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_supported_antenna_list)

[OID_DOT11_SUPPORTED_TX_ANTENNA](https://learn.microsoft.com/previous-versions/windows/embedded/ee484405(v=winembedded.80))

[OID_DOT11_SUPPORTED_RX_ANTENNA](https://learn.microsoft.com/previous-versions/ms893804(v=msdn.10))