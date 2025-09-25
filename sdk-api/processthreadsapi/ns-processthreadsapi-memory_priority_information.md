# MEMORY_PRIORITY_INFORMATION structure

## Description

Specifies the memory priority for a thread or process. This structure is used by the [GetProcessInformation](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessinformation), [SetProcessInformation](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessinformation), [GetThreadInformation](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreadinformation), and [SetThreadInformation](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadinformation) functions.

## Members

### `MemoryPriority`

The memory priority for the thread or process. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **MEMORY_PRIORITY_VERY_LOW**<br><br>1 | Very low memory priority. |
| **MEMORY_PRIORITY_LOW**<br><br>2 | Low memory priority. |
| **MEMORY_PRIORITY_MEDIUM**<br><br>3 | Medium memory priority. |
| **MEMORY_PRIORITY_BELOW_NORMAL**<br><br>4 | Below normal memory priority. |
| **MEMORY_PRIORITY_NORMAL**<br><br>5 | Normal memory priority. This is the default priority for all threads and processes on the system. |

## Remarks

The memory priority of a thread or process serves as a hint to the memory manager when it trims pages from the working set. Other factors being equal, pages with lower memory priority are trimmed before pages with higher memory priority. For more information, see [Working Set](https://learn.microsoft.com/windows/desktop/Memory/working-set).

## See also

[GetProcessInformation](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessinformation)

[GetThreadInformation](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreadinformation)

[SetProcessInformation](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessinformation)

[SetThreadInformation](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadinformation)