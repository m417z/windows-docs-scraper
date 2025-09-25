# _CIP_HDR2_MPEGTS structure

## Description

The CIP_HDR2_MPEGTS structure describes the second quadlet of a CIP header pair for an MPEGTS format stream.

## Members

### `TSF`

Time-shift flag. This is not used for opening a stream.

### `RSV23bit`

Reserved bits. This must be 0. Do not use this.

### `FMT`

CIP format. For example, 000000 = DV and 100000 = MPEGTS.

### `Bit10`

Must be set to 1:0

## See also

[CIP_HDR1](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ns-avcstrm-_cip_hdr1)