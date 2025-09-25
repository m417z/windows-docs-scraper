# _STI_DIAG structure

## Description

The STI_DIAG structure is used as a parameter to the [IStiDevice::Diagnostic](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-diagnostic) and [IStiUSD::Diagnostic](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-diagnostic) methods.

## Members

### `dwSize`

Caller-supplied size, in bytes, of the STI_DIAG structure.

### `dwBasicDiagCode`

Bit flag indicating the type of test to be performed. Currently this must be STI_DIAGCODE_HWPRESENCE*.*

### `dwVendorDiagCode`

Optional, vendor-defined diagnostic request code.

### `dwStatusMask`

Reserved for future use.

### `sErrorInfo`

Structure of type [STI_ERROR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_error_infow).