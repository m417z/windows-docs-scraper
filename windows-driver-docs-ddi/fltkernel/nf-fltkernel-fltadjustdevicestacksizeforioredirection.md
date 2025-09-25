# FltAdjustDeviceStackSizeForIoRedirection function

## Description

The **FltAdjustDeviceStackSizeForIoRedirection** routine increases the size of the source device stack to allow a minifilter to redirect I/O from a specified source instance to a specified target instance when the target stack is deeper than the source stack.

## Parameters

### `SourceInstance` [in]

The filter instance on the source device stack.

### `TargetInstance` [in]

The filter instance on the target device stack.

### `SourceDeviceStackSizeModified` [out, optional]

This optional parameter has a value of **TRUE** if the **FltAdjustDeviceStackSizeForIoRedirection** routine modified the size of the source device stack, **FALSE** otherwise.

## Return value

| Return value | Description |
| --- | --- |
| STATUS_SUCCESS | Success. |
| STATUS_NOT_SUPPORTED | The redirection is not supported. |
| STATUS_INVALID_PARAMETER | The source device stack would be too large after calling this routine. |

## Remarks

Using **FltAdjustDeviceStackSizeForIoRedirection** does not guarantee that every IRP that the minifilter encounters will be sufficient in size to be redirected to the target stack. IRPs that were allocated and issued before the call to **FltAdjustDeviceStackSizeForIoRedirection** would still have been allocated based on the old stack size.

A minifilter can adjust the stack size during instance setup if the filter knows which stack the I/O will be redirected to.

The filter can issue its own create operation down the new stack using [FltCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefile). Before completing the create operation, the filter can adjust the stack size to account for the target stack. Doing that adjustment ensures that the stack size will be adjusted before the create action is completed. All IRPs allocated for that file object will have a large enough stack to support redirection.

During instance-setup or during post-create callback for a redirected file object, use [FltIsIoRedirectionAllowed](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisioredirectionallowed) to determine if redirection is possible without modifying the source stack. If necessary, use **FltAdjustDeviceStackSizeForIoRedirection** to adjust the source stack.

In the pre-operation callback for every operation that needs redirection, use [FltIsIoRedirectionAllowedForOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisioredirectionallowedforoperation) to determine if redirection is possible without modifying the source stack. If necessary, use **FltAdjustDeviceStackSizeForIoRedirection** to adjust the source stack.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FLT_IO_PARAMETER_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_io_parameter_block)

[FltIsIoRedirectionAllowed](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisioredirectionallowed)

[FltIsIoRedirectionAllowedForOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisioredirectionallowedforoperation)

[PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)