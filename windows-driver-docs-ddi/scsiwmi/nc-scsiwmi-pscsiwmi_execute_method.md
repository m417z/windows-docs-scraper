# PSCSIWMI_EXECUTE_METHOD callback function

## Description

A miniport driver's **HwScsiWmiExecuteMethod** routine is called to execute a method associated with a data block. This routine is optional.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `DeviceContext` [in]

Points to the miniport driver-defined context value passed to [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction).

### `RequestContext` [in]

Points to the SCSIWMI_REQUEST_CONTEXT structure that the miniport driver passed to [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction).

### `GuidIndex` [in]

Specifies the data block by its index into the list of GUIDs in the SCSI_WMILIB_CONTEXT structure that the miniport driver passed to [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction).

### `InstanceIndex` [in]

If the block specified by *GuidIndex* has multiple instances, *InstanceIndex* specifies the instance.

### `MethodId` [in]

Specifies the ID of the method to execute. The miniport driver defines the method ID as an item in a data block.

### `InBufferSize` [in]

Indicates the size in bytes of the input data. If there is no input data, *InBufferSize* is zero.

### `OutBufferSize` [in]

Indicates the number of bytes available in the buffer for output data.

### `Buffer` [in, out]

Points to a buffer that holds the input data and receives the output data, if any, from the method. If the buffer is too small to receive all of the output, the miniport driver calls **ScsiPortWmiPostProcess** with SRB_STATUS_DATA_OVERRUN and the size required.

## Return value

**HwScsiWmiExecuteMethod** returns SRB_STATUS_PENDING if the request is pending, or a nonzero SRB status value if the request was completed. The SRB status value returned by this routine is the same as what was passed in to [ScsiPortWmiPostProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmipostprocess). Although the return value data type is BOOLEAN, the **HwScsiWmiExecuteMethod** routine actually returns an SRB status value.

## Remarks

When a miniport driver receives an SRB in which the **Function** member is set to SRB_FUNCTION_WMI, it calls [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction) with a pointer to an initialized SCSI_WMILIB_CONTEXT structure and *MinorFunction* set to **Srb->WmiSubFunction**. The SCSI port driver calls the miniport driver's **HwScsiWmiExecuteMethod** routine if *MinorFunction* indicates a request to execute a method.

If a miniport driver does not implement a **HwScsiWmiExecuteMethod** routine, it must set **ExecuteWmiMethod** to **NULL** in the SCSI_WMILIB_CONTEXT the miniport driver passes to [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction). In this case, the port driver returns SRB_STATUS_ERROR to the caller.

If the method generates output, the miniport driver should check the size of the output buffer in *OutBufferSize* before performing any operation that might have side effects or that should not be performed twice. For example, if a method returns the values of a group of counters and then resets the counters, the miniport driver should check the buffer size before resetting the counters. This ensures that the port driver can safely resend the request with a larger buffer. If the buffer is too small, the miniport driver should call [ScsiPortWmiPostProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmipostprocess) with SRB_STATUS_DATA_OVERRUN and the size of the output buffer needed to fulfill the request.

The miniport driver executes the method and writes output, if any, to the buffer. Before returning from **HwScsiWmiExecuteMethod**, the miniport driver calls [ScsiPortWmiPostProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmipostprocess) with an appropriate *SrbStatus* value and the number of bytes used in the output buffer.

## See also

[SCSIWMI_REQUEST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-scsiwmi_request_context)

[SCSI_WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-_scsiwmilib_context)

[ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction)

[ScsiPortWmiPostProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmipostprocess)