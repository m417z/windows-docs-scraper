# PdhCollectQueryDataEx function

## Description

Uses a separate thread to collect the current raw data value for all counters in the specified query. The function then signals the application-defined event and waits the specified time interval before returning.

## Parameters

### `hQuery` [in]

Handle of the query. The query identifies the counters that you want to collect. The
[PdhOpenQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenquerya) function returns this handle.

### `dwIntervalTime` [in]

Time interval to wait, in seconds.

### `hNewDataEvent` [in]

Handle to the event that you want PDH to signal after the time interval expires. To create an event object, call the
[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) function.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_INVALID_HANDLE** | The query handle is not valid. |
| **PDH_NO_DATA** | The query does not currently have any counters. |

## Remarks

PDH terminates the thread when you call the [PdhCloseQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhclosequery) function. If you call **PdhCollectQueryDataEx** more than once, each subsequent call terminates the thread from the previous call and then starts a new thread.

When
**PdhCollectQueryDataEx** is called for data from one counter instance only and the counter instance does not exist, the function returns PDH_NO_DATA. However, if data from more than one counter is queried,
**PdhCollectQueryDataEx** may return ERROR_SUCCESS even if one of the counter instances does not yet exist. This is because it is not known if the specified counter instance does not exist, or if it will exist but has not yet been created. In this case, call
[PdhGetRawCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetrawcountervalue) or
[PdhGetFormattedCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetformattedcountervalue) for each of the counter instances of interest to determine whether they exist.

PDH stores the raw counter values for the current and previous collection. If you want to retrieve the current raw counter value, call the [PdhGetRawCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetrawcountervalue) function. If you want to compute a displayable value for the counter value, call the [PdhGetFormattedCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetformattedcountervalue). If the counter path contains a wildcard for the instance name, instead call the [PdhGetRawCounterArray](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetrawcounterarraya) and [PdhGetFormattedCounterArray](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetformattedcounterarraya) functions, respectively.

#### Examples

The following example shows how to use this function.

```cpp

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <pdh.h>

#pragma comment(lib, "pdh.lib")

CONST PWSTR COUNTER_NAME    = L"\\Processor(0)\\% Processor Time";
CONST ULONG SAMPLE_COUNT    = 10;
CONST ULONG SAMPLE_INTERVAL = 2;

void wmain(void)
{
    PDH_STATUS Status;
    HANDLE Event = NULL;
    PDH_HQUERY Query = NULL;
    PDH_HCOUNTER Counter;
    ULONG WaitResult;
    ULONG CounterType;
    PDH_FMT_COUNTERVALUE DisplayValue;

    Status = PdhOpenQuery(NULL, 0, &Query);
    if (Status != ERROR_SUCCESS)
    {
        wprintf(L"\nPdhOpenQuery failed with status 0x%x.", Status);
        goto Cleanup;
    }

    Status = PdhAddCounter(Query, COUNTER_NAME, 0, &Counter);
    if (Status != ERROR_SUCCESS)
    {
        wprintf(L"\nPdhAddCounter failed with 0x%x.", Status);
        goto Cleanup;
    }

    //
    // Calculating the formatted value of some counters requires access to the
    // value of a previous sample. Make this call to get the first sample value
    // populated, to be used later for calculating the next sample.
    //

    Status = PdhCollectQueryData(Query);
    if (Status != ERROR_SUCCESS)
    {
        wprintf(L"\nPdhCollectQueryData failed with status 0x%x.", Status);
        goto Cleanup;
    }

    //
    // This will create a separate thread that will collect raw counter data
    // every 2 seconds and set the supplied Event.
    //

    Event = CreateEvent(NULL, FALSE, FALSE, L"MyEvent");
    if (Event == NULL)
    {
        wprintf(L"\nCreateEvent failed with status 0x%x.", GetLastError());
        goto Cleanup;
    }

    Status = PdhCollectQueryDataEx(Query, SAMPLE_INTERVAL, Event);
    if (Status != ERROR_SUCCESS)
    {
        wprintf(L"\nPdhCollectQueryDataEx failed with status 0x%x.", Status);
        goto Cleanup;
    }

    //
    // Collect and format 10 samples, 2 seconds apart.
    //

    for (ULONG i = 0; i < SAMPLE_COUNT; i++)
    {
        WaitResult = WaitForSingleObject(Event, INFINITE);

        if (WaitResult == WAIT_OBJECT_0)
        {
            Status = PdhGetFormattedCounterValue(Counter, PDH_FMT_DOUBLE, &CounterType, &DisplayValue);

            if (Status == ERROR_SUCCESS)
            {
                wprintf(L"\nCounter Value: %.20g", DisplayValue.doubleValue);
            }
            else
            {
                wprintf(L"\nPdhGetFormattedCounterValue failed with status 0x%x.", Status);
                goto Cleanup;
            }
        }
        else if (WaitResult == WAIT_FAILED)
        {
            wprintf(L"\nWaitForSingleObject failed with status 0x%x.", GetLastError());
            goto Cleanup;
        }
    }

Cleanup:

    if (Event)
    {
        CloseHandle(Event);
    }

    //
    // This will close both the Query handle and all associated Counter handles
    // returned by PdhAddCounter.
    //

    if (Query)
    {
        PdhCloseQuery(Query);
    }
}

```

## See also

[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa)

[PdhCollectQueryData](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhcollectquerydata)

[PdhOpenQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenquerya)