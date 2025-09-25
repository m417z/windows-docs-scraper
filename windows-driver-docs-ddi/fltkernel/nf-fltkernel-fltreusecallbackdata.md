# FltReuseCallbackData function

## Description

The **FltReuseCallbackData** routine reinitializes a callback data structure so that it can be reused.

## Parameters

### `CallbackData` [in, out]

Pointer to the callback data ([FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure to be reused. This structure must have been allocated by a previous call to [FltAllocateCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecallbackdata). This parameter is required and cannot be **NULL**.

## Return value

None

## Remarks

**FltReuseCallbackData** reinitializes a callback data ([FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure so that it can be used in a new I/O operation. **FltReuseCallbackData** does not change the **TargetInstance** field or the **TargetFileObject** field of the callback data structure's I/O parameter block.

The **FltReuseCallbackData** routine frees any [MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) chain associated with the supplied *CallbackData* object. A pointer to an MDL chain associated with a [FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) object will be invalid after a call to **FltReuseCallbackData** for that object.

Using **FltReuseCallbackData** to reuse a callback data structure is faster than freeing the structure and allocating a new one.

A minifilter driver should use **FltReuseCallbackData** only on a callback data structure that the minifilter driver previously allocated with [FltAllocateCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecallbackdata) and used in a call to [FltPerformSynchronousIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltperformsynchronousio) or [FltPerformAsynchronousIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltperformasynchronousio).

If the callback data structure was used for asynchronous I/O, the minifilter driver should not call **FltReuseCallbackData** until the *CallbackRoutine* specified in the call to [FltPerformAsynchronousIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltperformasynchronousio) is called.

In particular, a minifilter driver should not use this routine for any callback data structures not allocated by the minifilter driver itself.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FltAllocateCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecallbackdata)

[FltFreeCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreecallbackdata)

[FltPerformAsynchronousIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltperformasynchronousio)

[FltPerformSynchronousIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltperformsynchronousio)

[FltReissueSynchronousIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreissuesynchronousio)