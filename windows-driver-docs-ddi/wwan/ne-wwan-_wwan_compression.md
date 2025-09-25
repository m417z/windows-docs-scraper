# _WWAN_COMPRESSION enumeration

## Description

The WWAN_COMPRESSION enumeration lists the different compression options that are supported by the MB
device.

## Constants

### `WwanCompressionNone`

No compression is applied.

### `WwanCompressionEnable`

Enable header and data compression.

### `WwanCompressionMax`

The total number of supported compression options.

## Remarks

This enumeration applies only to GSM devices. The MB Service specifies
**WwanCompressionNone** as the compression type for CDMA-based devices.

## See also

[WWAN_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_context)

[WWAN_SET_CONTEXT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_context_state)