# _CIP_HDR2_SYT structure

## Description

The CIP_HDR2_SYT structure describes the second quadlet of a CIP header pair for a DV format stream.

## Members

### `SYT`

Lower 16 bits of CYCLE_TIME. This is not used for opening a stream.

### `RSV`

Must be set to 0:0.

### `STYPE`

Specifies the video signal type, which is used for transmitting real time data.

### `F5060_OR_TSF`

Specifies field encoding or time-shift flag depending on the value of FMT. This flag may be either 0 for NTSC or 1 for PAL, or 1 for TimeShiftFlag. This flag has multiple meanings (like a union) depending on the FMT member. If the FMT member indicates DV format, then this is either 50/60 flag (NTSC or PAL); if it is it MPEG-TS, then this is a time-shifting flag.

### `FMT`

CIP format ID. For example, 000000 = DV and 100000 = MPEG2TS. If this is 111111 (no data), then DBS, FN, SPH and DBC (in the first quadlet of the CIP header, [CIP_HDR1](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ns-avcstrm-_cip_hdr1)) are ignored.

### `Bit10`

Must be set to 1:0.

## See also

[CIP_HDR1](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ns-avcstrm-_cip_hdr1)