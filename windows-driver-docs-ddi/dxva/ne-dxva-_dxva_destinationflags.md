# _DXVA_DestinationFlags enumeration

## Description

The DXVA_DestinationFlags enumeration type contains a collection of flags that identify changes in the current destination surface from the previous destination surface.

## Constants

### `DXVA_DestinationFlagMask`

Specifies the destination-flag mask, which consists of the first 4 bits of a DWORD.

### `DXVA_DestinationFlag_Background_Changed`

Indicates that the background color of the destination surface changed.

### `DXVA_DestinationFlag_TargetRect_Changed`

Indicates that the target rectangle of the destination surface changed.

### `DXVA_DestinationFlag_ColorData_Changed`

Indicates that format information for the destination surface changed.

### `DXVA_DestinationFlag_Alpha_Changed`

Indicates that the planar alpha value for the destination surface changed.

## See also

[DXVA_DeinterlaceBltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_deinterlacebltex)

[DeinterlaceBltEx](https://learn.microsoft.com/windows-hardware/drivers/display/dxva-deinterlacebobdeviceclass-deinterlacebltex)