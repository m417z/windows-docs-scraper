# _FEATURE_DATA_INCREMENTAL_STREAMING_WRITABLE structure

## Description

The FEATURE_DATA_INCREMENTAL_STREAMING_WRITABLE structure contains information about the Incremental Streaming Writable feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `DataTypeSupported`

Indicates the supported data type. See the *SCSI Multimedia - 4 (MMC-4)* specification for an explanation of the values that this member can take. **DataTypeSupported**[0] must hold the most significant byte of the number of the data type. **DataTypeSupported**[1] must hold the least significant byte of the number.

### `BufferUnderrunFree`

Indicates, when set to one, that the logical unit is capable of zero-loss linking.

### `AddressModeReservation`

### `TrackRessourceInformation`

### `Reserved01`

### `NumberOfLinkSizes`

Specifies the number of link sizes available for the current media. See the *MMC-3* specification for an explanation of the values that this member can take.

### `LinkSize`

Contains an array that indicates the number of logical blocks per link.

## Remarks

This structure holds data for the feature named "Incremental Streaming Writable" by the *MMC-3* specification. Devices that support this feature can write data to a contiguous region, and can append data to a limited number of locations on the media. On CD media, this is known as "packet recording" and on a DVD media it is known as "incremental recording".

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)