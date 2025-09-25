# FwpsInjectionHandleCreate0 function

## Description

The
**FwpsInjectionHandleCreate0** function creates a handle that can be used by
[packet injection functions](https://learn.microsoft.com/windows-hardware/drivers/network/packet-injection-functions) to inject
packet or stream data into the TCP/IP network stack and by the
[FwpsQueryPacketInjectionState0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsquerypacketinjectionstate0) function to query the packet injection state.

**Note** **FwpsInjectionHandleCreate0** is a specific version of **FwpsInjectionHandleCreate**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `addressFamily` [in, optional]

The address family for which the injection handle is being created. This can be one of the
following address families:

#### AF_UNSPEC

The address family is unspecified.

#### AF_INET

The IPv4 address family.

#### AF_INET6

The IPv6 address family.

For transport, stream, and forward injections, this parameter is optional and can be set to
AF_UNSPEC, which indicates an unspecified address family. This value is defined in
Ws2def.h.

### `flags` [in]

A flag value set by a callout driver to indicate the type of data to be injected. This flag can have
one or more of the following values:

#### FWPS_INJECTION_TYPE_FORWARD

Packet data will be injected by calling the
[FwpsInjectForwardAsync0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectforwardasync0) function.

#### FWPS_INJECTION_TYPE_NETWORK

Network data will be injected by calling either the
[FwpsInjectNetworkReceiveAsync0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectnetworkreceiveasync0) function or the
[FwpsInjectNetworkSendAsync0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectnetworksendasync0) function.

#### FWPS_INJECTION_TYPE_STREAM

Stream data will be injected by calling the
[FwpsStreamInjectAsync0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsstreaminjectasync0) function.

#### FWPS_INJECTION_TYPE_TRANSPORT

Transport data will be injected by calling either the
[FwpsInjectTransportReceiveAsync0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjecttransportreceiveasync0) function or the
[FwpsInjectTransportSendAsync0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjecttransportsendasync0) function.

 To create an injection handle to be used by multiple injection functions, combine the
injection type bits with bitwise OR operations. If the flag value is set to zero, the resulting
injection handle can be used for transport, stream, and forward injections.

### `injectionHandle` [out]

A pointer to a variable that receives the handle.

## Return value

The
**FwpsInjectionHandleCreate0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The injection handle was successfully created. |
| **STATUS_FWP_TCPIP_NOT_READY** | The TCP/IP network stack is not ready. A callout driver should call the [FwpsInjectionHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandlecreate0) function again at a later time to create an injection handle. |
| **Other status codes** | An error occurred. |

## Remarks

A callout driver calls the
**FwpsInjectionHandleCreate0** function to create a handle that can be used for injecting packet or
stream data into the TCP/IP network stack and to query the packet injection state. A callout driver
passes the created handle to the
[packet injection
functions](https://learn.microsoft.com/windows-hardware/drivers/network/packet-injection-functions) and
[FwpsQueryPacketInjectionState0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsquerypacketinjectionstate0).

After a callout driver has finished using an injection handle, it must call the
[FwpsInjectionHandleDestroy0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandledestroy0) function to destroy the handle. If pending injections have not yet
completed, this function will wait for their completion before returning.

When injections are being made to the network layer and both IPv4 and IPv6 address families are being
filtered, the callout driver must create two injection handles by calling the
**FwpsInjectionHandleCreate0** function twice: one call with
*addressFamily* set to AF_INET, and a second call with
*addressFamily* set to AF_INET6.

For the MAC layers ( *MAC_FRAME_NATIVE, *MAC_FRAME_ETHERNET, *VSWITCH_ETHERNET), you can use the same injection handle acquired with the FWPS_INJECTION_TYPE_L2 flag. The Injection type is tied closer to the injection functions than the layers.

For a code example, see [WFPSampler HelperFunctions_InjectionData.cpp](https://github.com/microsoft/Windows-driver-samples/blob/master/network/trans/WFPSampler/syslib/HelperFunctions_InjectionData.cpp).

## See also

[FwpsInjectionHandleDestroy0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandledestroy0)

[FwpsQueryPacketInjectionState0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsquerypacketinjectionstate0)

[Packet Injection Functions](https://learn.microsoft.com/windows-hardware/drivers/network/packet-injection-functions)