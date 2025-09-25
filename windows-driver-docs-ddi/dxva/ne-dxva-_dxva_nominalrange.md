# _DXVA_NominalRange enumeration

## Description

The DXVA_NominalRange enumeration type contains enumerators that identify whether sample data includes headroom (values beyond 1.0 white) and toeroom (superblacks below the reference 0.0 black).

## Constants

### `DXVA_NominalRangeShift`

Specifies to shift bits by 12 positions (DXVA_ExtColorData_ShiftBase + 4, or 8 + 4).

### `DXVA_NominalRangeMask`

Specifies the nominal range mask. 3 (0x00007000) bits of a DWORD can be used to specify nominal range.

### `DXVA_NominalRange_Unknown`

Specifies that the nominal range is not specified.

### `DXVA_NominalRange_Normal`

Specifies that normalized chroma [0..1] maps to [0..255] for 8-bit or [0..1023] for 10-bit.

### `DXVA_NominalRange_Wide`

Specifies that normalized chroma [0..1] maps to [16..235] for 8-bit or [64..940] for 10-bit.

### `DXVA_NominalRange_0_255`

Specifies that normalized chroma [0..1] maps to [0..255] for 8-bit or [0..1023] for 10-bit.

### `DXVA_NominalRange_16_235`

Specifies that normalized chroma [0..1] maps to [16..235] for 8-bit or [64..940] for 10-bit.

### `DXVA_NominalRange_48_208`

Specifies that normalized chroma [0..1] maps to [48..208] for 8-bit or [192..832] for 10-bit.

## Remarks

One of the enumerators of DXVA_NominalRange can be specified in the **NominalRange** member of the [DXVA_ExtendedFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_extendedformat) structure.

Wide gamut R'G'B' (that is, blackpoint at 16,16,16 and whitepoint at 235,235,235) must be differentiated from normal [sRGB](https://go.microsoft.com/fwlink/p/?linkid=10112).

## See also

[DXVA_ExtendedFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_extendedformat)