## Description

The **DRT_SETTINGS** structure contains the settings utilized by the local Distributed Routing Table.

## Members

### `dwSize`

The size of the structure specified by the *sizeof* parameter found in **DRT_SETTINGS** with the purpose of allowing new fields in the structure in future versions of the DRT API.

### `cbKey`

Specifies the exact number of bytes for keys in this DRT instance. Currently only 8 bytes are supported. Any other values will return **E_INVALIDARG** via the [DrtOpen](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtopen) function.

### `bProtocolMajorVersion`

Pointer to the byte array that represents the protocol major version specified by the application. This is packed in every DRT packet to identify the version of the Security or Bootstrap Providers in use when a single DRT instance is supporting multiple Security or Bootstrap Providers.

### `bProtocolMinorVersion`

Pointer to the byte array that represents the protocol minor version specified by the application.
This is packed in every DRT packet to identify the version of the Security or Bootstrap Providers in use when a single DRT instance is supporting multiple Security or Bootstrap Providers.

### `ulMaxRoutingAddresses`

Specifies the maximum number of address the DRT registers when an application registers a key. The maximum value for this field is 4.

### `pwzDrtInstancePrefix`

This string forms the basis of the name of the DRT instance. The name of the instance can be used to locate the Windows performance counters associated with it.

### `hTransport`

Handle to a transport created by the transport creation API. This is used to open a DRT with a transport specified by the **DRT_SETTINGS** structure. Currently only IPv6 UDP is supported via [DrtCreateIpv6UdpTransport](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtcreateipv6udptransport).

### `pSecurityProvider`

Pointer to the security provider specified for use. An instance of the Derived Key Security Provider can be obtained by calling [DrtCreateDerivedKeySecurityProvider](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtcreatederivedkeysecurityprovider).

### `pBootstrapProvider`

Pointer to the Bootstrap Provider specified for use. An instance of the PNRP Bootstrap Provider can be obtained by calling [DrtCreatePnrpBootstrapResolver](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtcreatepnrpbootstrapresolver).

### `eSecurityMode`

Specifies the security mode that the DRT should operate under. All nodes participating in a DRT mesh must use the same security mode.

## See also

[DrtCreateIpv6UdpTransport](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtcreateipv6udptransport)

[DrtCreatePnrpBootstrapResolver](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtcreatepnrpbootstrapresolver)

[DrtOpen](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtopen)