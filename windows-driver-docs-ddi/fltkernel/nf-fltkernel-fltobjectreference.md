# FltObjectReference function

## Description

The **FltObjectReference** routine adds a rundown reference to an opaque filter, instance, or volume pointer.

## Parameters

### `FltObject` [in, out]

Opaque filter pointer (PFLT_FILTER), instance pointer (PFLT_INSTANCE), or volume pointer (PFLT_VOLUME).

## Return value

**FltObjectReference** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as the following:

| Return code | Description |
| --- | --- |
| **STATUS_FLT_DELETING_OBJECT** | The minifilter driver, instance, or volume is being torn down. This is an error code. |

## Remarks

Adding a rundown reference to an opaque filter, instance, or volume object pointer prevents the object from being freed.

To remove a rundown reference from an opaque filter, instance, or volume pointer, call [FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference).

## See also

[FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference)