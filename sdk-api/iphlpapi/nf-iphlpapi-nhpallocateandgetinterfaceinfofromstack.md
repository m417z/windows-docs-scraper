# NhpAllocateAndGetInterfaceInfoFromStack function

## Description

[This function is no longer available for use as of Windows Vista. Instead, use the [GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses) function and the associated [IP_ADAPTER_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_addresses_lh) structure.]

The **NhpAllocateAndGetInterfaceInfoFromStack** function obtains adapter information about the local computer.

## Parameters

### `ppTable`

An array of [IP_INTERFACE_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_interface_name_info_w2ksp1) structures that contains information about each adapter on the local system. The array contains one element for each adapter on the system.

### `pdwCount`

The number of elements in the *ppTable* array.

### `bOrder`

When **TRUE**, elements in the *ppTable* array are sorted by increasing index value.

### `hHeap`

A handle that specifies the heap from which *ppTable* should be allocated. This parameter can be the process heap returned by a call to the [GetProcessHeap](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-getprocessheap) function, or a private heap created by a call to the [HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate) function.

### `dwFlags`

A set of flags to be passed to the [HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc) function when allocating memory for *ppTable*. See the **HeapAlloc** function for more information.

## Return value

Returns ERROR_SUCCESS upon successful completion.

## Remarks

In the Microsoft Windows Software Development Kit (SDK), the **NhpAllocateAndGetInterfaceInfoFromStack** function is defined on Windows 2000 with Service Pack 1 (SP1) and later. When compiling an application, if the target platform is Windows 2000 with SP1 and later (`NTDDI_VERSION >= NTDDI_WIN2KSP1`, `_WIN32_WINNT >= 0x0500`, or `WINVER >= 0x0500`), the **NhpAllocateAndGetInterfaceInfoFromStack** is defined.

## See also

[GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses)

[GetProcessHeap](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-getprocessheap)

[HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate)

[IP
Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP
Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IP_INTERFACE_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_interface_name_info_w2ksp1)