# NET_WAKE_SOURCE_MEDIA_CHANGE_PARAMETERS structure

## Description

The **NET_WAKE_SOURCE_MEDIA_CHANGE_PARAMETERS** structure contains parameters for a media change wake-on-LAN (WoL) wake source.

## Members

### `Size`

The size of this structure, in bytes.

### `MediaConnect`

A boolean value that specifies if the net adapter generated the wake-up event because it connected to the network media.

### `MediaDisconnect`

A boolean value that specifies if the net adapter generated the wake-up event because it disconnected from the network media.

## Remarks

Call [**NET_WAKE_SOURCE_MEDIA_CHANGE_PARAMETERS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/nf-netwakesource-net_wake_source_media_change_parameters_init) to initialize this structure and fill in its **Size** field. After calling **NET_WAKE_SOURCE_MEDIA_CHANGE_PARAMETERS_INIT**, call [**NetWakeSourceGetMediaChangeParameters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/nf-netwakesource-netwakesourcegetmediachangeparameters) to fill in the other members of the structure.

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_WAKE_SOURCE_MEDIA_CHANGE_PARAMETERS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/nf-netwakesource-net_wake_source_media_change_parameters_init)

[**NetWakeSourceGetMediaChangeParameters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/nf-netwakesource-netwakesourcegetmediachangeparameters)