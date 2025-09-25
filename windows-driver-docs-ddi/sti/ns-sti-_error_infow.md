# _ERROR_INFOW structure

## Description

The STI_ERROR_INFO structure is used as a parameter for the [IStiDevice::GetLastErrorInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-getlasterrorinfo) and [IStiUSD::GetLastErrorInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-getlasterrorinfo) methods. It is also used as a member of the [STI_DIAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_sti_diag) structure.

## Members

### `dwSize`

Caller-supplied size, in bytes, of the STI_ERROR_INFO structure.

### `dwGenericError`

Win32 error code.

### `dwVendorError`

Optional, vendor-specific error code.

### `szExtendedErrorText`

Optional character array containing a text string describing the error.