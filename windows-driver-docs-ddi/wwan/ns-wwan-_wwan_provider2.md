# _WWAN_PROVIDER2 structure

## Description

The WWAN_PROVIDER2 structure describes the details of a network provider.

## Members

### `Provider`

A formatted WWAN_PROVIDER object that represents details about a network provider.

### `WwanCellularClass`

The cellular class that the provider uses.

### `Rssi`

A value that represents the strength of the wireless signal. Please refer to [WWAN_SIGNAL_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_signal_state) on the format of this member.

### `ErrorRate`

 A coded value that represents a percentage range of error rates. Please refer to [WWAN_SIGNAL_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_signal_state) on the format of this member.

## See also

[WWAN_CELLULAR_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_cellular_class)

[WWAN_PROVIDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_provider)

[WWAN_SIGNAL_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_signal_state)