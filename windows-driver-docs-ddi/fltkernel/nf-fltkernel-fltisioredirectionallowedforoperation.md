# FltIsIoRedirectionAllowedForOperation function

## Description

The **FltIsIoRedirectionAllowedForOperation** routine determines whether I/O can be redirected from the filter instance associated with the specified [FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure to the specified filter instance.

## Parameters

### `Data` [in]

An [FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure representing the I/O operation.

### `TargetInstance` [in]

A filter instance on the target device stack.

### `RedirectionAllowedThisIo` [out]

A value of **TRUE** if this I/O can be redirected to the target device stack by changing the filter instance referenced.

### `RedirectionAllowedAllIo` [out, optional]

This optional parameter has a value of **TRUE** if all I/O to the device stack to which the I/O operation is issued can be redirected to the target device by changing the filter instance referenced, otherwise **FALSE**.

## Return value

An NTSTATUS value of STATUS_SUCCESS for success or STATUS_NOT_SUPPORTED if the redirection is not supported.

## Remarks

An I/O operation is associated with a [FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure. That structure contains a reference to a **PFLT_IO_PARAMETER_BLOCK** object, which contains a reference to the FLT_INSTANCE of the minifilter associated with the I/O operation.

If *RedirectionAllowed* is **TRUE**, the minifilter can redirect I/O by changing that instance to a new target instance.

If *RedirectionAllowed* is **FALSE**, the minifilter needs to allocate a new callback data object to issue I/O on the target stack or call [FltAdjustDeviceStackSizeForIoRedirection](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltadjustdevicestacksizeforioredirection) to increase the size of the source device stack.

**Note** Minifilters should not modify the reference to the FLT_INSTANCE before verifying that redirection can be done this way. Use **FltIsIoRedirectionAllowedForOperation** or [FltIsIoRedirectionAllowed](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisioredirectionallowed).

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FLT_IO_PARAMETER_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_io_parameter_block)

[FltAdjustDeviceStackSizeForIoRedirection](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltadjustdevicestacksizeforioredirection)

[FltIsIoRedirectionAllowed](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisioredirectionallowed)