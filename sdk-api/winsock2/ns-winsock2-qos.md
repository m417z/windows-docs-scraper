# QOS structure

## Description

The
**QOS** structure provides the means by which QOS-enabled applications can specify quality of service parameters for sent and received traffic on a particular flow.

## Members

### `SendingFlowspec`

Specifies QOS parameters for the sending direction of a particular flow. SendingFlowspec is sent in the form of a
[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structure.

### `ReceivingFlowspec`

Specifies QOS parameters for the receiving direction of a particular flow. ReceivingFlowspec is sent in the form of a
[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structure.

### `ProviderSpecific`

Pointer to a structure of type
[WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) that can provide additional provider-specific quality of service parameters to the RSVP SP for a given flow.

## Remarks

Most applications can fulfill their quality of service requirements without using the
[ProviderSpecific](https://learn.microsoft.com/previous-versions/aa374467(v=vs.80)) buffer. However, if the application must provide information not available with standard Windows 2000 QOS parameters, the ProviderSpecific buffer allows the application to provide additional parameters for RSVP and/or traffic control.

## See also

[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec)

[ProviderSpecific Buffer](https://learn.microsoft.com/previous-versions/aa374467(v=vs.80))