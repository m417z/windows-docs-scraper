# FWPS_TRANSPORT_SEND_PARAMS1_ structure

## Description

The **FWPS_TRANSPORT_SEND_PARAMS1** structure defines properties of an outbound transport layer
packet.

**Note** **FWPS_TRANSPORT_SEND_PARAMS1** is the specific version of **FWPS_TRANSPORT_SEND_PARAMS** used in Windows 7 and later. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information. For Windows Vista, [FWPS_TRANSPORT_SEND_PARAMS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_transport_send_params0_) is available.

## Members

### `remoteAddress`

A pointer to a buffer that specifies the remote IP address to which the socket needs to be sent.
The remote address specified by this member can be different than the one passed as one of the incoming
data values to the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function.

The buffer can contain an IPv4 address (4 bytes) or an IPv6 address (16 bytes), and the address must
be specified in network byte order. The IP version must match the
*AddressFamily* parameter specified in the
[FwpsInjectTransportSendAsync1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjecttransportsendasync1) function.

The buffer must remain valid until the injection completion function is called.

### `remoteScopeId`

A **SCOPE_ID** structure that contains the scope identifier for the remote IP address. The scope
identifier is provided to a callout through the
**remoteScopeId** member of the
[FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_) structure that is passed to the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function. The **SCOPE_ID**
structure is defined in
Ws2ipdef.h as follows.

```
typedef struct {
  union {
    struct {
      ULONG  Zone : 28;
      ULONG  Level : 4;
    };
    ULONG  Value;
  };
} SCOPE_ID, *PSCOPE_ID;
```

### `controlData`

An optional pointer to a buffer that contains socket control data specified by the
[WSASendMsg](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsasendmsg) function. For information about the **WSACMSGHDR** type, see
[CMSGHDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsacmsghdr).

If present, socket control data is provided to a callout with the
**controlData** member of the
[FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_) structure that is passed to the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function.

If socket control data is not **NULL**, it must be deep-copied in the callout driver's implementation
of the
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) function, and the
**controlData** buffer must be kept valid until the injection completion
function is called.

### `controlDataLength`

The length, in bytes, of the
**controlData** member.

### `headerIncludeHeader`

The transport header to include.

### `headerIncludeHeaderLength`

The length, in bytes, of the
**headerIncludeHeader** member.

## See also

[CMSGHDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsacmsghdr)

[FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_)

[FwpsInjectTransportSendAsync1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjecttransportsendasync1)

[WSASendMsg](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsasendmsg)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)