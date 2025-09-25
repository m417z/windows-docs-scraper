# GetInterfaceInfo function

## Description

The
**GetInterfaceInfo** function obtains the list of the network interface adapters with IPv4 enabled on the local system.

## Parameters

### `pIfTable` [out]

A pointer to a buffer that specifies an
[IP_INTERFACE_INFO](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_interface_info) structure that receives the list of adapters. This buffer must be allocated by the caller.

### `dwOutBufLen` [in, out]

A pointer to a **DWORD** variable that specifies the size of the
buffer pointed to by *pIfTable* parameter to receive the [IP_INTERFACE_INFO](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_interface_info) structure. If this size is insufficient to hold the IPv4 interface information,
**GetInterfaceInfo** fills in this variable with the required size, and returns an error code of **ERROR_INSUFFICIENT_BUFFER**.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer to receive the IPv4 adapter information is too small. This value is returned if the *dwOutBufLen* parameter indicates that the buffer pointed to by the *pIfTable* parameter is too small to retrieve the IPv4 interface information. The required size is returned in the **DWORD** variable pointed to by the *dwOutBufLen* parameter. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if the *dwOutBufLen* parameter is **NULL**, or [GetInterfaceInfo](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getinterfaceinfo) is unable to write to the memory pointed to by the *dwOutBufLen* parameter. |
| **ERROR_NO_DATA** | There are no network adapters enabled for IPv4 on the local system. This value is also returned if all network adapters on the local system are disabled. |
| **ERROR_NOT_SUPPORTED** | This function is not supported on the operating system in use on the local system. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The
**GetInterfaceInfo** function is specific to network adapters with IPv4 enabled. The function returns an [IP_INTERFACE_INFO](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_interface_info) structure pointed to by the *pIfTable* parameter that contains the number of network adapters with IPv4 enabled on the local system and an array of [IP_ADAPTER_INDEX_MAP](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_adapter_index_map) structures with information on each network adapter with IPv4 enabled. The **IP_INTERFACE_INFO** structure returned by **GetInterfaceInfo** contains at least one **IP_ADAPTER_INDEX_MAP** structure even if the **NumAdapters** member of the **IP_INTERFACE_INFO** structure indicates that no network adapters with IPv4 are enabled. When the **NumAdapters** member of the **IP_INTERFACE_INFO** structure returned by **GetInterfaceInfo** is zero, the value of the members of the single **IP_ADAPTER_INDEX_MAP** structure returned in the **IP_INTERFACE_INFO** structure is undefined.

If the **GetInterfaceInfo** function is called with too small a buffer to retrieve the IPv4 interface information (the *dwOutBufLen* parameter indicates that the buffer pointed to by the *pIfTable* parameter is too small), the function returns **ERROR_INSUFFICIENT_BUFFER**. The required size is returned in the **DWORD** variable pointed to by the *dwOutBufLen* parameter.

 The correct way to use the **GetInterfaceInfo** function is to call this function twice. In the first call, pass a **NULL** pointer in the *pIfTable* parameter and zero in the variable pointed to by the *dwOutBufLen* parameter. The call will fail with **ERROR_INSUFFICIENT_BUFFER** and the required size for this buffer is returned in the **DWORD** variable pointed to by the *dwOutBufLen* parameter. A buffer can then be allocated of the required size using the value pointed by the *dwOutBufLen*. Then the **GetInterfaceInfo** function can be called a second time with a pointer to this buffer passed in the *pIfTable* parameter and the length of the buffer set to the size of this buffer.

The
[GetAdaptersInfo](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersinfo) and
**GetInterfaceInfo** functions do not return information about the loopback interface. Information on the loopback interface is returned by the [GetIpAddrTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipaddrtable) function.

On Windows Vista and later, the **Name** member of the [IP_ADAPTER_INDEX_MAP](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_adapter_index_map) structure returned in the [IP_INTERFACE_INFO](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_interface_info) structure may be a Unicode string of the GUID for the network interface (the string begins with the '{' character).

#### Examples

The following example retrieves the list of network adapters with IPv4 enabled on the local system and prints various properties of the first network adapter.

```cpp
#include <winsock2.h>
#include <ws2ipdef.h>
#include <iphlpapi.h>
#include <stdio.h>

#pragma comment(lib, "iphlpapi.lib")

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

/* Note: could also use malloc() and free() */

int main()
{

// Declare and initialize variables
    PIP_INTERFACE_INFO pInfo = NULL;
    ULONG ulOutBufLen = 0;

    DWORD dwRetVal = 0;
    int iReturn = 1;

    int i;

// Make an initial call to GetInterfaceInfo to get
// the necessary size in the ulOutBufLen variable
    dwRetVal = GetInterfaceInfo(NULL, &ulOutBufLen);
    if (dwRetVal == ERROR_INSUFFICIENT_BUFFER) {
        pInfo = (IP_INTERFACE_INFO *) MALLOC(ulOutBufLen);
        if (pInfo == NULL) {
            printf
                ("Unable to allocate memory needed to call GetInterfaceInfo\n");
            return 1;
        }
    }
// Make a second call to GetInterfaceInfo to get
// the actual data we need
    dwRetVal = GetInterfaceInfo(pInfo, &ulOutBufLen);
    if (dwRetVal == NO_ERROR) {
        printf("Number of Adapters: %ld\n\n", pInfo->NumAdapters);
        for (i = 0; i < pInfo->NumAdapters; i++) {
            printf("Adapter Index[%d]: %ld\n", i,
                   pInfo->Adapter[i].Index);
            printf("Adapter Name[%d]: %ws\n\n", i,
                   pInfo->Adapter[i].Name);
        }
        iReturn = 0;
    } else if (dwRetVal == ERROR_NO_DATA) {
        printf
            ("There are no network adapters with IPv4 enabled on the local system\n");
        iReturn = 0;
    } else {
        printf("GetInterfaceInfo failed with error: %d\n", dwRetVal);
        iReturn = 1;
    }

    FREE(pInfo);
    return (iReturn);
}

```

## See also

[GetAdaptersInfo](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersinfo)

[GetIpAddrTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipaddrtable)

[GetNumberOfInterfaces](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getnumberofinterfaces)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IP_ADAPTER_INDEX_MAP](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_adapter_index_map)

[IP_INTERFACE_INFO](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_interface_info)