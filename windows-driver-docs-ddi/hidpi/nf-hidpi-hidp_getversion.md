## Description

The **HidP_GetVersion** function is a header-only implementation that returns the HID API version.

## Parameters

### `Version` [out]

The version of the HID API.

## Return value

**HidP_GetVersion** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) error code.

## Remarks

Call **HidP_GetVersion** at runtime before using [HidP_GetButtonArray](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getbuttonarray) or [HidP_SetButtonArray](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setbuttonarray). The **HidP_GetButtonArray** and **HidP_SetButtonArray** functions are only available on operating systems where **HidP_GetVersion** returns a value of two or greater. Version two of the API corresponds to Windows 11.

**HidP_GetVersion** is safe to call on down-level systems because it is a header-only implementation.

## See also

- [HidP_GetButtonArray](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getbuttonarray)
- [HidP_SetButtonArray](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setbuttonarray)