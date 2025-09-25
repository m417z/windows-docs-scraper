# DXGKDDI_UNLOAD callback function

## Description

The *DxgkDdiUnload* function frees any resources allocated during execution of the display miniport driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) function.

## Remarks

Typically, there will be nothing to do in *DxgkDdiUnload*.

*DxgkDdiUnload* should be made pageable.

## See also

[DriverEntry of Display Miniport Driver](https://learn.microsoft.com/windows-hardware/drivers/display/driverentry-of-display-miniport-driver)