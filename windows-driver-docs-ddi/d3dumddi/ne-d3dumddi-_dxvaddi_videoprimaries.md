# _DXVADDI_VIDEOPRIMARIES enumeration

## Description

The DXVADDI_VIDEOPRIMARIES enumeration type contains values that identify the color primaries, which state which RGB basis functions are used.

## Constants

### `DXVADDI_VideoPrimariesMask`

Specifies the color primaries mask. The first 5 (0x001F) bits of a DWORD can be used to specify color primaries.

### `DXVADDI_VideoPrimaries_Unknown`

Specifies that color primaries are not specified. The default is BT709.

### `DXVADDI_VideoPrimaries_reserved`

[in] Reserved. Do not use this value.

### `DXVADDI_VideoPrimaries_BT709`

Specifies BT709 primaries (including sRGB and scRGB).

### `DXVADDI_VideoPrimaries_BT470_2_SysM`

Specifies BT470-2 SysM primaries, which are the original NTSC primaries.

### `DXVADDI_VideoPrimaries_BT470_2_SysBG`

Specifies BT470-2 SysBG primaries.

### `DXVADDI_VideoPrimaries_SMPTE170M`

Specifies SMPTE170M primaries, which are rarely used analog NTSC primaries (also known as SMPTE RP 145).

### `DXVADDI_VideoPrimaries_SMPTE240M`

Specifies SMPTE240M primaries.

### `DXVADDI_VideoPrimaries_EBU3213`

Specifies EBU3213 primaries.

### `DXVADDI_VideoPrimaries_SMPTE_C`

Specifies SMPTE_C primaries, which are analog '79 NTSC primaries.

## Remarks

One of the values of DXVADDI_VIDEOPRIMARIES can be specified in the **VideoPrimaries** member of the [DXVADDI_EXTENDEDFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_extendedformat) structure.

## See also

[DXVADDI_EXTENDEDFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_extendedformat)