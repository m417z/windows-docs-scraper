# NET_WAKE_SOURCE_BITMAP_PARAMETERS structure

## Description

The **NET_WAKE_SOURCE_BITMAP_PARAMETERS** structure contains parameters for a wake-on-LAN (WoL) bitmap pattern wake source.

## Members

### `Size`

The size of this structure, in bytes.

### `Id`

The identifier for this wake source.

### `Pattern`

A sequence of bytes that contains a pattern against which to compare bytes in an incoming packet.

### `PatternSize`

The size of the bitmap pattern, in bytes.

### `Mask`

A mask that specifies which bytes in incoming packets should be matched against the bitmap pattern. Each bit in the bitmask corresponds to a byte in the pattern. If a bit is zero, the corresponding byte in the incoming packet should not be pattern-matched. If the bit is one, the network adapter compares the byte in the incoming packet with the byte specified in the pattern.

### `MaskSize`

The size of the mask, in bytes.

## Remarks

Call [**NET_WAKE_SOURCE_BITMAP_PARAMETERS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/nf-netwakesource-net_wake_source_bitmap_parameters_init) to initialize this structure and fill in its **Size** field. After calling **NET_WAKE_SOURCE_BITMAP_PARAMETERS_INIT**, call [**NetWakeSourceGetBitmapParameters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/nf-netwakesource-netwakesourcegetbitmapparameters) to fill in the other members of the structure.

An upper-layer driver can specify a generic WOL pattern with the **Pattern** member. A bitmap pattern is specified as a sequence of bytes and a mask bitmap, specified in the **Mask** member. Each bit in the mask corresponds to a byte in the pattern, and specifies whether the corresponding byte in the incoming packet should be matched against the corresponding byte in the pattern. If all the bytes compared by the network adapter match, the packet is a match and the network adapter should generate a wake-up event.

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_WAKE_SOURCE_BITMAP_PARAMETERS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/nf-netwakesource-net_wake_source_bitmap_parameters_init)

[**NetWakeSourceGetBitmapParameters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/nf-netwakesource-netwakesourcegetbitmapparameters)