# FltObjectDereference function

## Description

The **FltObjectDereference** routine removes a rundown reference from an opaque filter, instance, or volume pointer.

## Parameters

### `FltObject` [in, out]

Opaque filter pointer (PFLT_FILTER), instance pointer (PFLT_INSTANCE), or volume pointer (PFLT_VOLUME).

## Return value

None

## Remarks

To add a rundown reference to an opaque filter, instance, or volume pointer, call [FltObjectReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectreference).

## See also

[FltObjectReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectreference)