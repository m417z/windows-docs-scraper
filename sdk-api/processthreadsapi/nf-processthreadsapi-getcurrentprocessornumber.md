# GetCurrentProcessorNumber function

## Description

Retrieves the number of the processor the current thread was running on during the call to this function.

## Return value

The function returns the current processor number.

## Remarks

This function is used to provide information for estimating process performance.

On systems with more than 64 logical processors, the **GetCurrentProcessorNumber** function returns the processor number within the [processor group](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups) to which the logical processor is assigned. Use the [GetCurrentProcessorNumberEx](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentprocessornumberex) function to retrieve the processor group and number of the current processor.

## See also

[Multiple Processors](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-processors)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Processes](https://learn.microsoft.com/windows/desktop/ProcThread/child-processes)