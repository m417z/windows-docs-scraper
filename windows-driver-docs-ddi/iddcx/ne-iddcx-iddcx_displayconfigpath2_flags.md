## Description

An **IDDCX_DISPLAYCONFIGPATH2_FLAGS** enumeration value identifies the flags for the path, including which fields in the [**IDDCX_DISPLAYCONFIGPATH2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_displayconfigpath2) structure contain valid data.

## Constants

### `IDDCX_DISPLAYCONFIGPATH2_FLAGS_UNINITIALIZED:0x0`

Indicates that an **IDDCX_DISPLAYCONFIGPATH2_FLAGS** variable has not yet been assigned a meaningful value.

### `IDDCX_DISPLAYCONFIGPATH2_FLAGS_MODE_VALID:0x1`

If set, the accompanying [**IDDCX_DISPLAYCONFIGPATH2::Mode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_displayconfigpath2) field contains valid data.

### `IDDCX_DISPLAYCONFIGPATH2_FLAGS_MONITOR_SCALE_FACTOR_VALID:0x2`

If set, the accompanying [**IDDCX_DISPLAYCONFIGPATH2::MonitorScaleFactor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_displayconfigpath2) field contains valid data.

### `IDDCX_DISPLAYCONFIGPATH2_FLAGS_MONITOR_PHYSICAL_SIZE_VALID:0x4`

If set, the accompanying [**IDDCX_DISPLAYCONFIGPATH2::MonitorPhysicalSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_displayconfigpath2) field contains valid data.

### `IDDCX_DISPLAYCONFIGPATH2_FLAGS_MONITOR_COLORIMETRY_VALID:0x8`

If set, the accompanying [**IDDCX_DISPLAYCONFIGPATH2::MonitorColorimetry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_displayconfigpath2) field contains valid data.

### `IDDCX_DISPLAYCONFIGPATH2_FLAGS_MONITOR_SDRWHITELEVEL_VALID:0x10`

If set, the accompanying [**IDDCX_DISPLAYCONFIGPATH2::MonitorSdrWhiteLevel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_displayconfigpath2) field contains valid data.

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**IDARG_IN_ADAPTERDISPLAYCONFIGUPDATE2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_adapterdisplayconfigupdate2)

[**IDDCX_DISPLAYCONFIGPATH2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_displayconfigpath2)

[**IddCxAdapterDisplayConfigUpdate2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterdisplayconfigupdate2)