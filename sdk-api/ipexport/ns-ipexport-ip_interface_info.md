# IP_INTERFACE_INFO structure

## Description

The
**IP_INTERFACE_INFO** structure contains a list of the network interface adapters with IPv4 enabled on the local system.

## Members

### `NumAdapters`

The number of adapters listed in the array pointed to by the **Adapter** member.

### `Adapter`

An array of
[IP_ADAPTER_INDEX_MAP](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_adapter_index_map) structures. Each structure maps an adapter index to that adapter's name. The adapter index may change when an adapter is disabled and then enabled, or under other circumstances, and should not be considered persistent.

## Remarks

The
**IP_INTERFACE_INFO** structure is specific to network adapters with IPv4 enabled. The **IP_INTERFACE_INFO** structure contains the number of network adapters with IPv4 enabled on the local system and an array of [IP_ADAPTER_INDEX_MAP](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_adapter_index_map) structures with information on each network adapter with IPv4 enabled. The **IP_INTERFACE_INFO** structure contains at least one **IP_ADAPTER_INDEX_MAP** structure even if the **NumAdapters** member of the **IP_INTERFACE_INFO** structure indicates that no network adapters with IPv4 are enabled. When the **NumAdapters** member of the **IP_INTERFACE_INFO** structure is zero, the value of the members of the single **IP_ADAPTER_INDEX_MAP** structure returned in the **IP_INTERFACE_INFO** structure is undefined.

The
**IP_INTERFACE_INFO** structure can't be used to return information about the loopback interface.

On Windows Vista and later, the **Name** member of the [IP_ADAPTER_INDEX_MAP](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_adapter_index_map) structure in the **IP_INTERFACE_INFO** structure may be a Unicode string of the GUID for the network interface (the string begins with the '{' character).

This structure is defined in the *Ipexport.h* header file which is automatically included in the *Iphlpapi.h* header file. The *Ipexport.h* header file should never be used directly.

#### Examples

The following example retrieves the list of network adapters with IPv4 enabled on the local system and prints various properties of the first adapter.

```cpp
// Declare and initialize variables
PIP_INTERFACE_INFO pInfo;
pInfo = (IP_INTERFACE_INFO *) malloc( sizeof(IP_INTERFACE_INFO) );
ULONG ulOutBufLen = 0;
DWORD dwRetVal = 0;

// Make an initial call to GetInterfaceInfo to get
// the necessary size in the ulOutBufLen variable
if ( GetInterfaceInfo(pInfo, &ulOutBufLen) == ERROR_INSUFFICIENT_BUFFER) {
  free(pInfo);
  pInfo = (IP_INTERFACE_INFO *) malloc (ulOutBufLen);
}

// Make a second call to GetInterfaceInfo to get
// the actual data we need
if ((dwRetVal = GetInterfaceInfo(pInfo, &ulOutBufLen)) == NO_ERROR ) {
  printf("\tAdapter Name: %ws\n", pInfo->Adapter[0].Name);
  printf("\tAdapter Index: %ld\n", pInfo->Adapter[0].Index);
  printf("\tNum Adapters: %ld\n", pInfo->NumAdapters);

  // free memory allocated
  free(pInfo);
  pInfo = NULL;
}
else if (dwRetVal == ERROR_NO_DATA) {
  printf("There are no network adapters with IPv4 enabled on the local system\n");
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
    NULL ))  {
    printf("\tError: %s", lpMsgBuf);
  }
  LocalFree( lpMsgBuf );
}

```

## See also

[GetInterfaceInfo](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getinterfaceinfo)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IP Helper Structures](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-structures)

[IP_ADAPTER_INDEX_MAP](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_adapter_index_map)