# IDDCX_DISPLAYCONFIGPATH structure

## Description

**IDDCX_DISPLAYCONFIGPATH** contains the display monitor configuration for a path.

## Members

### `Size`

Size, in bytes, of this structure.

### `MonitorObject`

An [**IDDCX_MONITOR**](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object handle that the driver provides to identify the monitor this path is targeted at.

### `Position`

A [**POINT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure containing the requested desktop position for this path.

### `Resolution`

A [**DISPLAYCONFIG_2DREGION**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-displayconfig_2dregion) structure containing the resolution for this path. **Resolution** must match a resolution supported by the driver.

### `Rotation`

A [**DISPLAYCONFIG_ROTATION**](https://learn.microsoft.com/windows/win32/api/wingdi/ne-wingdi-displayconfig_rotation) value specifying the requested screen orientation for this path.

### `RefreshRate`

A [**DISPLAYCONFIG_RATIONAL**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-displayconfig_rational) structure containing the requested refresh rate for this path. **RefreshRate** must match a refresh rate supported by the driver for the specified resolution.

> [!NOTE]
> This refresh rate is defined as progressive as remote drivers can only support progressive target modes.

### `VSyncFreqDivider`

The V Sync divider value for the specified **RefreshRate**.

### `MonitorScaleFactor`

The requested monitor DPI for this path. This value is just a hint and OS may override the value to ensure the DPI configuration of the session is valid. Valid values are 100 to 500 inclusive.

### `PhysicalWidthOverride`

Physical width override for the specified monitor, in millimeters. A value of zero means no override.

### `PhysicalHeightOverride`

Physical height override for the specified monitor, in millimeters. A value of zero means no override.

## Remarks

An indirect display driver (IDD) calls [**IddCxAdapterDisplayConfigUpdate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterdisplayconfigupdate) when it receives a new display configuration. It passes an array of **IDDCX_DISPLAYCONFIGPATH** structures in [**IDARG_IN_ADAPTERDISPLAYCONFIGUPDATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_adapterdisplayconfigupdate).

## See also

[**IDARG_IN_ADAPTERDISPLAYCONFIGUPDATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_adapterdisplayconfigupdate)

[**IddCxAdapterDisplayConfigUpdate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterdisplayconfigupdate)