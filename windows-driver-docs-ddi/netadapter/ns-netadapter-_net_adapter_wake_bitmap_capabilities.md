# NET_ADAPTER_WAKE_BITMAP_CAPABILITIES structure

## Description

The **NET_ADAPTER_WAKE_BITMAP_CAPABILITIES** structure describes a net adapter's wake on LAN (WoL) capabilities for waking from a bitmap pattern.

## Members

### `Size`

The size of this structure, in bytes.

### `BitmapPattern`

A boolean value that describes if the net adapter is capable of waking from a bitmap pattern.

### `MaximumPatternCount`

The maximum number of bitmap patterns that the hardware supports.

### `MaximumPatternSize`

The maximum size, in bytes, for the bitmap patterns that the hardware supports.

## Remarks

Call [**NET_ADAPTER_WAKE_BITMAP_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_wake_bitmap_capabilities_init) to initialize this structure, then call [**NetAdapterWakeSetBitmapCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterwakesetbitmapcapabilities) to set the net adapter's bitmap pattern WoL capabilities. Client drivers typically call **NetAdapterWakeSetBitmapCapabilities** when starting a net adapter, but before calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_ADAPTER_WAKE_BITMAP_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_wake_bitmap_capabilities_init)

[**NetAdapterWakeSetBitmapCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterwakesetbitmapcapabilities)

[**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart)