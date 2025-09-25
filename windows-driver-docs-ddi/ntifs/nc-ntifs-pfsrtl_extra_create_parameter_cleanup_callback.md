# PFSRTL_EXTRA_CREATE_PARAMETER_CLEANUP_CALLBACK callback

## Description

A filter driver can register a PFSRTL_EXTRA_CREATE_PARAMETER_CLEANUP_CALLBACK-typed routine as the filter driver's *CleanupCallback* callback routine for an extra create parameter (ECP) context structure.

## Parameters

### `EcpContext` [in, out]

An ECP context pointer that was returned by the routine that allocated the ECP context structure.

### `EcpType` [in[]

A pointer to a GUID that was passed to the routine that allocated the ECP context structure, that indicates the extra create parameter type. For more information, see [Using GUIDs in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-guids-in-drivers).

## Remarks

When a filter driver allocates an ECP context structure, it can optionally specify a PFSRTL_EXTRA_CREATE_PARAMETER_CLEANUP_CALLBACK-typed routine as the filter driver's *CleanupCallback* callback routine. If the filter driver specifies a *CleanupCallback* callback routine, the operating system will invoke the *CleanupCallback* routine (regardless of IRQ level). This *CleanupCallback* routine performs any necessary ECP context-related cleanup processing when the ECP context structure is deleted.

To specify a callback routine, a filter driver passes a pointer to the callback routine by using the *CleanupCallback* parameter of the routine that originally allocated the ECP context structure. If a callback routine is not needed, a **NULL** value must be passed to the *CleanupCallback* parameter.

The following routines support the PFSRTL_EXTRA_CREATE_PARAMETER_CLEANUP_CALLBACK-typed callback routine:

* [**FltAllocateExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameter)
* [**FltAllocateExtraCreateParameterFromLookasideList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameterfromlookasidelist)
* [**FsRtlAllocateExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlallocateextracreateparameter)

## See also

[**ECP_LIST**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85))

[**FltAllocateExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameter)

[**FltAllocateExtraCreateParameterFromLookasideList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameterfromlookasidelist)

[**FltAllocateExtraCreateParameterList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameterlist)

[**FltFreeExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameter)

[**FltFreeExtraCreateParameterList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameterlist)

[**FltRemoveExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltremoveextracreateparameter)