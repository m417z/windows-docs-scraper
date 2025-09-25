# _FLT_RELATED_CONTEXTS structure

## Description

The **FLT_RELATED_CONTEXTS** structure contains a minifilter driver's contexts for the objects associated with an I/O operation.

## Members

### `VolumeContext`

Opaque pointer to the minifilter's context for the volume that the **Volume** member of the [FLT_RELATED_OBJECTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects) structure points to.

### `InstanceContext`

Opaque pointer to the minifilter driver's context for the instance that the **Instance** member of the [FLT_RELATED_OBJECTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects) structure points to.

### `FileContext`

On Windows Vista and later, this member is an opaque pointer to the minifilter driver's per-file context for the stream handle that the **FileObject** member of the [FLT_RELATED_OBJECTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects) structure points to. On Windows operating systems earlier than Windows Vista, this member is reserved for system use.

### `StreamContext`

Opaque pointer to the minifilter's stream context for the stream handle that the **FileObject** member of the [FLT_RELATED_OBJECTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects) structure points to.

### `StreamHandleContext`

Opaque pointer to the minifilter's stream handle context for the stream handle that the **FileObject** member of the [FLT_RELATED_OBJECTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects) structure points to.

### `TransactionContext`

On Windows Vista and later, this member is an opaque pointer to the minifilter's transaction context for the transaction that the **Transaction** member of the [FLT_RELATED_OBJECTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects) structure points to. On Windows operating systems earlier than Windows Vista, this member is reserved for system use.

## Remarks

The **FLT_RELATED_CONTEXTS** structure contains a minifilter driver's contexts for the objects associated with an I/O operation or an instance setup or teardown operation.

A minifilter driver uses the **FLT_RELATED_CONTEXTS** structure to retrieve multiple contexts for a given operation. To do so, the minifilter driver allocates an empty **FLT_RELATED_CONTEXTS** structure and passes a pointer to it as the *Contexts* parameter to [FltGetContexts](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetcontexts).

A minifilter can also use this structure to release multiple contexts for a given operation. To do so, the minifilter driver passes a pointer to **FLT_RELATED_CONTEXTS** as the *Contexts* parameter to [FltReleaseContexts](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontexts).

For more information about using contexts, see the reference entry for [FltAllocateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext).

## See also

[FLT_CONTEXT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_context_registration)

[FLT_RELATED_OBJECTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects)

[FltAllocateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[FltGetContexts](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetcontexts)

[FltReleaseContexts](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontexts)