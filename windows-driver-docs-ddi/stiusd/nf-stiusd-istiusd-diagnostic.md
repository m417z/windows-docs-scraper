# IStiUSD::Diagnostic

## Description

A still image minidriver's **IStiUSD::Diagnostic** method runs diagnostic tests on a still image device.

## Parameters

### `pBuffer`

Caller-supplied pointer to an [STI_DIAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_sti_diag) structure to receive testing status information.

## Return value

If the operation succeeds, the method should return S_OK. Otherwise, it should return one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

The **IStiUSD::Diagnostic** method is called when a user clicks on the Scanners and Cameras Control Panel's Test button. The method should execute tests to confirm that the device is fully operational. For a scanner, these tests might include turning the light on and off, and moving the scanning arm. For a camera, they might include execution of built-in diagnostic functions, or manipulation of device settings. The return value should indicate success or failure of the diagnostic tests.

## See also

[IStiDevice::Diagnostic](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-diagnostic)

[IStiUSD](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)