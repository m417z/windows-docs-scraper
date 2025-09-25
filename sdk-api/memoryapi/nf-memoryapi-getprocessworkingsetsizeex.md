# GetProcessWorkingSetSizeEx function

## Description

Retrieves the minimum and maximum working set sizes of the specified process.

## Parameters

### `hProcess` [in]

A handle to the process whose working set sizes will be obtained. The handle must have the **PROCESS_QUERY_INFORMATION** or **PROCESS_QUERY_LIMITED_INFORMATION** access right. For more information, see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

**Windows Server 2003:** The handle must have the **PROCESS_QUERY_INFORMATION** access right.

### `lpMinimumWorkingSetSize` [out]

A pointer to a variable that receives the minimum working set size of the specified process, in bytes. The virtual memory manager attempts to keep at least this much memory resident in the process whenever the process is active.

### `lpMaximumWorkingSetSize` [out]

A pointer to a variable that receives the maximum working set size of the specified process, in bytes. The virtual memory manager attempts to keep no more than this much memory resident in the process whenever the process is active when memory is in short supply.

### `Flags` [out]

The flags that control the enforcement of the minimum and maximum working set sizes.

| Value | Meaning |
| --- | --- |
| **QUOTA_LIMITS_HARDWS_MIN_DISABLE**<br><br>0x00000002 | The working set may fall below the minimum working set limit if memory demands are high. |
| **QUOTA_LIMITS_HARDWS_MIN_ENABLE**<br><br>0x00000001 | The working set will not fall below the minimum working set limit. |
| **QUOTA_LIMITS_HARDWS_MAX_DISABLE**<br><br>0x00000008 | The working set may exceed the maximum working set limit if there is abundant memory. |
| **QUOTA_LIMITS_HARDWS_MAX_ENABLE**<br><br>0x00000004 | The working set will not exceed the maximum working set limit. |

## Remarks

The "working set" of a process is the set of memory pages currently visible to the process in physical RAM memory. These pages are resident and available for an application to use without triggering a page fault. The minimum and maximum working set sizes affect the virtual memory paging behavior of a process.

## See also

[Process Working Set](https://learn.microsoft.com/windows/desktop/ProcThread/process-working-set)

[Processes](https://learn.microsoft.com/windows/desktop/ProcThread/child-processes)

[SetProcessWorkingSetSizeEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-setprocessworkingsetsizeex)