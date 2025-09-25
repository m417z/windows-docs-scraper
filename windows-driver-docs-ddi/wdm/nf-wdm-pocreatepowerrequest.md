# PoCreatePowerRequest function (wdm.h)

## Description

The **PoCreatePowerRequest** routine creates a power request object.

## Parameters

### `PowerRequest` [out]

A pointer to a location into which the routine writes a pointer to the newly created power request object. If the call fails, the routine writes **NULL** to this location.

### `DeviceObject` [in]

A pointer to the device object of the caller (a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure).

### `Context` [in]

A pointer to a [COUNTED_REASON_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_counted_reason_context) structure that describes why the caller is creating the power request object. This parameter is optional and can be set to **NULL**.

## Return value

**PoCreatePowerRequest** returns STATUS_SUCCESS if the call is successful. If the call fails, possible error return codes include the following:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The *DeviceObject* parameter is **NULL**. |
| **STATUS_INSUFFICIENT_RESOURCES** | There is not enough memory available to create a power request object. |

## Remarks

This routine creates a power request object. To enable power requests, the caller should create one power request object and use that object for all calls to the [PoSetPowerRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-posetpowerrequest) and [PoClearPowerRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poclearpowerrequest) routines.

A driver can use power requests to override certain aspects of the computer's default power behavior. For example, a driver for a TV receiver device can use power requests to prevent the [power manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/power-manager) from automatically blanking the display during extended periods of time in which no user interaction occurs.

When the power request object is no longer needed, the caller must delete the object by calling the [PoDeletePowerRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-podeletepowerrequest) routine. The driver must delete the power request object before it deletes the device object that was used to create the power request object.

## See also

[PoClearPowerRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poclearpowerrequest)

[PoDeletePowerRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-podeletepowerrequest)

[PoSetPowerRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-posetpowerrequest)