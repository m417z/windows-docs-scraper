## Description

A **IDDCX_DISPLAYCONFIGPATH2** structure contains path display configuration information.

## Members

### `Size`

Size, in bytes, of this structure.

### `Flags`

A bitwise OR of [**IDDCX_DISPLAYCONFIGPATH2_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_displayconfigpath2_flags) values that identify the flags for this path, including which fields contain valid data.

### `MonitorObject`

An [**IDDCX_MONITOR**](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object handle that the driver provides to identify the monitor this path is targeted at.

### `Mode`

If valid, this field is a [**IDDCX_DISPLAYCONFIG_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_displayconfig_mode) structure that contains details of the mode to be set for the monitor in this path.

### `MonitorScaleFactor`

If valid, this field specifies the requested monitor DPI for this path. This value is just a hint and OS may override it to ensure the DPI configuration of the session is valid. Valid values are 100 to 500 inclusive.

### `MonitorPhysicalSize`

If valid, this field is a [**DISPLAYCONFIG_2DREGION**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-displayconfig_2dregion) structure that contains the physical width and height override for the specified monitor, in millimeters. A value of zero means no override.

### `MonitorColorimetry`

If valid, this field is a [**IDDCX_DISPLAYCONFIG_MONITOR_COLORIMETRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_displayconfig_monitor_colorimetry) structure that contains the colorimetry details for the specified monitor.

### `MonitorSdrWhiteLevel`

If valid, this field specifies the new white level, in nits, to be used for SDR content on this monitor when in an HDR mode.

## Remarks

An indirect display driver (IDD) calls [**IddCxAdapterDisplayConfigUpdate2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterdisplayconfigupdate2) when it receives a new display configuration. It passes an array of **IDDCX_DISPLAYCONFIGPATH2** structures in [**IDARG_IN_ADAPTERDISPLAYCONFIGUPDATE2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_adapterdisplayconfigupdate2).

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**IDARG_IN_ADAPTERDISPLAYCONFIGUPDATE2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_adapterdisplayconfigupdate2)

[**IddCxAdapterDisplayConfigUpdate2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterdisplayconfigupdate2)