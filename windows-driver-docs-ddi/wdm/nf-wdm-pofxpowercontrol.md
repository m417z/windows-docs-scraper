# PoFxPowerControl function

## Description

The **PoFxPowerControl** routine sends a power control request to the power management framework (PoFx).

## Parameters

### `Handle` [in]

A handle that represents the registration of the device with PoFx. The device driver previously received this handle from the [PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) routine.

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

**PoFxPowerControl** returns **STATUS_SUCCESS** if the requested operation succeeds. Possible error return values include the following status code.

| Return code | Description |
| --- | --- |
| **STATUS_NOT_IMPLEMENTED** | The requested power control operation is not implemented. |
| **STATUS_NOT_SUPPORTED** | The power engine plug-in (PEP) does not acknowledge support for this device. |

## Remarks

A device driver calls this routine to send a power control request directly to PoFx. A power control request is similar to an I/O control request (IOCTL). Unlike an IOCTL, however, a power control request is sent directly to PoFx and is not observed by other device drivers in the device stack. During a **PoFxPowerControl** call, PoFx synchronously performs the requested operation.

Similarly, PoFx can send a power control request directly to the device driver. The driver handles this request in its [PowerControlCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_power_control_callback) routine.

PoFx delegates the handling of all power control requests to the power engine plug-in (PEP). The PEP is an optional software component that performs power management tasks that are specific to a particular product line of processor or System on a Chip (SoC) modules. If the hardware vendor for the processor or SoC supplies a PEP for a hardware platform, this PEP might handle custom power control requests from a device driver, or might send custom power control requests to the driver's *PowerControlCallback* routine. The vendor can specify a set of *PowerControlCode* GUIDs and define the operations that are designated by these GUIDs. As an option, a device driver can contain platform-specific code to handle or to send requests for these operations.

## See also

[PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice)

[PowerControlCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_power_control_callback)