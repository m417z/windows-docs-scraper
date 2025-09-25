# _WSK_CLIENT_DISPATCH structure

## Description

The WSK_CLIENT_DISPATCH structure specifies a WSK application's dispatch table of event callback
functions for events that are not specific to a particular socket.

## Members

### `Version`

The version of the WSK
[Network Programming Interface
(NPI)](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) that the WSK application would like to use.

### `Reserved`

Reserved for system use. WSK applications must set this member to zero.

### `WskClientEvent`

A pointer to the WSK application's
[WskClientEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_client_event) event callback function. If
a WSK application does not implement a
*WskClientEvent* event callback function, this member must be set to **NULL**.

## Remarks

When a WSK application calls the
[WskRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskregister) function, it provides a pointer to
an initialized WSK_CLIENT_DISPATCH structure by means of the
**Dispatch** member of the
[WSK_CLIENT_NPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_npi) structure pointed to by the
*WskClientNpi* parameter.

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

For more information about attaching a WSK application to the WSK subsystem, see
[Registering a Winsock Kernel
Application](https://learn.microsoft.com/windows-hardware/drivers/network/registering-a-winsock-kernel-application).

## See also

[WSK_CLIENT_NPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_npi)

[WSK_PROVIDER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_dispatch)

[WSK_PROVIDER_NPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_npi)

[WskClientEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_client_event)

[WskRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskregister)