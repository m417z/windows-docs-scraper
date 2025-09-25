# _DXGKDT_OPM_DVI_CHARACTERISTICS enumeration

## Description

The DXGKDT_OPM_DVI_CHARACTERISTICS enumeration indicates the Digital Video Interface (DVI) electrical characteristics of a connector.

## Constants

### `DXGKMDT_OPM_DVI_CHARACTERISTIC_1_0`

Indicates that the DVI electrical characteristics are version 1.0.

### `DXGKMDT_OPM_DVI_CHARACTERISTIC_1_1_OR_ABOVE`

Indicates that the DVI electrical characteristics are version 1.1 or later.

### `DXGKMDT_OPM_DVI_CHARACTERISTICS_FORCE_ULONG`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. You should not use this value.

## Remarks

The DXGKMDT_OPM_GET_DVI_CHARACTERISTICS GUID is used in a call to the display miniport driver's [DxgkDdiOPMGetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_information) function to retrieve the DVI electrical characteristics of the output connector. For more information about retrieving information about a protected output, see [Retrieving Information About a Protected Output](https://learn.microsoft.com/windows-hardware/drivers/display/retrieving-information-about-a-protected-output).

## See also

[DxgkDdiOPMGetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_information)