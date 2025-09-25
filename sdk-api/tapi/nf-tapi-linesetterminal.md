# lineSetTerminal function

## Description

The
**lineSetTerminal** function enables an application to specify which terminal information related to the specified line, address, or call is to be routed. The
**lineSetTerminal** function can be used while calls are in progress on the line to allow an application to route these events to different devices as required.

## Parameters

### `hLine`

Handle to an open line device.

### `dwAddressID`

Address on the given open line device. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `hCall`

Handle to a call. The call state of *hCall* can be any state, if *dwSelect* is CALL.

### `dwSelect`

Whether the terminal setting is requested for the line, the address, or just the specified call. If line or address is specified, events either apply to the line or address itself or serve as a default initial setting for all new calls on the line or address. This parameter uses one of the
[LINECALLSELECT_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallselect--constants).

### `dwTerminalModes`

Class of low-level events to be routed to the given terminal. This parameter uses one or more of the
[LINETERMMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linetermmode--constants).

### `dwTerminalID`

Device identifier of the terminal device where the given events are to be routed. Terminal identifiers are small integers in the range of zero to one less than **dwNumTerminals**, where **dwNumTerminals**, and the terminal modes each terminal is capable of handling, are returned by
[lineGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevcaps).

These terminal identifiers have no relation to other device identifiers and are defined by the service provider using device capabilities.

### `bEnable`

If **TRUE**, *dwTerminalID* is valid and the specified event classes are routed to or from that terminal. If **FALSE**, these events are not routed to or from the terminal device with identifier equal to *dwTerminalID*.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_INVALADDRESSID, LINEERR_NOMEM, LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLSELECT, LINEERR_OPERATIONFAILED, LINEERR_INVALLINEHANDLE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALTERMINALID, LINEERR_UNINITIALIZED, LINEERR_INVALTERMINALMODE.

## Remarks

An application can use this function to route certain classes of low-level line events to the specified terminal device or to suppress the routing of these events. For example, voice can be routed to an audio I/O device (headset), lamps and display events can be routed to the local phone device, and button events and ringer events can be suppressed altogether.

This function can be called at any time, even when a call is active on the given line device. This allows a user to switch from using the local phone set to another audio I/O device. This function can be called multiple times to route the same events to multiple terminals simultaneously. To reroute events to a different terminal, the application should first disable routing to the existing terminal and then route the events to the new terminal.

Terminal identifier assignments are made by the line's service provider. Device capabilities indicate only which terminal identifiers the service provider has available. Service providers that do not support this type of event routing would indicate that they have no terminal devices (**dwNumTerminals** in
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) would be zero).

Invoking
**lineSetTerminal** on a line or address affects all existing calls on that line or address, but does not affect calls on other addresses. It also sets the default for future calls on that line or address. A line or address that has multiple connected calls active at one time can have different routing in effect for each call.

Disabling the routing of low-level events to a terminal when these events are not currently routed to or from that terminal does not necessarily generate an error so long as the function succeeds (the specified events are not routed to or from that terminal).

TAPI routes call progress tones and messages to the same location as set by the
**lineSetTerminal** function for "media". For example, if audio signals are going to the phone, then so will busy signals (analog) or Q.931 messages indicating busy (digital).

## See also

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevcaps)