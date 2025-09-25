# EnumerateTraceGuidsEx function

## Description

Retrieves information about event trace providers that are currently running on
the computer.

## Parameters

### `TraceQueryInfoClass` [in]

Determines the type of information to return. For possible values, see the
[TRACE_QUERY_INFO_CLASS](https://learn.microsoft.com/windows/win32/api/evntrace/ne-evntrace-trace_query_info_class)
enumeration.

### `InBuffer` [in]

GUID of the provider or provider group whose information you want to retrieve.
Specify the GUID only if _TraceQueryInfoClass_ is **TraceGuidQueryInfo** or
**TraceGroupQueryInfo**.

### `InBufferSize` [in]

Size, in bytes, of the data _InBuffer_.

### `OutBuffer` [out]

Application-allocated buffer that contains the enumerated information. The
format of the information depends on the value of _TraceQueryInfoClass_.

### `OutBufferSize` [in]

Size, in bytes, of the _OutBuffer_ buffer. If the function succeeds, the
_ReturnLength_ parameter receives the size of the buffer used. If the buffer is
too small, the function returns `ERROR_INSUFFICIENT_BUFFER` and the
_ReturnLength_ parameter receives the required buffer size. If the buffer size
is zero on input, no data is returned in the buffer and the _ReturnLength_
parameter receives the required buffer size.

### `ReturnLength` [out]

Actual size of the data in _OutBuffer_, in bytes.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is one of the
[system error codes](https://learn.microsoft.com/windows/win32/debug/system-error-codes). The following are
some common errors and their causes.

- **ERROR_INVALID_PARAMETER**

 One of the parameters is not valid.

- **ERROR_INSUFFICIENT_BUFFER**

 The _OutBuffer_ buffer is too small to receive information for all registered
providers. Reallocate the buffer using the size returned in _ReturnLength_.

## Remarks

This function returns information about event trace providers that have been
started (via
[RegisterTraceGuids](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-registertraceguidsa)
or [EventRegister](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventregister)) and
have not yet been stopped.

> [!Note]
> To get information about provider manifests that have been registered
> on the system (i.e. manifests registered via `wevtutil`), use
> [TdhEnumerateProviders](https://learn.microsoft.com/windows/win32/api/tdh/nf-tdh-tdhenumerateproviders).

If _TraceQueryInfoClass_ is **TraceGuidQueryInfo**, ETW returns the data in a
[TRACE_GUID_INFO](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-trace_guid_info) block
that is a header to the information. The info block contains a
[TRACE_PROVIDER_INSTANCE_INFO](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-trace_provider_instance_info)
block for each provider that uses the same GUID. Each instance info block
contains a
[TRACE_ENABLE_INFO](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-trace_enable_info)
structure for each session that enabled the provider.

### Examples

The following example shows you how to call this function.

```cpp
#include <windows.h>
#include <stdio.h>
#include <evntcons.h>

DWORD GetProviderInfo(GUID ProviderGuid, PTRACE_GUID_INFO& pInfo);

int wmain(void)
{
    ULONG status = ERROR_SUCCESS;
    GUID* pTemp = NULL;
    GUID* pGuids = NULL;
    DWORD GuidListSize = 0;
    DWORD GuidCount = 0;
    DWORD RequiredListSize = 0;
    WCHAR ProviderGuid[50];
    PTRACE_GUID_INFO pInfo = NULL;
    PTRACE_PROVIDER_INSTANCE_INFO pInstance = NULL;
    PTRACE_ENABLE_INFO pEnable = NULL;

    // Get the required buffer size for the query.

    status = EnumerateTraceGuidsEx(TraceGuidQueryList, NULL, 0, pGuids, GuidListSize, &RequiredListSize);

    // The number of registered providers could change between the
    // time you called to get the buffer size and the time you called
    // to get the actual data, so call EnumerateTraceGuidsEx in a loop
    // until you no longer get ERROR_INSUFFICIENT_BUFFER.

    while (ERROR_INSUFFICIENT_BUFFER == status)
    {
        pTemp = (GUID*)realloc(pGuids, RequiredListSize);

        if (NULL == pTemp)
        {
            printf("Error allocating memory for list of provider GUIDs.\n");
            goto cleanup;
        }

        pGuids = pTemp;
        pTemp = NULL;

        GuidListSize = RequiredListSize;

        ZeroMemory(pGuids, GuidListSize);

        status = EnumerateTraceGuidsEx(TraceGuidQueryList, NULL, 0, pGuids, GuidListSize, &RequiredListSize);
    }

    if (ERROR_SUCCESS == status)
    {
        GuidCount = GuidListSize / sizeof(GUID);

        // For each registered provider on the computer, get information
        // about how it was registered. If a session enabled the
        // provider, get information on how the session enabled the provider.

        for (USHORT i = 0; i < GuidCount; i++)
        {
            StringFromGUID2(pGuids[i], ProviderGuid, sizeof(ProviderGuid));

            printf("Provider: %ls\n", ProviderGuid);

            status = GetProviderInfo(pGuids[i], pInfo);

            if (ERROR_SUCCESS == status)
            {
                pInstance = (PTRACE_PROVIDER_INSTANCE_INFO)((PBYTE)pInfo + sizeof(TRACE_GUID_INFO));

                if (pInfo->InstanceCount > 1)
                {
                    printf("There are %d providers that use the same GUID.\n", pInfo->InstanceCount);
                }

                for (DWORD j = 0; j < pInfo->InstanceCount; j++)
                {
                    printf("\tThe PID of the process that registered the provider is %lu.\n", pInstance->Pid);

                    if ((pInstance->Flags & TRACE_PROVIDER_FLAG_PRE_ENABLE) == TRACE_PROVIDER_FLAG_PRE_ENABLE)
                    {
                        printf("\tThe provider is not registered; however, one or more sessions have enabled the provider.\n");
                    }
                    else
                    {
                        if ((pInstance->Flags & TRACE_PROVIDER_FLAG_LEGACY) == TRACE_PROVIDER_FLAG_LEGACY)
                        {
                            printf("\tThe provider used RegisterTraceGuids to register itself.\n");
                        }
                        else
                        {
                            printf("\tThe provider used EventRegister to register itself.\n");
                        }
                    }

                    if (pInstance->EnableCount > 0)
                    {
                        printf("\tThe provider is enabled to the following sessions.\n");

                        pEnable = (PTRACE_ENABLE_INFO)((PBYTE)pInstance + sizeof(TRACE_PROVIDER_INSTANCE_INFO));

                        for (DWORD k = 0; k < pInstance->EnableCount; k++)
                        {
                            printf("\t\tSession Id: %hu\n", pEnable->LoggerId);
                            printf("\t\tLevel used to enable the provider: %hu\n", pEnable->Level);
                            printf("\t\tMatchAnyKeyword value used to enable the provider: %I64u\n", pEnable->MatchAnyKeyword);
                            printf("\t\tMatchAllKeyword value used to enable the provider: %I64u\n", pEnable->MatchAllKeyword);

                            if (pEnable->EnableProperty > 0)
                            {
                                printf("\t\tThe session requested that the following information be included with each event:\n");

                                if ((pEnable->EnableProperty & EVENT_ENABLE_PROPERTY_SID) == EVENT_ENABLE_PROPERTY_SID)
                                {
                                    printf("\t\t\tThe SID of the user that logged the event\n");
                                }

                                if ((pEnable->EnableProperty & EVENT_ENABLE_PROPERTY_TS_ID) == EVENT_ENABLE_PROPERTY_TS_ID)
                                {
                                    printf("\t\t\tThe terminal session ID\n");
                                }
                            }

                            pEnable++;

                            printf("\n");
                        }
                    }

                    pInstance = (PTRACE_PROVIDER_INSTANCE_INFO)((PBYTE)pInstance + pInstance->NextOffset);

                    printf("\n");
                }

                printf("\n");
            }
            else
            {
                printf("Error retrieving provider info (%lu)\n\n", status);
            }
        }

        printf("\nRegistered provider count is %lu.\n", GuidCount);
    }
    else
    {
        printf("EnumerateTraceGuidsEx(TraceGuidQueryList) failed with %lu.\n", status);
        goto cleanup;
    }

cleanup:

    if (pGuids)
    {
        free(pGuids);
        pGuids = NULL;
    }

    if (pInfo)
    {
        free(pInfo);
        pInfo = NULL;
    }

    return 0;
}

// Get information about the specified provider.

DWORD GetProviderInfo(GUID ProviderGuid, PTRACE_GUID_INFO& pInfo)
{
    ULONG status = ERROR_SUCCESS;
    PTRACE_GUID_INFO pTemp = NULL;
    DWORD InfoListSize = 0;
    DWORD RequiredListSize = 0;

    status = EnumerateTraceGuidsEx(TraceGuidQueryInfo, &ProviderGuid, sizeof(GUID), pInfo, InfoListSize, &RequiredListSize);

    while (ERROR_INSUFFICIENT_BUFFER == status)
    {
        pTemp = (PTRACE_GUID_INFO)realloc(pInfo, RequiredListSize);

        if (NULL == pTemp)
        {
            printf("Error allocating memory for provider info.\n");
            goto cleanup;
        }

        pInfo = pTemp;
        pTemp = NULL;

        InfoListSize = RequiredListSize;

        ZeroMemory(pInfo, InfoListSize);

        status = EnumerateTraceGuidsEx(TraceGuidQueryInfo, &ProviderGuid, sizeof(GUID), pInfo, InfoListSize, &RequiredListSize);
    }

    if (ERROR_SUCCESS != status)
    {
        printf("EnumerateTraceGuidsEx(TraceGuidQueryInfo) failed with %lu.\n", status);
    }

cleanup:

    return status;
}
```

## See also

[TRACE_QUERY_INFO_CLASS](https://learn.microsoft.com/windows/win32/api/evntrace/ne-evntrace-trace_query_info_class)