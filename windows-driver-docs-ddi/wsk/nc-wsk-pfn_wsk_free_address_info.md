# PFN_WSK_FREE_ADDRESS_INFO callback function

## Description

The
**WskFreeAddressInfo** function frees address information that the
[WskGetAddressInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_get_address_info) function has dynamically
allocated.

## Parameters

### `Client` [in]

[in] A pointer to a
[WSK_CLIENT](https://learn.microsoft.com/windows-hardware/drivers/network/wsk-client) structure that was returned through
the
*WskProviderNpi* parameter of the
[WskCaptureProviderNPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskcaptureprovidernpi) function.

### `AddrInfo` [in]

[in] A pointer to a linked list of one or more [ADDRINFOEXW](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-addrinfoexw) structures that contain response
information about the host. This pointer was returned through the
*Result* parameter of the
[WskGetAddressInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_get_address_info) function.

The [ADDRINFOEXW](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-addrinfoexw) structure is defined in the
Ws2def.h header file. It is identical to the
[addrinfoex](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-addrinfoexw) structure.

**Important** The
Ws2def.h header file is automatically included in
Wsk.h. Do not use
Ws2def.h directly.

## See also

[WSK_CLIENT](https://learn.microsoft.com/windows-hardware/drivers/network/wsk-client)

[WskCaptureProviderNPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskcaptureprovidernpi)

[WskGetAddressInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_get_address_info)