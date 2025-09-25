## Description

A **IDDCX_DISPLAYCONFIG_MONITOR_COLORIMETRY_FLAGS** enumeration contains flags that indicate support for specific colorimetry and Electro-Optical Transfer Function (EOTF) capabilities.

## Constants

### `IDDCX_DISPLAYCONFIG_MONITOR_COLORIMETRY_FLAGS_UNINITIALIZED:0x0`

Indicates that an **IDDCX_DISPLAYCONFIG_MONITOR_COLORIMETRY_FLAGS** variable has not yet been assigned a meaningful value.

### `IDDCX_DISPLAYCONFIG_MONITOR_COLORIMETRY_FLAGS_BT2020YCC:0x1`

Tells the OS that the monitor supports the BT.2020 color space using a YCC signal format.

### `IDDCX_DISPLAYCONFIG_MONITOR_COLORIMETRY_FLAGS_BT2020RGB:0x2`

Tells the OS that the monitor supports the BT.2020 color space using an RGB signal format.

### `IDDCX_DISPLAYCONFIG_MONITOR_COLORIMETRY_FLAGS_ST2084:0x4`

ells the OS that the monitor supports the ST.2084 Electro-Optical Transfer Function (EOTF).

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**IDARG_IN_ADAPTERDISPLAYCONFIGUPDATE2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_adapterdisplayconfigupdate2)

[**IDDCX_DISPLAYCONFIG_MONITOR_COLORIMETRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_displayconfig_monitor_colorimetry)

[**IDDCX_DISPLAYCONFIGPATH2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_displayconfigpath2)

[**IddCxAdapterDisplayConfigUpdate2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterdisplayconfigupdate2)