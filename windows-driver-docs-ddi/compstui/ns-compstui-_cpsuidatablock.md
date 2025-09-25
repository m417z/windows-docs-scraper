## Description

The **CPSUIDATABLOCK** structure is used as a parameter for the [ComPropSheet](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfncompropsheet) function, if the function code is [CPSFUNC_SET_DATABLOCK](https://learn.microsoft.com/previous-versions/ff547036(v=vs.85)) or [CPSFUNC_QUERY_DATABLOCK](https://learn.microsoft.com/previous-versions/ff546425(v=vs.85)).

## Members

### `cbData`

Size, in bytes of the buffer pointed to by **pbData**.

### `pbData`

Pointer to a caller-allocated buffer.