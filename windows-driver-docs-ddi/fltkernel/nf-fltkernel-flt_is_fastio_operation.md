## Description

The **FLT_IS_FASTIO_OPERATION** macro determines whether the given callback data structure represents a fast I/O operation.

## Parameters

### `Data` [in]

A pointer to a callback data ([**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure.

## Remarks

The **FLT_IS_FASTIO_OPERATION** macro checks whether the FLTFL_CALLBACK_DATA_FAST_IO_OPERATION operation bit is set in the **Flags** member of the [**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure that the **Data** parameter points to. Thus, the return type of this macro is of the same type as the **Flags** member.

This macro returns one of the following values.

| Value | Meaning |
| ----- | ------- |
| Nonzero | The FLTFL_CALLBACK_DATA_FAST_IO_OPERATION bit is set in the callback data structure. |
| 0 | The FLTFL_CALLBACK_DATA_FAST_IO_OPERATION bit is not set in the callback data structure. |

## See also

[**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)