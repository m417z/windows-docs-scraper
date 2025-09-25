# NetworkIsolationGetAppContainerConfig function

## Description

The **NetworkIsolationGetAppContainerConfig** function is used to retrieve configuration information about one or more app containers.

## Parameters

### `pdwNumPublicAppCs` [out]

Type: **DWORD***

The number of app containers in the **appContainerSids** member.

### `appContainerSids` [out]

Type: **[PSID_AND_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_and_attributes)***

The security identifiers (SIDs) of app containers that are allowed to send loopback traffic. Used for debugging purposes.

## Return value

Type: **DWORD**

Returns ERROR_SUCCESS if successful, or an error value otherwise.

## Remarks

Note that it is the calling program's responsibility to free the memory associated with the PSID_AND_ATTRIBUTES structure. The following code sample shows how to call this function. The FreeAppContainerConfig function shows how to free all of the associated memory.

```cpp

#include "stdafx.h"
#include <netfw.h>

typedef DWORD
(WINAPI *FN_NETWORKISOLATIONGETAPPCONTAINERCONFIG)(
    _Out_ DWORD *pdwNumPublicAppCs,
    _Outptr_result_buffer_(*pdwNumPublicAppCs) PSID_AND_ATTRIBUTES *appContainerSids
    );

void
FreeAppContainerConfig(
    __in DWORD sidCount,
    __in_ecount(sidCount) SID_AND_ATTRIBUTES *srcSidAttrib
    )
{
    DWORD dwIndex = 0;

    for (dwIndex = 0; dwIndex < sidCount; dwIndex++)
    {
        HeapFree(GetProcessHeap(), 0, srcSidAttrib[dwIndex].Sid);
    }

    HeapFree(GetProcessHeap(), 0, srcSidAttrib);
}

int _tmain(int argc, _TCHAR* argv[])
{
    DWORD dwErr = 0;
    PSID_AND_ATTRIBUTES appContainerSids = NULL;
    DWORD dwCount = 0;
    HMODULE hModule = NULL;
    FN_NETWORKISOLATIONGETAPPCONTAINERCONFIG pfnNetworkIsolationGetAppContainerConfig = NULL;

    hModule = LoadLibraryW(L"FirewallAPI.dll");
    if (hModule == NULL)
    {
        dwErr = GetLastError();
        goto Cleanup;
    }

    pfnNetworkIsolationGetAppContainerConfig = (FN_NETWORKISOLATIONGETAPPCONTAINERCONFIG)GetProcAddress(
        hModule,
        "NetworkIsolationGetAppContainerConfig"
        );
    if (pfnNetworkIsolationGetAppContainerConfig == NULL)
    {
        dwErr = GetLastError();
        goto Cleanup;
    }

    dwErr = pfnNetworkIsolationGetAppContainerConfig(
        &dwCount,
        &appContainerSids
        );
    if (dwErr != ERROR_SUCCESS)
    {
        goto Cleanup;
    }

    // Process the app container sids

Cleanup:

    FreeAppContainerConfig(
        dwCount,
        appContainerSids
        );

    if (hModule != NULL)
    {
        FreeLibrary(hModule);
    }

	return 0;
}

```