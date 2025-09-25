# FltAllocateCallbackData function

## Description

**FltAllocateCallbackData** allocates a callback data structure that a minifilter driver can use to initiate an I/O request.

## Parameters

### `Instance` [in]

Opaque instance pointer for the minifilter driver instance that is initiating the I/O operation. This parameter is required and cannot be **NULL**.

### `FileObject` [in, optional]

File object pointer to be used in the I/O operation. This parameter is optional and can be **NULL**.

### `RetNewCallbackData` [out]

Pointer to a caller-allocated variable that receives the address of the newly allocated callback data ([FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure.

## Return value

**FltAllocateCallbackData** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as the following:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | [FltAllocateCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecallbackdata) encountered a pool allocation failure when attempting to allocate the callback data structure. This is an error code. |

## Remarks

A minifilter driver can call **FltAllocateCallbackData** to allocate a callback data ([FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure for an I/O operation initiated by the minifilter driver.

**Note** The **FltAllocateCallbackData** routine does not allocate all the memory that might be required by a subsequent I/O request. If an I/O request, such as [FltPerformSynchronousIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltperformsynchronousio) or [FltPerformAsynchronousIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltperformasynchronousio), requires additional memory for some structure, the request could encounter a memory allocation. The [FltAllocateCallbackDataEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecallbackdataex) routine can be used to avoid this potential problem by preallocating memory for additional structures to be used in an I/O request. If there is a memory allocation problem for either the *RetNewCallbackData* structure or additional required structures, it can be dealt with at the point of callback data allocation.

Callback data structures are allocated from nonpaged pool.

After initializing the parameters of the callback data structure returned by **FltAllocateCallbackData**, the caller initiates the I/O operation by passing the structure to [FltPerformSynchronousIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltperformsynchronousio) or [FltPerformAsynchronousIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltperformasynchronousio). These routines send the I/O operation only to the minifilter driver instances attached below the initiating instance (specified in the *Instance* parameter) and to the file system. Minifilter drivers attached above the specified instance do not receive the I/O operation.

Minifilter drivers can only initiate IRP-based I/O operations. They cannot initiate fast I/O or file system filter (FSFilter) callback operations.

Minifilter drivers should use **FltAllocateCallbackData**, [FltPerformAsynchronousIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltperformasynchronousio), and [FltPerformSynchronousIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltperformsynchronousio) only for I/O operations for which routines such as the following cannot be used:

[FltClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltclose)

[FltCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefile)

[FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation)

[FltReadFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreadfile)

[FltSetVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetvolumeinformation)

[FltTagFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flttagfile)

[FltUntagFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltuntagfile)

[FltWriteFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltwritefile)

When the callback data structure allocated by **FltAllocateCallbackData** is no longer needed, the caller is responsible for freeing it by calling [FltFreeCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreecallbackdata).

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FltClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltclose)

[FltCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefile)

[FltFreeCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreecallbackdata)

[FltPerformAsynchronousIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltperformasynchronousio)

[FltPerformSynchronousIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltperformsynchronousio)

[FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation)

[FltReadFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreadfile)

[FltReissueSynchronousIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreissuesynchronousio)

[FltReuseCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreusecallbackdata)

[FltSetVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetvolumeinformation)

[FltTagFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flttagfile)

[FltUntagFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltuntagfile)

[FltWriteFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltwritefile)