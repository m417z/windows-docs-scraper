# _PEP_POWER_CONTROL_COMPLETE structure (pepfx.h)

## Description

The **PEP_POWER_CONTROL_COMPLETE** structure contains status information for a power control operation that the PEP previously requested and that the device driver has completed.

## Members

### `DeviceHandle` [in]

A PEPHANDLE value that identifies the device. The PEP supplied this handle in response to a previous [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification.

### `PowerControlCode` [in]

A pointer to a GUID value that specifies the power control operation that was performed. This is the same value that the PEP supplied in response to the [PEP_DPM_WORK](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-peps-for-acpi-services) notification to initiate the power control operation.

### `RequestContext` [in]

A pointer to the request context that was sent by the PEP in the [PEP_WORK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_information) structure that the PEP supplied in the original work request. Typically, this member points to a structure that contains a pointer to an output buffer to contain the results of the power control operation that was requested by the PEP.

### `BytesReturned` [in]

The size, in bytes, of the result data stored by the driver in the output buffer. For more information about this buffer, see the description of the **RequestContext** member.

### `Status` [in]

The status of the power control operation. If the operation was successful, the PEP sets this member to STATUS_SUCCESS. Otherwise, the PEP sets this member to an appropriate error status code.

## Remarks

This structure is used by the [PEP_DPM_POWER_CONTROL_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_power_control_complete) notification. All five members of the structure contain input values that are supplied by

If the output buffer is too small to receive all of the result data from the operation, the PEP sets the **Status** member of the structure to STATUS_INSUFFICIENT_RESOURCES, sets the **BytesReturned** member to the required size of the output buffer, and (typically) writes no data to the output buffer.

## See also

GUID