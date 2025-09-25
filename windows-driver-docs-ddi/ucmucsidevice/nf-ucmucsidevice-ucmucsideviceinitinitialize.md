# UcmUcsiDeviceInitInitialize function

## Description

Initializes the [**WDFDEVICE_INIT**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) provided by the framework.

## Parameters

### `DeviceInit`

A pointer to a framework-allocated [**WDFDEVICE_INIT**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, returns an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

The client driver must call this function after calling [**WdfDeviceInitSetPnpPowerEventCallbacks**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpnppowereventcallbacks). This function initializes the UCSI extension (UcmUcsiCx) with the framework **WDFDEVICE_INIT** structure that contains pointers to PnP and power callback functions implemented by the client driver.

## See also