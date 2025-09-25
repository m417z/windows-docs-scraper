## Description

The AVCSTRM_FORMAT_INFO structure is used to describe a data stream.

## Members

### `SizeOfThisBlock`

Specifies the size of this data structure, in bytes.

### `AVCStrmFormat`

Specifies one of the AV/C streaming subunit formats defined in [AVCSTRM_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ne-avcstrm-_avcstrm_format).

### `cipHdr1`

Specifies the definition of the first quadlet of the two quadlet CIP header.

### `cipHdr2`

Specifies the definition of the second quadlet of the two quadlet CIP header.

### `SrcPacketsPerFrame`

Specifies the number of source packets to fill a data frame.

### `FrameSize`

Specifies the data buffer size.

### `NumOfRcvBuffers`

Specifies the number of receiving buffers.

### `NumOfXmtBuffers`

Specifies the number of transmitting buffers.

### `OptionFlags`

Specifies any option flags. Currently, only one flag is defined:

| Flag | Description |
|---|---|
| AVCSTRM_FORMAT_OPTION_STRIP_SPH | Strip the SPH (source packet header) from the 192-byte data packet for MPEG2TS. |

### `AvgTimePerFrame`

Specifies the average time per frame in 100 nanosecond units.

### `BlockPeriod`

Specifies the block period. This is used for transmit only. It is calculated from 1/ BlockPerSecond *1,000,000,000 picoseconds. For SDDV, it transmits one block per 1394 cycle. 1/(29.97* 250) * 1,000,000,000,000 = 133,466,800 picoseconds.

### `Reserved`

Reserved. Do not use. Must be set to 0.

## See also

[AVCSTRM_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ne-avcstrm-_avcstrm_format)

[CIP_HDR1](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ns-avcstrm-_cip_hdr1)

[CIP_HDR2_FDF](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ns-avcstrm-_cip_hdr2_fdf)

[CIP_HDR2_MPEGTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ns-avcstrm-_cip_hdr2_mpegts)

[CIP_HDR2_SYT](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ns-avcstrm-_cip_hdr2_syt)