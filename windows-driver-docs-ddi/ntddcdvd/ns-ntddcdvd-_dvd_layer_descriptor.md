# _DVD_LAYER_DESCRIPTOR structure

## Description

The DVD_LAYER_DESCRIPTOR structure is used in conjunction with the [IOCTL_DVD_READ_STRUCTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_dvd_read_structure) request to retrieve a DVD layer descriptor.

## Members

### `BookVersion`

Specifies the version of the specified book that this media complies with.

### `BookType`

Specifies the DVD book this media complies with. This member can have one of the following values:

| Value | Meaning |
| --- | --- |
| 0 | DVD-ROM |
| 1 | DVD-RAM |
| 2 | DVD-R |
| 3 | DVD-RW |
| 9 | DVD+RW |

### `MinimumRate`

Specifies the read rate to use for the media. This member can have one of the following values:

| Value | Meaning |
| --- | --- |
| 0 | DVD-ROM |
| 1 | DVD-RAM |
| 2 | DVD-R |
| 3 | DVD-RW |
| 9 | DVD+RW |

### `DiskSize`

Specifies the physical size of the media. A value of zero indicates 120 mm. A value of 1 indicates a size of 80 mm.

### `LayerType`

Indicates the type of layer. This member can have one of the following values:

| Value | Meaning |
| --- | --- |
| 1 | Read-only layer |
| 2 | Recordable layer |
| 4 | Rewritable layer |

### `TrackPath`

Specifies the direction of the layers when more than one layer is used. If the **TrackPath** member is zero, this media uses a parallel track path (PTP). With PTP, each layer is independent and has its own lead-in and lead-out areas. If **TrackPath** is 1, the media uses opposite track path (OTP). With opposite track path, the two layers are united, and there is only one lead-in and lead-out area. For further details, see the *SCSI Multimedia Commands - 3 (MMC-3)* specification.

### `NumberOfLayers`

Specifies the number of layers present on the side of the media being read. A value of zero indicates that the media has one layer. A value of 1 indicates that the media has two layers.

### `Reserved1`

Reserved.

### `TrackDensity`

Indicates the track width used for this media in units of micrometers per track. This member can have one of the following values:

| Value | Meaning |
| --- | --- |
| 0 | 0.74 m/track |
| 1 | 0.80 m/track |
| 2 | 0.615 m/track |

### `LinearDensity`

Indicates the minimum/maximum pit length used for this layer in units of micrometers per bit. This member can have one of the following values:

| Value | Meaning |
| --- | --- |
| 0 | 0.267 m/bit |
| 1 | 0.293 m/bit |
| 2 | 0.409 to 0.435 m/bit |
| 4 | 0.280 to 0.291 m/bit |
| 8 | 0.353 m/bit |

### `StartingDataSector`

Specifies the first block that contains user data. This member can have one of the following values:

| Value | Meaning |
| --- | --- |
| 0x30000 | An initial block value of 0x30000 indicates that the media type is DVD-ROM or DVD-R/-RW |
| 0x31000 | An initial block value of 0x30000 indicates that the media type is DVD-RAM or DVD+RW |

### `EndDataSector`

Specifies the last sector of the user data in the last layer of the media.

### `EndLayerZeroSector`

Specifies the last sector of the user data in layer zero. If this media does not use the opposite track path method and contains multiple layers, this value is set to zero.

### `Reserved5`

Reserved.

### `BCAFlag`

Indicates, if set to 1, the presence of data in the burst cutting area (BCA). If set to zero, it indicates that there is no BCA data.

## Remarks

For more information, see the *SCSI Multimedia Commands - 3 (MMC-3)* specification.

## See also

[IOCTL_DVD_READ_STRUCTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_dvd_read_structure)