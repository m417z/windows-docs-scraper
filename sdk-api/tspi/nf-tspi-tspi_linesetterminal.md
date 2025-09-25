# TSPI_lineSetTerminal function

## Description

The
**TSPI_lineSetTerminal** function enables TAPI to specify to which terminal information related to the specified line, address, or call is to be routed. This operation can be used while calls are in progress on the line, to allow events to be routed to different devices as required.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdLine`

The handle to a line.

### `dwAddressID`

An address on the given open line device. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades. TAPI does not validate this parameter when this function is called.

### `hdCall`

The handle to a call. The call state can be any state (if *dwSelect* is LINECALLSELECT_CALL).

### `dwSelect`

Specifies whether the terminal setting is requested for the line, the address, or just the specified call. If line or address is specified, events either apply to the line or address itself or serve as a default initial setting for all new calls on the line or address. This parameter uses one of the
[LINECALLSELECT_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallselect--constants).

### `dwTerminalModes`

The class(es) of low level events to be routed to the given terminal. Use one of the
[LINETERMMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linetermmode--constants) for this parameter.

### `dwTerminalID`

The device identifier of the terminal device where the given events are to be routed. Terminal identifiers are small integers in the range from 0 through **dwNumTerminals** minus one, where **dwNumTerminals** and the terminal modes each terminal is capable of handling are indicated by the service provider in
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps).

**Note** These terminal identifiers have no relation to other device identifiers and are defined by the service provider through device capabilities. TAPI does not validate this parameter when this function is called.

### `bEnable`

If **TRUE**, *dwTerminalID* is valid and the specified event classes are routed to or from that terminal. If **FALSE**, these events are not routed to or from the *dwTerminalID*. TAPI does not validate this parameter when this function is called.

## Return value

Returns *dwRequestID*, or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALLINEHANDLE, LINEERR_INVALTERMINALID, LINEERR_INVALADDRESSID, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALCALLHANDLE, LINEERR_NOMEM, LINEERR_INVALCALLSELECT, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALTERMINALMODE, LINEERR_OPERATIONFAILED.

## Remarks

The service provider returns LINEERR_RESOURCEUNAVAIL if the operation cannot be completed because of resource overcommitment or if too many terminals are set, due either to hardware limitations or to service provider/device driver limitations.

TAPI can use this operation to route certain classes of low-level line events to the specified terminal device, or to suppress the routing of these events altogether. For example, voice can be routed to a separate audio I/O device (headset), lamps and display events can be routed to the local phone device, and button events and ringer events can be suppressed altogether.

Call progress tones and/or messages get routed to the same place as media. For example, if audio signals are going to the phone, then so are busy signals (analog) or Q.931 messages indicating busy (digital).

The service provider must determine whether the combinations of *dwSelect* and *dwTerminalModes* are legal.

This operation can be called any time, even when a call is active on the given line device. This, for example, allows a user to switch from using the local phone set to another audio I/O device.

This function can be called multiple times to route the same events to multiple terminals simultaneously. To reroute events to a different terminal, TAPI recommends that the application first disable routing to the existing terminal and next route the events to the new terminal. However, the service provider should make its best effort to accommodate the application's requests in any sequence.

Terminal identifier assignments are made by the service provider, and
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) indicates which terminal identifiers the service provider has available. Service providers that don't support this type of event routing indicate that they have no terminal devices (**dwNumTerminals** in
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) is set to zero).

**LineSetTerminal** on a line or address affects all existing calls on that line or address, but does not affect calls on other addresses. It also sets the default for future calls on that line or address. A line or address that has multiple connected calls active at any one time can have different routing in effect for each call.

Disabling the routing of low-level events to a terminal when these events are not currently routed to or from that terminal is not required to generate an error so long as after the function succeeds, the specified events are not routed to or from that terminal.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[LINECALLSELECT_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallselect--constants)

[LINETERMMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linetermmode--constants)