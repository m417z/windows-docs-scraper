# _CIP_HDR1 structure

## Description

The CIP_HDR1 structure describes the generic data structure of the two quadlet CIP headers (first quadlet of the pair).

## Members

### `DBC`

Data block counter. This is not used by subunit driver. It must be set to 0.

### `Rsv00`

Reserved bits. Do not use this. It must be 0:0.

### `SPH`

Specifies a source packet header. A value of 1 indicates the presence of a source packet header. A value of 0 indicates no source packet header.

### `QPC`

Quadlet padding count (0..7 quadlets).

### `FN`

Specifies the fractional number.

### `DBS`

Specifies the data block size in quadlets.

### `SID`

Specifies the source node ID (ID of transmitter). Not used by the subunit driver. Must be set to 0.

### `Bit00`

Must be set to 0:0.

## See also

[CIP_HDR2_FDF](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ns-avcstrm-_cip_hdr2_fdf)

[CIP_HDR2_MPEGTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ns-avcstrm-_cip_hdr2_mpegts)

[CIP_HDR2_SYT](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ns-avcstrm-_cip_hdr2_syt)