# PdhGetFormattedCounterArrayA function

## Description

Returns an array of formatted counter values. Use this function when you want to format the counter values of a counter that contains a wildcard character for the instance name.

## Parameters

### `hCounter` [in]

Handle to the counter whose current value you want to format. The
[PdhAddCounter](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhaddcountera) function returns this handle.

### `dwFormat` [in]

Determines the data type of the formatted value. Specify one of the following values.

| Value | Meaning |
| --- | --- |
| **PDH_FMT_DOUBLE** | Return data as a double-precision floating point real. |
| **PDH_FMT_LARGE** | Return data as a 64-bit integer. |
| **PDH_FMT_LONG** | Return data as a long integer. |

You can use the bitwise inclusive OR operator (|) to combine the data type with one of the following scaling factors.

| Value | Meaning |
| --- | --- |
| **PDH_FMT_NOSCALE** | Do not apply the counter's default scaling factor. |
| **PDH_FMT_NOCAP100** | Counter values greater than 100 (for example, counter values measuring the processor load on multiprocessor computers) will not be reset to 100. The default behavior is that counter values are capped at a value of 100. |
| **PDH_FMT_1000** | Multiply the actual value by 1,000. |

### `lpdwBufferSize` [in, out]

Size of the *ItemBuffer* buffer, in bytes. If zero on input, the function returns PDH_MORE_DATA and sets this parameter to the required buffer size. If the buffer is larger than the required size, the function sets this parameter to the actual size of the buffer that was used. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer.

### `lpdwItemCount` [out]

Number of counter values in the *ItemBuffer* buffer.

### `ItemBuffer` [out]

Caller-allocated buffer that receives an array of
[PDH_FMT_COUNTERVALUE_ITEM](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_fmt_countervalue_item_a) structures; the structures contain the counter values. Set to **NULL** if *lpdwBufferSize* is zero.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_MORE_DATA** | The *ItemBuffer* buffer is not large enough to contain the object name. This return value is expected if *lpdwBufferSize* is zero on input. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer. |
| **PDH_INVALID_ARGUMENT** | A parameter is not valid or is incorrectly formatted. For example, on some releases you could receive this error if the specified size on input is greater than zero but less than the required size. |
| **PDH_INVALID_HANDLE** | The counter handle is not valid. |

## Remarks

You should call this function twice, the first time to get the required buffer size (set *ItemBuffer* to **NULL** and *lpdwBufferSize* to 0), and the second time to get the data.

The data for the counter is locked for the duration of the call to
**PdhGetFormattedCounterArray** to prevent any changes during the processing of the call.

#### Examples

The following example shows how to use this function.

```cpp

#include <windows.h>
#include <stdio.h>
#include <pdh.h>
#include <pdhmsg.h>

#pragma comment(lib, "pdh.lib")

CONST PWSTR COUNTER_PATH = L"\\Processor(*)\\% Processor Time";
CONST ULONG SAMPLE_INTERVAL_MS = 1000;

void main()
{
    PDH_HQUERY hQuery = NULL;
    PDH_STATUS status = ERROR_SUCCESS;
    PDH_HCOUNTER hCounter = NULL;
    DWORD dwBufferSize = 0;         // Size of the pItems buffer
    DWORD dwItemCount = 0;          // Number of items in the pItems buffer
    PDH_FMT_COUNTERVALUE_ITEM *pItems = NULL;  // Array of PDH_FMT_COUNTERVALUE_ITEM structures

    if (status = PdhOpenQuery(NULL, 0, &hQuery))
    {
        wprintf(L"PdhOpenQuery failed with 0x%x.\n", status);
        goto cleanup;
    }

    // Specify a counter object with a wildcard for the instance.
    if (status = PdhAddCounter(hQuery, COUNTER_PATH, 0, &hCounter))
    {
        wprintf(L"PdhAddCounter failed with 0x%x.\n", status);
        goto cleanup;
    }

    // Some counters need two sample in order to format a value, so
    // make this call to get the first value before entering the loop.
    if (status = PdhCollectQueryData(hQuery))
    {
        wprintf(L"PdhCollectQueryData failed with 0x%x.\n", status);
        goto cleanup;
    }

    for (int i = 0; i < 10; i++)
    {
        Sleep(SAMPLE_INTERVAL_MS);

        if (status = PdhCollectQueryData(hQuery))
        {
            wprintf(L"PdhCollectQueryData failed with 0x%x.\n", status);
            goto cleanup;
        }

        // Get the required size of the pItems buffer.
        status = PdhGetFormattedCounterArray(hCounter, PDH_FMT_DOUBLE, &dwBufferSize, &dwItemCount, pItems);
        if (PDH_MORE_DATA == status)
        {
            pItems = (PDH_FMT_COUNTERVALUE_ITEM *) malloc(dwBufferSize);
            if (pItems)
            {
                status = PdhGetFormattedCounterArray(hCounter, PDH_FMT_DOUBLE, &dwBufferSize, &dwItemCount, pItems);
                if (ERROR_SUCCESS == status)
                {
                    // Loop through the array and print the instance name and counter value.
                    for (DWORD i = 0; i < dwItemCount; i++)
                    {
                        wprintf(L"counter: %s, value %.20g\n", pItems[i].szName, pItems[i].FmtValue.doubleValue);
                    }
                }
                else
                {
                    wprintf(L"Second PdhGetFormattedCounterArray call failed with 0x%x.\n", status);
                    goto cleanup;
                }

                free(pItems);
                pItems = NULL;
                dwBufferSize = dwItemCount = 0;
            }
            else
            {
                wprintf(L"malloc for PdhGetFormattedCounterArray failed.\n");
                goto cleanup;
            }
        }
        else
        {
            wprintf(L"PdhGetFormattedCounterArray failed with 0x%x.\n", status);
            goto cleanup;
        }
    }

cleanup:

    if (pItems)
        free(pItems);

    if (hQuery)
        PdhCloseQuery(hQuery); // Closes all counter handles and the query handle
}

```

> [!NOTE]
> The pdh.h header defines PdhGetFormattedCounterArray as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[PDH_FMT_COUNTERVALUE_ITEM](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_fmt_countervalue_item_a)

[PdhAddCounter](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhaddcountera)

[PdhGetFormattedCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetformattedcountervalue)

[PdhGetRawCounterArray](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetrawcounterarraya)

[PdhGetRawCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetrawcountervalue)