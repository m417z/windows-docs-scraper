# PoSetPowerRequest function (wdm.h)

## Description

The **PoSetPowerRequest** routine increments the count for the specified power request type.

## Parameters

### `PowerRequest` [in, out]

A pointer to a power request object that was created by the [PoCreatePowerRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-pocreatepowerrequest) routine.

### `Type` [in]

The type of power request. Set this parameter to the following [POWER_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_power_request_type) enumeration value:

* **PowerRequestSystemRequired**

## Return value

**PoSetPowerRequest** returns STATUS_SUCCESS if the call is successful. If the call fails, possible error return codes include the following:

| Return code | Description |
| --- | --- |
| **STATUS_NOT_SUPPORTED** | The *Type* parameter is set to an unsupported value. |

## Remarks

A driver can call the **PoSetPowerRequest** routine to request that the [power manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/power-manager) override several types of default power behavior, which are specified as [POWER_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_power_request_type) enumeration values. To restore the default behavior, the driver cancels the request by calling the [PoClearPowerRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poclearpowerrequest) routine.

The power manager maintains a count of the active requests for each power request type. The **PoSetPowerRequest** routine increments the count for the specified power request type by one. The **PoClearPowerRequest** routine decrements the count by one. A nonzero count indicates that requests from one or more components are active. After the count decrements to zero, the computer reverts to the default behavior for the specified power request type.

## See also

[POWER_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_power_request_type)

[PoClearPowerRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poclearpowerrequest)

[PoCreatePowerRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-pocreatepowerrequest)