# _WSK_PROVIDER_DISPATCH structure

## Description

The WSK_PROVIDER_DISPATCH structure specifies the WSK subsystem's dispatch table of functions that
are not specific to a particular socket.

## Members

### `Version`

The version of the WSK
[Network Programming Interface
(NPI)](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) that the WSK subsystem will use for its attachment to the WSK application.

### `Reserved`

Reserved for system use.

### `WskSocket`

A pointer to the WSK subsystem's
[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket) function.

### `WskSocketConnect`

A pointer to the WSK subsystem's
[WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect) function.

### `WskControlClient`

A pointer to the WSK subsystem's
[WskControlClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_client) function.

### `WskGetAddressInfo`

A pointer to the WSK subsystem's
[WskGetAddressInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_get_address_info) function.

This member is available beginning with Windows 7.

### `WskFreeAddressInfo`

A pointer to the WSK subsystem's
[WskFreeAddressInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_free_address_info) function.

This member is available beginning with Windows 7.

### `WskGetNameInfo`

A pointer to the WSK subsystem's
[WskGetNameInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_get_name_info) function.

This member is available beginning with Windows 7.

## Remarks

When a WSK application calls the
[WskCaptureProviderNPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskcaptureprovidernpi) function, the
WSK subsystem returns a pointer to a WSK_PROVIDER_DISPATCH structure by means of the
**Dispatch** member of the
[WSK_CLIENT_NPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_npi) structure pointed to by the
*WskProviderNpi* parameter.

The major and minor version numbers that are contained within the
**Version** member are encoded by using the MAKE_WSK_VERSION macro:

```
Version = MAKE_WSK_VERSION(Major,Minor);
```

The major and minor version numbers can be extracted from the
**Version** member by using the WSK_MAJOR_VERSION and WSK_MINOR_VERSION macros:

```
Major = WSK_MAJOR_VERSION(Version);
Minor = WSK_MINOR_VERSION(Version);
```

The minor version number that is contained within the
**Version** member of this structure might be a higher minor version number than what was requested by
the WSK application in the
**Version** member of the
[WSK_CLIENT_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_dispatch) structure. This
situation should not cause a problem for the WSK application because higher minor versions of the WSK NPI
are a strict superset of lower minor versions of the WSK NPI if they have the same major version number.
The WSK subsystem will specify the remaining members of the WSK_PROVIDER_DISPATCH structure to conform to
the version of the WSK NPI that is indicated in the
**Version** member of the structure.

For more information about attaching a WSK application to the WSK subsystem, see
[Registering a Winsock Kernel
Application](https://learn.microsoft.com/windows-hardware/drivers/network/registering-a-winsock-kernel-application).

## See also

[WSK_CLIENT_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_dispatch)

[WSK_CLIENT_NPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_npi)

[WskCaptureProviderNPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskcaptureprovidernpi)

[WskControlClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_client)

[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket)

[WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect)