# FltRetrieveIoPriorityInfo function

## Description

The **FltRetrieveIoPriorityInfo** routine is used by a minifilter driver to retrieve priority information from a thread.

## Parameters

### `Data` [in, optional]

An optional pointer to a [**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure, which represents an I/O operation. This parameter can be **NULL**.

### `FileObject` [in, optional]

An optional pointer to the file object associated with the I/O operation. This parameter can be **NULL**.

### `Thread` [in, optional]

An optional pointer to the thread in which to retrieve priority information from. This parameter can be **NULL**.

### `PriorityInfo` [in, out]

A pointer to an [**IO_PRIORITY_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_io_priority_info) structure used to receive the priority information from the given thread. The IO_PRIORITY_INFO structure must be initialized by an appropriate routine before it can be used by this routine. See the following Remarks section for more information.

## Return value

The **FltRetrieveIoPriorityInfo** routine returns STATUS_SUCCESS or an appropriate NTSTATUS value.

## Remarks

The **FltRetrieveIoPriorityInfo** routine retrieves priority information and saves the information in the structure pointed to by the **PriorityInfo** parameter.

Typically, the **FltRetrieveIoPriorityInfo** routine is used in conjunction with the [**FltApplyPriorityInfoThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltapplypriorityinfothread) routine to save and then set a thread's I/O priority, paging priority, and thread priority.

If the **Thread** parameter is non-**NULL**, the thread's paging priority and thread priority will be retrieved and placed in the **PagePriority** and **ThreadPriority** members of the IO_PRIORITY_INFO structure pointed to by the **PriorityInfo** parameter. If the **Thread** parameter is **NULL**, the **ThreadPriority** and **PagePriority** members of the IO_PRIORITY_INFO structure are marked with sentinel values indicating that the thread's paging and thread priorities should not be changed by the system. Note that these sentinel values stay in effect until explicitly changed.

The following pseudo-code example describes what I/O priority value is retrieved and placed in the **IoPriority** member of the IO_PRIORITY_INFO structure pointed to by the **PriorityInfo** parameter.

```
Set the IoPriority member of the structure pointed to by the PriorityInfo parameter to the normal I/O priority value.
IF Data is not NULL and represents an IRP-based operation and has I/O priority information available THEN
    Set the IoPriority member of the structure pointed to by the PriorityInfo parameter to the Data's I/O priority value.
ELSE IF the FileObject parameter is not NULL and has I/O priority information available THEN
    Set the IoPriority member of the structure pointed to by the PriorityInfo parameter to the FileObject's I/O priority value.
ELSE IF the Thread parameter is not NULL THEN
    Set the IoPriority member of the structure pointed to by the PriorityInfo parameter to the Thread's I/O priority value.
```

> [!NOTE]
> If the IO_PRIORITY_INFO structure pointed to by the **PriorityInfo** parameter has not been initialized, you must do so prior to calling this routine, by calling the [**IoInitializePriorityInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioinitializepriorityinfo) routine.

## See also

[**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[**FltApplyPriorityInfoThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltapplypriorityinfothread)

[**FltGetIoPriorityHint**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhint)

[**FltGetIoPriorityHintFromCallbackData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhintfromcallbackdata)

[**FltGetIoPriorityHintFromFileObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhintfromfileobject)

[**FltGetIoPriorityHintFromThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhintfromthread)

[**FltRetrieveIoPriorityInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrieveiopriorityinfo)

[**FltSetIoPriorityHintIntoCallbackData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetiopriorityhintintocallbackdata)

[**FltSetIoPriorityHintIntoFileObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetiopriorityhintintofileobject)

[**FltSetIoPriorityHintIntoThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetiopriorityhintintothread)

[**IO_PRIORITY_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_io_priority_info)

[**IoInitializePriorityInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioinitializepriorityinfo)

[**PsGetCurrentThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthread)