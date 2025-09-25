# PERFLIBREQUEST callback function

## Description

Providers can implement this function to receive notification when consumers perform certain actions, such as adding or removing counters from a query.
PERFLIB calls the callback before the consumer's request completes.

The **PERFLIBREQUEST** type defines a pointer to this callback function. The **ControlCallback** function is a placeholder for the application-defined function name.

## Parameters

### `RequestCode` [in]

The request code can be one of the following values.

| Value | Meaning |
| --- | --- |
| ****PERF_ADD_COUNTER**** | The consumer is adding a counter to the query. PERFLIB calls the callback with this request code for each counter being added to the query. The *Buffer* parameter contains a [PERF_COUNTER_IDENTITY](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_identity) structure that identifies the counter being added.<br><br>Providers can use this notification to start counting. |
| ****PERF_REMOVE_COUNTER**** | The consumer is removing a counter from the query. PERFLIB calls the callback with this request code for each counter being removed from the query. The *Buffer* parameter contains a [PERF_COUNTER_IDENTITY](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_identity) structure that identifies the counter being removed.<br><br>Providers can use this notification to stop counting. |
| ****PERF_ENUM_INSTANCES**** | The consumer is enumerating instances of the counter set. The *Buffer* parameter contains a null-terminated Unicode string that identifies the name of the computer (or its IP address) from which the consumer is enumerating the instances. |
| ****PERF_COLLECT_START**** | The consumer is beginning to collect counter data. The *Buffer* parameter contains a null-terminated Unicode string that identifies the name of the computer (or its IP address) from which the consumer is collecting data.<br><br>Providers can use this notification if the raw data state is critical (for example, transaction-related counters where partial updates are not allowed). This notification gives the provider a chance to flush all pending updates and lock future updates before collection begins. |
| ****PERF_COLLECT_END**** | The counter data collection is complete. The *Buffer* parameter contains a null-terminated Unicode string that identifies the name of the computer (or its IP address) from which the consumer collected data.<br><br>Providers can use this notification to release the update lock imposed by the collection start notification so that updates to the counter data can resume. |

### `Buffer` [in]

The contents of the buffer depends on the request. For possible content, see the *RequestCode* parameter.

### `BufferSize` [in]

Size, in bytes, of the *Buffer* parameter.

## Return value

Return ERROR_SUCCESS if the callback succeeds.

If the callback fails, PERFLIB will return the error code to the consumer if the request is **PERF_ADD_COUNTER**, **PERF_ENUM_INSTANCES**, or **PERF_COLLECT_START**; otherwise, the error code is ignored.

## Remarks

If the **callback** attribute of the [provider](https://learn.microsoft.com/previous-versions/aa373164(v=vs.85)) element is "custom" or you used the **-NotificationCallback** argument when calling [CTRPP](https://learn.microsoft.com/windows/desktop/PerfCtrs/ctrpp), you must implement this function. You pass the name of your callback function to [CounterInitialize](https://learn.microsoft.com/windows/desktop/PerfCtrs/counterinitialize).

**Windows Vista:** The [CounterInitialize](https://learn.microsoft.com/windows/desktop/PerfCtrs/counterinitialize) function is named **PerfAutoInitialize**. The [CTRPP](https://learn.microsoft.com/windows/desktop/PerfCtrs/ctrpp) tool also generates a skeleton of this callback for you that includes all the request codes. You then add code to the request codes that you want to support and remove the others.

The callback must complete within one second. If the callback does not complete in time, PERFLIB continues with the consumer's request and ignores the callback's return value when it completes.

#### Examples

The following example shows a simple implementation of a
[ControlCallback](https://learn.microsoft.com/windows/desktop/ETW/controlcallback) function.

```cpp
ULONG MyControlCallback(ULONG RequestCode, PVOID pBuffer, ULONG* pBufferSize)
{
    ULONG Status = ERROR_SUCCESS;
    PWNODE_HEADER Wnode = (PWNODE_HEADER)pBuffer;
    LPWSTR pComputerName = NULL;
    LPWSTR pInstance = NULL;
    PPERF_COUNTER_IDENTITY pCounter;
    UNREFERENCED_PARAMETER(pBufferSize);

    switch (RequestCode)
    {
        case PERF_ADD_COUNTER:
            pCounter = (PPERF_COUNTER_IDENTITY)(((LPBYTE) Wnode) + sizeof(WNODE_HEADER));
            pComputerName = (LPWSTR)(((LPBYTE) pCounter) + pCounter->MachineOffset);
            pInstance = (pCounter->NameOffset > 0)
                ? (LPWSTR) (((LPBYTE) pCounter) + pCounter->NameOffset) : NULL;

            break;

        case PERF_REMOVE_COUNTER:
            pCounter = (PPERF_COUNTER_IDENTITY)(((LPBYTE) Wnode) + sizeof(WNODE_HEADER));
            pComputerName = (LPWSTR)(((LPBYTE) pCounter) + pCounter->MachineOffset);
            pInstance = (pCounter->NameOffset > 0)
                ? (LPWSTR) (((LPBYTE) pCounter) + pCounter->NameOffset) : NULL;

            break;

        case PERF_ENUM_INSTANCES:
            pComputerName = (LPWSTR) (((LPBYTE) Wnode) + sizeof(WNODE_HEADER));

            break;

        case PERF_COLLECT_START:
            pComputerName = (LPWSTR) (((LPBYTE) Wnode) + sizeof(WNODE_HEADER));

            break;

        case PERF_COLLECT_END:
            pComputerName = (LPWSTR) (((LPBYTE) Wnode) + sizeof(WNODE_HEADER));

            break;

        default:
            wprintf(L"Unknown request code, %lu\n", RequestCode);
    }

    return Status;
}

```