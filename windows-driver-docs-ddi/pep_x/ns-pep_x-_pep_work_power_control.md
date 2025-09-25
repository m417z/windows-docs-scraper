# _PEP_WORK_POWER_CONTROL structure (pep_x.h)

## Description

The **PEP_WORK_POWER_CONTROL** structure contains the parameters for a [power control request](https://learn.microsoft.com/windows-hardware/drivers/ddi/) that the platform extension plug-in (PEP) sends directly to a processor driver.

## Members

### `DeviceHandle`

A POHANDLE value that identifies the processor. The PEP received this handle in a previous [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification.

### `PowerControlCode` [in]

A pointer to a GUID value that specifies the power control operation to perform.

### `RequestContext`

A pointer to a PEP-defined context value. The PEP might use this value to uniquely identify a power control request message (in case the PEP issues multiple requests with the same control code to the same device).

### `InBuffer` [in]

A pointer to a driver-allocated input buffer that contains the input parameters for this power control operation.

### `InBufferSize` [in]

The size in bytes of the buffer pointed to by **InBuffer**.

### `OutBuffer` [in]

A pointer to a driver-allocated output buffer to which the PEP writes the results of this power control operation.

### `OutBufferSize` [in]

The size in bytes of the buffer pointed to by **OutBuffer**.

## Remarks

The **PowerControl** member of the [PEP_WORK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_information) structure is a pointer to a **PEP_WORK_POWER_CONTROL** structure.

The PEP issues a power control request from a worker thread. The Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) forwards this request by calling the processor driver's [PowerControlCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_power_control_callback) routine, if the driver implements this routine.

## See also

GUID

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)

[PEP_WORK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_information)

[PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice)

[PowerControlCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_power_control_callback)