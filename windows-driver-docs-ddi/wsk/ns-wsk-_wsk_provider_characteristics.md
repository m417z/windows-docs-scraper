# _WSK_PROVIDER_CHARACTERISTICS structure

## Description

The WSK_PROVIDER_CHARACTERISTICS structure specifies the characteristics of the WSK subsystem.

## Members

### `HighestVersion`

The highest version of the WSK
[Network Programming Interface
(NPI)](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) that is supported by the WSK subsystem.

### `LowestVersion`

The lowest version of the WSK NPI that is supported by the WSK subsystem.

## Remarks

When a
[WskCaptureProviderNPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskcaptureprovidernpi) call fails
with status code STATUS_NOINTERFACE, the WSK application can use a call to
[WskQueryProviderCharacteristics](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskqueryprovidercharacteristics) to query the range of WSK NPI versions supported by the WSK
subsystem.
**WskQueryProviderCharacteristics** returns the version information by means of the
WSK_PROVIDER_CHARACTERISTICS structure. A WSK application can use this information to determine if the
WSK subsystem supports a version of the WSK NPI that is compatible with the application.

The major and minor version numbers that are contained within the
**HighestVersion** and
**LowestVersion** members are encoded by using the MAKE_WSK_VERSION macro:

```
Version = MAKE_WSK_VERSION(Major,Minor);
```

The major and minor version numbers can be extracted from the
**HighestVersion** and
**LowestVersion** members by using the WSK_MAJOR_VERSION and WSK_MINOR_VERSION macros:

```
Major = WSK_MAJOR_VERSION(Version);
Minor = WSK_MINOR_VERSION(Version);
```

If a WSK application determines that the WSK subsystem supports a version of the WSK NPI that is
compatible with the application, the application should call
[WskRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskregister) and, by means of the
**Dispatch** member of the
[WSK_CLIENT_NPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_npi) structure pointed to by the
*WskClientNpi* parameter, it should specify the exact version of the WSK NPI that it would like to
use in the
**Version** member of the
[WSK_CLIENT_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_dispatch) structure. The WSK
application should specify the remaining members of the WSK_CLIENT_DISPATCH structure to conform with the
version of the WSK NPI that is specified in the
**Version** member of the structure.

For more information about attaching a WSK application to the WSK subsystem, see
[Registering a Winsock Kernel
Application](https://learn.microsoft.com/windows-hardware/drivers/network/registering-a-winsock-kernel-application).

## See also

[WSK_CLIENT_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_dispatch)

[WSK_CLIENT_NPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_npi)

[WskCaptureProviderNPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskcaptureprovidernpi)

[WskQueryProviderCharacteristics](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskqueryprovidercharacteristics)

[WskRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskregister)