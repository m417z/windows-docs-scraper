# _PEP_POWER_CONTROL_REQUEST structure (pep_x.h)

## Description

The **PEP_POWER_CONTROL_REQUEST** structure contains a request from a driver for a power control operation.

## Members

### `DeviceHandle` [in]

A PEPHANDLE value that identifies the device. The PEP supplied this handle in response to a previous [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification.

### `PowerControlCode` [in]

A pointer to a GUID value that specifies the power control operation to perform. This is the same value that the requesting driver supplied as the *PowerControlCode* parameter to the [PoFxPowerControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxpowercontrol) routine.

### `InBuffer` [in]

A pointer to a driver-allocated input buffer that contains the input parameters for this power control operation. This is the same value that the requesting driver supplied as the *InBuffer* parameter to the **PoFxPowerControl** routine.

### `InBufferSize` [in]

The size in bytes of the buffer pointed to by **InBuffer**. This is the same value that the requesting driver supplied as the *InBufferSize* parameter to the **PoFxPowerControl** routine.

### `OutBuffer` [in]

A pointer to a driver-allocated output buffer to which the PEP writes the results of this power control operation. This is the same value that the requesting driver supplied as the *OutBuffer* parameter to the **PoFxPowerControl** routine.

### `OutBufferSize` [in]

The size in bytes of the buffer pointed to by **OutBuffer**.

### `BytesReturned` [out]

The number of bytes that the PEP wrote to the output buffer pointed to by **OutBuffer**.

### `Status` [out]

The status of the requested power control operation. If the operation is successful, the PEP sets this member to STATUS_SUCCESS. Otherwise, the PEP sets this member to an appropriate error status code.

## Remarks

This structure is used by the [PEP_DPM_POWER_CONTROL_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_power_control_request) notification. The first six members of the structure contain input values that are supplied by the Windows [power management Framework](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework) (PoFx). The last two members contain values that the PEP writes to the structure in response to this notification. In addition, the PEP writes to the output buffer pointed to by the **OutBuffer** member.

If the output buffer is too small to receive all of the result data from the operation, the PEP sets the **Status** member of the structure to STATUS_INSUFFICIENT_RESOURCES, sets the **BytesReturned** member to the required size of the output buffer, and (typically) writes no data to the output buffer.

The driver for a device can call the [PoFxPowerControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxpowercontrol) routine to request a power control operation on the device. During this call, PoFx delegates the handling of this request to the PEP that owns the device. The **PowerControlCode** member of the **PEP_POWER_CONTROL_REQUEST** structure contains a custom control code whose meaning is understood by both the driver and the PEP for the device.

## See also

[PEP_DPM_POWER_CONTROL_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_power_control_request)

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)

[PoFxPowerControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxpowercontrol)