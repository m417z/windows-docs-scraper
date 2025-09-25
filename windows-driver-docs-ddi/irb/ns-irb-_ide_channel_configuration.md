# IDE_CHANNEL_CONFIGURATION structure

## Description

The IDE_CHANNEL_CONFIGURATION structure contains configuration information for the indicated channel.

> [!NOTE]
> The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `Version`

The port driver sets this member to sizeof(IDE_CHANNEL_CONFIGURATION). The miniport driver should verify that the version is greater than or equal to the one it is using.

### `ChannelNumber`

The port driver sets this field to the number assigned for this channel. For non-native mode controllers, the primary channel will always be assigned 0 and the secondary channel will always be assigned 1.

### `SupportedAdvances`

Reserved; do not use.

### `ChannelMode`

The port driver sets this field to inform the ATA miniport which mode it is running at. There are three possible modes:

| Mode | Description |
| ---- | ----------- |
| IdeModeNormal | This is the standard full capabilities mode where the ATA miniport may operate normally. |
| IdeModeDump | This is the limited no memory mode that an ATA miniport operates in during hibernate or crashdump. Callback routines and registry access routines cannot be used when in this mode. |
| IdeModeRemovableBay | Similar to the IdeModeNormal, this indicates the ATA miniport must take extra steps to enable enumeration of devices that may have just been hotplugged onto a Parallel ATA bus. |

### `ChannelResources`

The port driver uses this pointer to pass miniport hardware resources to be used to access the HBA on a PCI bus.

### `NumberOfOverlappedRequests`

The miniport driver should set this field to the number of requests the channel can handle at a time. By default, the port driver sets this to 1.

### `MaxTargetId`

The miniport should set this member to the maximum target ID supported on this channel. Typically, this is 1 less than the maximum number of devices supported on the channel. By default, the port driver sets this is set to 1 to indicate that 2 devices are supported on a channel.

### `SyncWithIsr`

Indicates support for unsynchronized I/O processing in the miniport driver. The miniport driver must set this member to TRUE.

### `SupportsWmi`

Indicates support for WMI. The miniport driver must set this member to TRUE.

### `AdvancedChannelConfiguration`

Reserved for system use; do not use.