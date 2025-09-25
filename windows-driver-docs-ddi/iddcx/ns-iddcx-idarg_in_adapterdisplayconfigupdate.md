# IDARG_IN_ADAPTERDISPLAYCONFIGUPDATE structure

## Description

**IDARG_IN_ADAPTERDISPLAYCONFIGUPDATE** contains the arguments used in the [**IddCxAdapterDisplayConfigUpdate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterdisplayconfigupdate)
function.

## Members

### `PathCount`

[in] The number of paths in the pPaths array. **PathCount** can't be zero.

### `pPaths`

[in] Pointer to array of [**IDDCX_DISPLAYCONFIGPATH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_displayconfigpath) structures containing path display configuration information.

## Remarks

An indirect display driver (IDD) calls [**IddCxAdapterDisplayConfigUpdate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterdisplayconfigupdate) when it receives a new display configuration.

## See also

[**IDDCX_DISPLAYCONFIGPATH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_displayconfigpath)

[**IddCxAdapterDisplayConfigUpdate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterdisplayconfigupdate)