# StorPortPoFxPowerControl function

## Description

The **StorPortPoFxPowerControl** routine sends a power control request to the power management framework (PoFx) to forward to the power engine plug-in (PEP).

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA). This is the device extension used to register the device in a prior call to [StorPortInitializePoFxPower](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializepofxpower).

### `Address`

A pointer to the power control code. This code is a GUID value that specifies the requested operation.

### `PowerControlCode` [in]

A pointer to the power control code. This code is a GUID value that specifies the requested operation.

### `InBuffer` [in, optional]

A pointer to a caller-allocated buffer that contains the input data for the operation. The format for the data in this buffer depends on the power control code specified by the *PowerControlCode* parameter. The *InBuffer* parameter is optional and can be specified as NULL if the specified operation requires no input data.

### `InBufferSize` [in]

The size, in bytes, of the input buffer that is pointed to by the *InBuffer* parameter. If *InBuffer* is NULL, set *InBufferSize* to zero.

### `OutBuffer` [out, optional]

A pointer to a caller-allocated buffer that is to contain the output data from the operation. The format for the data in this buffer depends on the power control code specified by the *PowerControlCode* parameter. The *OutBuffer* parameter is optional and can be specified as NULL if the specified operation produces no output data.

### `OutBufferSize` [in]

The size, in bytes, of the output buffer that is pointed to by the *OutBuffer* parameter. If *OutBuffer* is NULL, set *OutBufferSize* to zero.

### `BytesReturned` [out, optional]

A pointer to a location into which the routine writes the number of bytes of data that were written to the buffer that is pointed to by *OutBuffer*. The number of bytes written will be less than or equal to *OutBufferSize*. This parameter is optional and can be specified as **NULL** if the caller does not need to know how many bytes were written to the output buffer.

## Return value

The **StorPortPoFxPowerControl** routine returns one of these status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_SUCCESS** | The power control operation specified in *PowerControlCode* was successfully executed. |
| **STOR_STATUS_INVALID_PARAMETER** | Either *HwDeviceExtension* or *Device* is NULL.<br><br>-or-<br><br>*Address* points to an invalid unit address structure.<br><br>-or-<br><br>The storage device specified by *Address* is not found. |
| **STOR_STATUS_INVALID_DEVICE_REQUEST** | The storage device is not registered with the PoFx. |
| **STOR_STATUS_INVALID_IRQL** | The current IRQL > DISPATCH_LEVEL. |
| **STOR_STATUS_UNSUCCESSFUL** | The power control operation was unsuccessful. |

## Remarks

A miniport driver calls this routine to send a power control request directly to the PEP. A power control request is similar to an I/O control request (IOCTL). Unlike an IOCTL, however, a power control request is sent directly to PEP and is not observed by other device drivers in the device stack. During a **StorPortPoFxPowerControl** call, the PEP synchronously performs the requested operation.

Similarly, The PEP can send a power control request directly to the miniport. The miniport driver handles this request in its [HwStorAdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) and [HwStorUnitControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) routines. The *ControlType* parameter receives the **ScsiAdapterPoFxPowerControl** type in the **HwStorAdapterControl** routine and the **ScsiUnitPoFxPowerControl** in the **HwStorUnitControl** routine.

## See also

[HwStorAdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control)

[HwStorUnitControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control)