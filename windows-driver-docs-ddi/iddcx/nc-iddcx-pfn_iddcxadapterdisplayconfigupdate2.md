## Description

**PFN_IDDCXADAPTERDISPLAYCONFIGUPDATE2** is a pointer to an OS callback function that updates the display configuration for the specified adapter.

## Parameters

### `DriverGlobals`

[in] Contains system-defined per-driver data.

### `AdapterObject`

[in] The adapter object that the display configuration is associated with.

### `pInArgs`

[in] Input arguments for the display configuration update.

## Return value

**PFN_IDDCXADAPTERDISPLAYCONFIGUPDATE2** returns an NTSTATUS value that indicates the success or failure of the display configuration update.

## Remarks

An indirect display driver (IDD) shouldn't call this function directly. IDDs should instead call [**IddCxAdapterDisplayConfigUpdate2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterdisplayconfigupdate2).

## See also

[**IddCxAdapterDisplayConfigUpdate2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterdisplayconfigupdate2)