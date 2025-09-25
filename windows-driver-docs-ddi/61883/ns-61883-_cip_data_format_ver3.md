# _CIP_DATA_FORMAT_VER3 structure

## Description

This structure is used by **CipDataFormat**.

## Members

### `FMT`

This member is either known, or discovered by an AV/C command.

### `FDF_hi`

This member is either known, or discovered by an AV/C command.

### `FDF_mid`

This member is either known, or discovered by an AV/C command.

### `FDF_lo`

This member is either known, or discovered by an AV/C command.

### `bHeader`

This member is SPH as defined by IEC-61883.

### `Padding`

This member is QPC as defined by IEC-61883.

### `BlockSize`

This member is DBS as defined by IEC-61883.

### `Fraction`

This member is FN as defined by IEC-61883.

### `BlockPeriod`

This member is the number of 1394 ticks to send a data block.

### `BlockPeriodRemainder`

This member is the remainder of 1394 ticks to send a data block.

### `BlocksPerPacket`

This member is the number of blocks per packet; used for blocking mode only

## See also

[AV_61883_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)