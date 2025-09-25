## Description

Enables the function device object (FDO) to convey its auxiliary power requirement.

## Parameters

### `Context` [_In_reads_opt_(_Inexpressible_("varies"))]

The handle to the device.

### `AuxPowerInMilliWatts` [_In_]

The wattage in units of mW that the device needs for D3cold when the system is in S0. This value must be less than 0x80000000.

### `RetryInSeconds` [_Out_]

A pointer to a ULONG variable that receives the number of seconds the driver can retry its request when the request fails with STATUS_RETRY.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS Values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values). Possible errors are as follows:

| Error code | Description |
|---|---|
| STATUS_INVALID_PARAMETER | The input parameter is not valid. |
| STATUS_INVALID_DEVICE_REQUEST | The device is not in D0 or not the requester is not Function 0. |
| STATUS_RETRY | The request failed and the system indicates that a retry can be made. RetryInSeconds will contain the number of seconds the driver should wait before making the next request. |
| STATUS_UNSUCCESSFUL | The request failed and the system indicates that the current requested value is not possible. |
| STATUS_SUCCESS | The request succeeded. |

## Remarks

A device driver that successfully queries for the GUID_D3COLD_AUX_POWER_AND_TIMING_INTERFACE interface receives a pointer to a [**D3COLD_AUX_POWER_AND_TIMING_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_d3cold_aux_power_and_timing_interface) structure in which the driver sets the **RequestAuxPower** member to a pointer to its implementation of the _D3COLD_REQUEST_AUX_POWER_ callback function.

- For a multi-function device, only Function 0 is expected to call this routine and set the auxiliary power for the entire device.

- Function 0 must be in D0 state when this routine is called.

- There is no guarantee that the core power rail power will be removed after the success of this request.

## See also