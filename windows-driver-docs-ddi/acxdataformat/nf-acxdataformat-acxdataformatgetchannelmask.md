## Description

The **AcxDataFormatGetChannelMask** function gets the [channel mask](https://learn.microsoft.com/windows-hardware/drivers/audio/channel-mask) for the specified data format.

## Parameters

### `DataFormat` [in]

The data format for which to retrieve the channel mask.

## Return value

Returns a ULONGLONG value containing the channel mask.

## Remarks

The channel mask specifies the mapping of channels to speakers.

The following table shows the meaning of each bit in the channel mask:

| Bit number | Speaker position | Description |
|------------|------------------|-----------------------|
| 0 | FL | Front left |
| 1 | FR | Front right |
| 2 | FC | Front center |
| 3 | LFE | Low-frequency effects |
| 4 | BL | Back left |
| 5 | BR | Back right |
| 6 | FLC | Front left of center |
| 7 | FRC | Front right of center |
| 8 | BC | Back center |
| 9 | SL | Side left |
| 10 | SR | Side right |

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [Channel Mask](https://learn.microsoft.com/windows-hardware/drivers/audio/channel-mask)
- [acxdataformat.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)