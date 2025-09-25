# DrvFree function

## Description

The **DrvFree** function is used to notify the driver that the specified structure is no longer needed.

## Parameters

### `pv`

Pointer to the structure whose memory is to be freed.

### `id`

Pointer to the identifier that was returned with the structure.

## Remarks

**DrvFree** is an optional function that should be supported only if the driver must be informed when memory associated with structures can be freed. For example, if a [FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj) structure is in use, deletion can be deferred until [DrvDestroyFont](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvdestroyfont) has been called, eliminating the need for the driver to implement **DrvFree**.

A driver can use *id* in different ways. It can specify an object handle or it can indicate the way the structure is allocated. For example, it can differentiate between loaded resources and memory allocated from a heap. The driver can ignore this parameter if the structure pointed to by *pv* contains enough information.

## See also

[DrvDestroyFont](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvdestroyfont)

[DrvQueryFont](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvqueryfont)

[DrvQueryFontTree](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvqueryfonttree)