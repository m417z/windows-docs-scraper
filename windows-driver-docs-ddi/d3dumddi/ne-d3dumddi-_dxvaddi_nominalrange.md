# _DXVADDI_NOMINALRANGE enumeration

## Description

The DXVADDI_NOMINALRANGE enumeration type contains values that identify whether sample data includes headroom (that is, values beyond 1.0 white) and toeroom (that is, superblacks below the reference 0.0 black).

## Constants

### `DXVADDI_NominalRangeMask`

The nominal range mask. The first 3 (0x07) bits of a DWORD can be used to specify nominal range.

### `DXVADDI_NominalRange_Unknown`

The nominal range is not specified.

### `DXVADDI_NominalRange_Normal`

Normalized chroma [0..1] maps to [0..255] for 8-bit or [0..1023] for 10-bit.

### `DXVADDI_NominalRange_Wide`

Normalized chroma [0..1] maps to [16..235] for 8-bit or [64..940] for 10-bit.

### `DXVADDI_NominalRange_0_255`

Normalized chroma [0..1] maps explicitly to [0..255] for 8-bit.

### `DXVADDI_NominalRange_16_235`

Normalized chroma [0..1] maps explicitly to [16..235] for 8-bit.

### `DXVADDI_NominalRange_48_208`

Normalized chroma [0..1] maps explicitly to [48..208] for 8-bit.

## Remarks

One of the values of DXVADDI_NOMINALRANGE can be specified in the **NominalRange** member of the [DXVADDI_EXTENDEDFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_extendedformat) structure.

Wide gamut R'G'B' (that is, blackpoint at 16,16,16 and whitepoint at 235,235,235) must be differentiated from normal [sRGB](https://go.microsoft.com/fwlink/p/?linkid=10112).

## See also

[DXVADDI_EXTENDEDFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_extendedformat)