# FltAllocateCallbackDataEx function

## Description

The **FltAllocateCallbackDataEx** routine allocates a callback data structure and can preallocate memory for additional structures that a minifilter driver can use to initiate an I/O request.

## Parameters

### `Instance` [in]

Opaque instance pointer to the minifilter driver instance that is initiating the I/O operation. This parameter is required and cannot be **NULL**.

### `FileObject` [in/optional]

Pointer to a file object to be used in the I/O operation. This parameter is optional and can be **NULL**. Set **FileObject** to **NULL** if this is a CREATE operation.

### `Flags` [in]

A value of zero or the following flag: FLT_ALLOCATE_CALLBACK_DATA_PREALLOCATE_ALL_MEMORY

If this flag is set, the routine preallocates all the memory needed by the filter manager for additional structures to be used in an I/O request.

### `RetNewCallbackData` [out]

Pointer to a caller-allocated variable that receives the address of the newly allocated callback data [**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure.

## Return value

The **FltAllocateCallbackDataEx** routine returns STATUS_SUCCESS on success or STATUS_INSUFFICIENT_RESOURCES if the routine encountered a pool allocation failure when attempting to allocate the callback data structure or if the FLT_ALLOCATE_CALLBACK_DATA_PREALLOCATE_ALL_MEMORY flag is set and additional memory could not be allocated.

## Remarks

If the FLT_ALLOCATE_CALLBACK_DATA_PREALLOCATE_ALL_MEMORY flag is set, the routine allocates all the memory needed for additional filter manager structures to be used in a subsequent I/O request. Using this flag enables a minifilter to preallocate one or more callback data structures to be used for issuing I/O requests under low memory conditions or in situations where recovering from a memory allocation failure might be complicated.

> [!NOTE]
> The additional allocated memory is for use by the filter manager. The file system or other filters can still fail the I/O request due to an out-of-memory condition.

> [!IMPORTANT]
> The comments for [**FltAllocateCallbackData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecallbackdata) apply to **FltAllocateCallbackDataEx** as well. Review that information in order to select the correct routine for your design.

## See also

[**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[**FltAllocateCallbackData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecallbackdata)