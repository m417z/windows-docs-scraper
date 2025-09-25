# ClfsDeleteMarshallingArea function

## Description

The **ClfsDeleteMarshallingArea** routine deletes a marshalling area.

## Parameters

### `pvMarshalContext` [in]

A pointer to an opaque context that represents a marshalling area. The caller previously obtained this pointer by calling [ClfsCreateMarshallingArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatemarshallingarea).

## Return value

**ClfsDeleteMarshallingArea** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

Before deleting the marshalling area, **ClfsDeleteMarshallingArea** flushes all of the log I/O blocks associated with the marshalling area.

The marshalling area goes away only after all references to it go away. For example, the marshalling area remains in memory if it still has an open read context.

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsCreateMarshallingArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatemarshallingarea)