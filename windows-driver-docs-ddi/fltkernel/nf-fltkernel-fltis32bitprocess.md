# FltIs32bitProcess function

## Description

The **FltIs32bitProcess** routine checks whether the originator of the current I/O operation is a 32-bit user-mode application.

## Parameters

### `CallbackData` [in, optional]

Pointer to the callback data structure for the current I/O operation ([**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)). This parameter is optional and can be **NULL**.

## Return value

**FltIs32bitProcess** returns **TRUE** if the originator of the current I/O operation is a 32-bit user-mode process, **FALSE** otherwise.

## Remarks

Minifilter drivers call **FltIs32bitProcess** to determine whether an I/O request is likely to contain data elements that need to be converted, or "thunked," before they can be used in a 64-bit driver. For more information about thunking and other 64-bit driver issues, see [Programming Issues for 64-Bit Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/programming-issues-for-64-bit-drivers).

On a 32-bit system, **FltIs32bitProcess** always returns **TRUE**.

On a 64-bit system, **FltIs32bitProcess** returns **TRUE** or **FALSE**, according to the following conditions:

* If the **CallbackData** parameter is **NULL**, and the caller is running in the context of a 32-bit user-mode process, **FltIs32bitProcess** returns **TRUE**.

* If the **CallbackData** parameter is not **NULL**, and the callback data structure represents an IRP-based I/O operation where IRP was issued by the I/O manager on behalf of a user-mode process, **FltIs32bitProcess** returns **TRUE**.

* If the **CallbackData** parameter is not **NULL**, the callback data structure represents a fast I/O operation or a file system filter (FSFilter) callback operation, and the caller is running in the context of a 32-bit user-mode process, **FltIs32bitProcess** returns **TRUE**.

* If none of the above conditions is **true**, **FltIs32bitProcess** returns **FALSE**.

To determine whether a callback data structure represents an IRP-based I/O operation, use the [**FLT_IS_IRP_OPERATION**](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85)) macro.

To determine whether a callback data structure represents a fast I/O operation, use the [**FLT_IS_FASTIO_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_fastio_operation) macro.

To determine whether a callback data structure represents a file system filter (FSFilter) callback operation, use the [**FLT_IS_FS_FILTER_OPERATION**](https://learn.microsoft.com/previous-versions/ff544648(v=vs.85)) macro.

## See also

[**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[**FLT_IS_FASTIO_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_fastio_operation)

[**FLT_IS_FS_FILTER_OPERATION**](https://learn.microsoft.com/previous-versions/ff544648(v=vs.85))

[**FLT_IS_IRP_OPERATION**](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85))

[**IoIs32bitProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iois32bitprocess)