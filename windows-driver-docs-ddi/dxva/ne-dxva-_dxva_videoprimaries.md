# _DXVA_VideoPrimaries enumeration

## Description

The DXVA_VideoPrimaries enumeration type contains enumerators that identify the color primaries, which state which RGB basis functions are used.

## Constants

### `DXVA_VideoPrimariesShift`

Specifies to shift bits by 22 positions (DXVA_ExtColorData_ShiftBase + 14, or 8 + 14).

### `DXVA_VideoPrimariesMask`

Specifies the color primaries mask. 5 (0x07C00000) bits of a DWORD can be used to specify color primaries.

### `DXVA_VideoPrimaries_Unknown`

Specifies that color primaries are not specified. The default is BT709.

### `DXVA_VideoPrimaries_reserved`

Reserved.

### `DXVA_VideoPrimaries_BT709`

Specifies BT709 primaries (including sRGB, scRGB).

### `DXVA_VideoPrimaries_BT470_2_SysM`

Specifies BT470-2 SysM primaries, which are the original NTSC primaries.

### `DXVA_VideoPrimaries_BT470_2_SysBG`

Specifies BT470-2 SysBG primaries.

### `DXVA_VideoPrimaries_SMPTE170M`

Specifies SMPTE170M primaries, which are rarely used analog NTSC primaries (also known as SMPTE RP 145).

### `DXVA_VideoPrimaries_SMPTE240M`

Specifies SMPTE240M primaries.

### `DXVA_VideoPrimaries_EBU3213`

Specifies EBU3213 primaries.

### `DXVA_VideoPrimaries_SMPTE_C`

Specifies SMPTE_C primaries, which are analog '79 NTSC primaries.

## Remarks

One of the enumerators of DXVA_VideoPrimaries can be specified in the **VideoPrimaries** member of the [DXVA_ExtendedFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_extendedformat) structure.

## See also

[DXVA_ExtendedFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_extendedformat)