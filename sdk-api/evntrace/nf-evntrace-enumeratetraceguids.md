# EnumerateTraceGuids function

## Description

The **EnumerateTraceGuids** function retrieves information about event trace
providers that are currently running on the computer.

> [!Important]
> This function has been superseded by
> [EnumerateTraceGuidsEx](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-enumeratetraceguidsex).

## Parameters

### `GuidPropertiesArray` [in, out]

An array of pointers to
[TRACE_GUID_PROPERTIES](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-trace_guid_properties)
structures. Each pointer in the array must point at a buffer with room to store
a **TRACE_GUID_PROPERTIES** structure.

### `PropertyArrayCount` [in]

Number of pointers in the _GuidPropertiesArray_ array.

### `GuidCount` [out]

Receives the actual number of event tracing providers registered on the
computer.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is one of the
[system error codes](https://learn.microsoft.com/windows/win32/debug/system-error-codes). The following are
some common errors and their causes.

- **ERROR_INVALID_PARAMETER**

 One of the following is true:

  - _PropertyArrayCount_ is zero
  - _GuidPropertiesArray_ is **NULL**

- **ERROR_MORE_DATA**

 The property array is too small to receive information for all registered
providers (_GuidCount_ is greater than _PropertyArrayCount_). The function
fills _GuidPropertiesArray_ with the number of structures specified in
_PropertyArrayCount_.

## Remarks

This function returns information about event trace providers that have been
started (via
[RegisterTraceGuids](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-registertraceguidsa),
[EventRegister](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventregister)) and have
not yet been stopped.

> [!Note]
> To get information about provider manifests that have been registered
> on the system (i.e. manifests registered via `wevtutil`), use
> [TdhEnumerateProviders](https://learn.microsoft.com/windows/win32/api/tdh/nf-tdh-tdhenumerateproviders).

You can use the
[TRACE_GUID_PROPERTIES](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-trace_guid_properties).LoggerId member to
determine which session most recently enabled the provider if
**TRACE_GUID_PROPERTIES.IsEnable** is **TRUE**.

The list will not include the SystemTraceProvider providers.

### Examples

The following example shows you how to call this function.

```cpp
#include <windows.h>
#include <evntrace.h>
#include <vector>
#include <stdio.h>

int
wmain()
{
    ULONG status = 0;

    try
    {
        ULONG guidCount;
        std::vector<TRACE_GUID_PROPERTIES> guidPropValues;
        std::vector<TRACE_GUID_PROPERTIES*> guidPropPointers;

        // First call is just to get the actual count, so allocate a small buffer.
        guidCount = 1;

        // May need to retry multiple times since new providers could be added
        // between calls.
        for (;;)
        {
            ULONG const allocated = guidCount;
            guidPropValues.resize(allocated);
            guidPropPointers.resize(allocated);

            // Initialize the pointers to point at the values.
            for (ULONG i = 0; i != allocated; i += 1)
            {
                guidPropPointers[i] = &guidPropValues[i];
            }

            guidCount = 0;
            status = EnumerateTraceGuids(guidPropPointers.data(), allocated, &guidCount);
            if (status != ERROR_MORE_DATA)
            {
                guidPropValues.resize(guidCount);
                break;
            }

        }

        if (status != ERROR_SUCCESS)
        {
            printf("EnumerateTraceGuids error: %u\n", status);
        }
        else
        {
            printf("GuidCount = %lu\n", guidCount);
            for (auto const& v : guidPropValues)
            {
                printf("%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x - %hs\n",
                    v.Guid.Data1, v.Guid.Data2, v.Guid.Data3,
                    v.Guid.Data4[0], v.Guid.Data4[1],
                    v.Guid.Data4[2], v.Guid.Data4[3], v.Guid.Data4[4],
                    v.Guid.Data4[5], v.Guid.Data4[6], v.Guid.Data4[7],
                    v.IsEnable ? "Enabled" : "Disabled");
            }
        }
    }
    catch (std::bad_alloc const&)
    {
        printf("Out of memory!\n");
        status = ERROR_OUTOFMEMORY;
    }

    return status;
}
```

## See also

[EnumerateTraceGuidsEx](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-enumeratetraceguidsex)

[QueryAllTraces](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-queryalltracesw)

[TRACE_GUID_PROPERTIES](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-trace_guid_properties)