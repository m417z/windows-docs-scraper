## Description

**IDARG_IN_ADAPTERDISPLAYCONFIGUPDATE2** contains the arguments used in the [**IddCxAdapterDisplayConfigUpdate2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterdisplayconfigupdate2) function.

## Members

### `PathCount`

[in] The number of paths in the pPaths array. **PathCount** can't be zero.

### `pPaths`

[in] Pointer to array of [**IDDCX_DISPLAYCONFIGPATH2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_displayconfigpath2) structures containing path display configuration information.

## Remarks

An indirect display driver (IDD) calls [**IddCxAdapterDisplayConfigUpdate2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterdisplayconfigupdate2) when it receives a new display configuration.

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**IDDCX_DISPLAYCONFIGPATH2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_displayconfigpath2)

[**IddCxAdapterDisplayConfigUpdate2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterdisplayconfigupdate2)