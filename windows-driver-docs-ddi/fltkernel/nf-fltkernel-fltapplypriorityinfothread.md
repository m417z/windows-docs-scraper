# FltApplyPriorityInfoThread function

## Description

The **FltApplyPriorityInfoThread** routine is used by a minifilter driver to apply priority information to a thread.

## Parameters

### `InputPriorityInfo` [in]

A pointer to an [IO_PRIORITY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_io_priority_info) structure that is used to set the priority state of the given thread. This IO_PRIORITY_INFO structure must have its members set by an appropriate routine - see the following Remarks section. This parameter is required and cannot be **NULL**.

### `OutputPriorityInfo` [out, optional]

An optional pointer to an IO_PRIORITY_INFO structure used to receive the priority state of the thread before the *InputPriorityInfo* priority information is applied to the thread by **FltApplyPriorityInfoThread**. This parameter is optional and can be **NULL**.

### `Thread` [in]

A pointer to the thread in which to apply the *InputPriorityInfo* priority information to. This parameter is required and cannot be **NULL**.

## Return value

If the thread priority information, pointed to by the *InputPriorityInfo* parameter, is successfully applied to the given thread, the **FltApplyPriorityInfoThread** routine returns STATUS_SUCCESS. Otherwise, it returns an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER_1** | The structure pointed to by the *InputPriorityInfo* parameter was initialized but one or more of its member values are invalid. This is an error code. |

## Remarks

This routine is available starting with Windows Vista.

The **FltApplyPriorityInfoThread** routine sets the I/O priority, paging priority and thread priority of the given thread based on the member values of the IO_PRIORITY_INFO structure pointed to by the *InputPriorityInfo* parameter. This allows a previously saved set of priority information, acquired by the [FltRetrieveIoPriorityInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrieveiopriorityinfo) or **FltApplyPriorityInfoThread** routine, to be applied to a thread.

The original values of the target thread, before the *InputPriorityInfo* priority values are applied by the **FltApplyPriorityInfoThread** routine, can be saved if a valid *OutputPriorityInfo* pointer is supplied. Note that the structure pointed to by the *OutputPriorityInfo* parameter need not be initialized.

It is safe to provide the same pointer to a single IO_PRIORITY_INFO structure for both the *InputPriorityInfo* and *OutputPriorityInfo* parameters.

**Note** If the member values of the IO_PRIORITY_INFO structure pointed to by the *InputPriorityInfo* parameter have not been set, you must set these members, prior to calling the **FltApplyPriorityInfoThread** routine, by using one of the following methods:

* Call the [FltRetrieveIoPriorityInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrieveiopriorityinfo) routine.
* Ensure that the current *InputPriorityInfo* parameter was the *OutputPriorityInfo* parameter in a prior call to the **FltApplyPriorityInfoThread** routine.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FltGetIoPriorityHint](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhint)

[FltGetIoPriorityHintFromCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhintfromcallbackdata)

[FltGetIoPriorityHintFromFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhintfromfileobject)

[FltGetIoPriorityHintFromThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhintfromthread)

[FltRetrieveIoPriorityInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrieveiopriorityinfo)

[FltSetIoPriorityHintIntoCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetiopriorityhintintocallbackdata)

[FltSetIoPriorityHintIntoFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetiopriorityhintintofileobject)

[FltSetIoPriorityHintIntoThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetiopriorityhintintothread)

[IO_PRIORITY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_io_priority_info)