# _CIP_HDR2_FDF structure

## Description

The CIP_HDR2_FDF structure describes the second quadlet of a CIP header pair.

## Members

### `FDF`

Format dependent field. This is not used for opening a stream. These must be set to 0.

### `FMT`

CIP format. For example, 000000 = DV and 100000 = MPEG2TS.

### `Bit10`

Must be set to 1:0

## See also

[CIP_HDR1](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ns-avcstrm-_cip_hdr1)