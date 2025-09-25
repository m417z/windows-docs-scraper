## Description

A **IDDCX_DISPLAYCONFIG_MONITOR_COLORMODE** enumeration value specifies the color mode to be set on a monitor.

## Constants

### `IDDCX_DISPLAYCONFIG_MONITOR_COLORMODE_UNINITIALIZED:0`

Indicates that an **IDDCX_DISPLAYCONFIG_MONITOR_COLORMODE** variable has not yet been assigned a meaningful value.

### `IDDCX_DISPLAYCONFIG_MONITOR_COLORMODE_SDR:1`

Allows a driver to indicate that it wants to run in SDR mode even if the OS may wish to use HDR or SDR WCG.

### `IDDCX_DISPLAYCONFIG_MONITOR_COLORMODE_SDRWCG:2`

Allows a driver to indicate that it wants to run in SDR WCG mode even if the OS may wish to use HDR or SDR.

### `IDDCX_DISPLAYCONFIG_MONITOR_COLORMODE_HDR10:3`

Allows a driver to indicate that it wants to run in HDR mode even if the OS may wish to use SDR or SDR WCG.

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**IDARG_IN_ADAPTERDISPLAYCONFIGUPDATE2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_adapterdisplayconfigupdate2)

[**IDDCX_DISPLAYCONFIG_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_displayconfig_mode)

[**IDDCX_DISPLAYCONFIGPATH2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_displayconfigpath2)

[**IddCxAdapterDisplayConfigUpdate2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterdisplayconfigupdate2)