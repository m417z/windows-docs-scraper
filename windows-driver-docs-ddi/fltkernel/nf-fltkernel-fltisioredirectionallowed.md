# FltIsIoRedirectionAllowed function

## Description

The **FltIsIoRedirectionAllowed** routine determines whether I/O can be redirected from the specified source filter instance to another specified filter instance.

## Parameters

### `SourceInstance` [in]

The filter instance on the source device stack.

### `TargetInstance` [in]

The filter instance on the target device stack.

### `RedirectionAllowed` [out]

A value of **TRUE** if all I/O to the source device stack can be redirected to the target device stack by changing the filter instance referenced, otherwise **FALSE**.

## Return value

An NTSTATUS value of STATUS_SUCCESS for success or STATUS_NOT_SUPPORTED if redirection is not supported.

## Remarks

An I/O operation is associated with a [FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure. That structure contains a reference to a **PFLT_IO_PARAMETER_BLOCK** object, which contains a reference to the FLT_INSTANCE of the minifilter associated with the I/O operation.

If *RedirectionAllowed* is **TRUE**, the minifilter can redirect I/O by changing that instance to a new target instance.

If *RedirectionAllowed* is **FALSE**, the minifilter needs to allocate a new callback data object to issue I/O on the target stack or call [FltAdjustDeviceStackSizeForIoRedirection](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltadjustdevicestacksizeforioredirection) to increase the size of the source device stack.

**Note** Minifilters should not modify the reference to the FLT_INSTANCE before verifying that redirection can be done this way. Use [FltIsIoRedirectionAllowedForOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisioredirectionallowedforoperation) or **FltIsIoRedirectionAllowed**.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FLT_IO_PARAMETER_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_io_parameter_block)

[FltAdjustDeviceStackSizeForIoRedirection](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltadjustdevicestacksizeforioredirection)

[FltIsIoRedirectionAllowedForOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisioredirectionallowedforoperation)