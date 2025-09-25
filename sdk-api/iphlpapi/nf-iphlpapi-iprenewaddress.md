# IpRenewAddress function

## Description

The
**IpRenewAddress** function renews a lease on an IPv4 address previously obtained through Dynamic Host Configuration Protocol (DHCP).

## Parameters

### `AdapterInfo` [in]

A pointer to an
[IP_ADAPTER_INDEX_MAP](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_adapter_index_map) structure that specifies the adapter associated with the IP address to renew.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, use
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One of the parameters is invalid. This error is returned if the *AdapterInfo* parameter is **NULL** or if the **Name** member of the **PIP_ADAPTER_INDEX_MAP** structure pointed to by the *AdapterInfo* parameter is invalid. |
| **ERROR_PROC_NOT_FOUND** | An exception occurred during the request to DHCP for the renewal of the IPv4 address. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The
**IpRenewAddress** function is specific to IPv4 and renews only an IPv4 address previously obtained through the Dynamic Host Configuration Protocol (DHCP). The **Name** member of the [IP_ADAPTER_INDEX_MAP](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_adapter_index_map) structure pointed to by the *AdapterInfo* parameter is the only member used to determine the DHCP address to renew.

 An array of [IP_ADAPTER_INDEX_MAP](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_adapter_index_map) structures are returned in the [IP_INTERFACE_INFO](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_interface_info) structure by the [GetInterfaceInfo](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getinterfaceinfo) function. The **IP_INTERFACE_INFO** structure returned by **GetInterfaceInfo** contains at least one **IP_ADAPTER_INDEX_MAP** structure even if the **NumAdapters** member of the **IP_INTERFACE_INFO** structure indicates that no network adapters with IPv4 are enabled. When the **NumAdapters** member of the **IP_INTERFACE_INFO** structure returned by **GetInterfaceInfo** is zero, the value of the members of the single **IP_ADAPTER_INDEX_MAP** structure returned in the **IP_INTERFACE_INFO** structure is undefined.

If the **Name** member of the [IP_ADAPTER_INDEX_MAP](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_adapter_index_map) structure pointed to by the *AdapterInfo* parameter is **NULL**, the
**IpRenewAddress** function returns **ERROR_INVALID_PARAMETER**.

There are no functions available for releasing or renewing an IPv6 address. This can only be done by executing the Ipconfig command:

**ipconfig /release6**

**ipconfig /renew6**

#### Examples

The following example retrieves the list of network adapters with IPv4 enabled on the local system, then releases and renews the IPv4 address for the first adapter in the list.

```cpp
#include <windows.h>
#include <iphlpapi.h>
#include <stdio.h>

#pragma comment(lib, "iphlpapi.lib")

/* Note: could also use malloc() and free() */
#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

void main()
{

    // Before calling IpReleaseAddress and IpRenewAddress we use
    // GetInterfaceInfo to retrieve a handle to the adapter

    PIP_INTERFACE_INFO pInfo;
    pInfo = (IP_INTERFACE_INFO *) MALLOC( sizeof(IP_INTERFACE_INFO) );
    ULONG ulOutBufLen = 0;
    DWORD dwRetVal = 0;

    // Make an initial call to GetInterfaceInfo to get
    // the necessary size into the ulOutBufLen variable
    if ( GetInterfaceInfo(pInfo, &ulOutBufLen) == ERROR_INSUFFICIENT_BUFFER) {
      FREE(pInfo);
      pInfo = (IP_INTERFACE_INFO *) MALLOC (ulOutBufLen);
    }

    // Make a second call to GetInterfaceInfo to get the
    // actual data we want
    if ((dwRetVal = GetInterfaceInfo(pInfo, &ulOutBufLen)) == NO_ERROR ) {
      printf("\tAdapter Name: %ws\n", pInfo->Adapter[0].Name);
      printf("\tAdapter Index: %ld\n", pInfo->Adapter[0].Index);
      printf("\tNum Adapters: %ld\n", pInfo->NumAdapters);
    }
    else if (dwRetVal == ERROR_NO_DATA) {
      printf("There are no network adapters with IPv4 enabled on the local system\n");
      FREE(pInfo);
      pInfo = NULL;
      return;
    }
    else {
      printf("GetInterfaceInfo failed.\n");
      LPVOID lpMsgBuf;

      if (FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dwRetVal,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
        (LPTSTR) &lpMsgBuf,
        0,
        NULL )) {
        printf("\tError: %s", lpMsgBuf);
      }
      LocalFree( lpMsgBuf );
      return;
    }

    // Call IpReleaseAddress and IpRenewAddress to release and renew
    // the IP address on the first network adapter returned
    // by the call to GetInterfaceInfo.
    if ((dwRetVal = IpReleaseAddress(&pInfo->Adapter[0])) == NO_ERROR) {
      printf("IP release succeeded.\n");
    }
    else {
      printf("IP release failed.\n");
    }

    if ((dwRetVal = IpRenewAddress(&pInfo->Adapter[0])) == NO_ERROR) {
      printf("IP renew succeeded.\n");
    }
    else {
      printf("IP renew failed.\n");
    }

    /* Free allocated memory no longer needed */
    if (pInfo) {
        FREE(pInfo);
        pInfo = NULL;
    }
}

```

## See also

[GetInterfaceInfo](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getinterfaceinfo)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IP_ADAPTER_INDEX_MAP](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_adapter_index_map)

[IP_INTERFACE_INFO](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_interface_info)

[IpReleaseAddress](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-ipreleaseaddress)