# TAPI_EVENT enumeration

## Description

The
**TAPI_EVENT** enumeration is used to notify an application that a change has occurred in the TAPI object. The
[ITTAPIEventNotification::Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapieventnotification-event) method implementation uses members of this enumeration to indicate the type of object associated with the **IDispatch** pointer passed by TAPI.

## Constants

### `TE_TAPIOBJECT:0x1`

Change is in TAPI object itself. For more information, see
[ITTAPIObjectEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapiobjectevent).

### `TE_ADDRESS:0x2`

An Address object has changed. For more information, see
[ITAddressEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddressevent).

### `TE_CALLNOTIFICATION:0x4`

A new communications session has appeared on the address and the TAPI DLL has created a new call object. This could be a result from an incoming session, a session handed off by another application, or a session being parked on the address. For more information, see
[ITCallNotificationEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallnotificationevent) and
[ITTAPI::RegisterCallNotifications](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-registercallnotifications).

### `TE_CALLSTATE:0x8`

The Call state has changed. For more information, see
[ITCallStateEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallstateevent).

### `TE_CALLMEDIA:0x10`

The media associated with a call has changed. For more information, see
[ITCallMediaEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallmediaevent).

### `TE_CALLHUB:0x20`

A CallHub object has changed. For more information, see
[ITCallHubEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallhubevent).

### `TE_CALLINFOCHANGE:0x40`

The call information has changed.
For more information, see [ITCallInfoChangeEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfochangeevent).

### `TE_PRIVATE:0x80`

A provider-specific private object has changed. The precise type of object referenced is implementation dependent. For more information, see [Provider-Specific Interfaces](https://learn.microsoft.com/windows/desktop/Tapi/provider-specific-interfaces).

### `TE_REQUEST:0x100`

A Request object has changed. For more information, see [ITRequestEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itrequestevent).

### `TE_AGENT:0x200`

An Agent object has changed. For more information, see [ITAgentEvent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentevent).

### `TE_AGENTSESSION:0x400`

An AgentSession object has changed. For more information, see [ITAgentSessionEvent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentsessionevent).

### `TE_QOSEVENT:0x800`

A QOS event has occurred. For more information, see [ITQOSEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itqosevent).

### `TE_AGENTHANDLER:0x1000`

An AgentHandler object has changed. For more information, see [ITAgentHandlerEvent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagenthandlerevent).

### `TE_ACDGROUP:0x2000`

An ACDGroup object has changed. For more information, see [ITACDGroupEvent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itacdgroupevent).

### `TE_QUEUE:0x4000`

A Queue object has changed. For more information, see [ITQueueEvent](https://learn.microsoft.com/windows/desktop/api/tapi3cc/nn-tapi3cc-itqueueevent).

### `TE_DIGITEVENT:0x8000`

A digit event has occurred. For more information, see [ITDigitDetectionEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdigitdetectionevent).

### `TE_GENERATEEVENT:0x10000`

A digit generation event has occurred. For more information, see [ITDigitGenerationEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdigitgenerationevent).

### `TE_ASRTERMINAL:0x20000`

An Automatic Speech Recognition terminal event has occurred. Valid only for computers running on Windows XP and later.

### `TE_TTSTERMINAL:0x40000`

An event has occurred on a TTS terminal. For more information, see [ITTTSTerminalEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itttsterminalevent). Valid only for computers running on Windows XP and later.

### `TE_FILETERMINAL:0x80000`

An event has occurred on a file terminal. For more information, see [ITFileTerminalEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itfileterminalevent). Valid only for computers running on Windows XP and later.

### `TE_TONETERMINAL:0x100000`

An event has occurred on a tone terminal. For more information, see [ITToneTerminalEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittoneterminalevent). Valid only for computers running on Windows XP and later.

### `TE_PHONEEVENT:0x200000`

A Phone object has changed. For more information, see
[ITPhoneEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphoneevent). Valid only for computers running on Windows XP and later.

### `TE_TONEEVENT:0x400000`

A tone event has been fired. Detection of in-band tones will be enabled or disabled. For more information, see
[ITToneDetectionEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittonedetectionevent). Valid only for computers running on Windows XP and later.

### `TE_GATHERDIGITS:0x800000`

A gather digits event has been fired. Digits will be gathered on the current call. For more information, see
[ITDigitsGatheredEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdigitsgatheredevent). Valid only for computers running on Windows XP and later.

### `TE_ADDRESSDEVSPECIFIC:0x1000000`

An address device-specific event has occurred. For more information, see [ITAddressDeviceSpecificEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddressdevicespecificevent). Valid only for computers running on Windows XP and later.

### `TE_PHONEDEVSPECIFIC:0x2000000`

A phone device-specific event has occurred. For more information, see [ITPhoneDeviceSpecificEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddressdevicespecificevent). Valid only for computers running on Windows XP and later.

## Remarks

Call the
[ITTAPI::put_EventFilter](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-put_eventfilter) method and set the event filter mask to enable receiving events. If **ITTAPI::put_EventFilter** is not called, the application cannot receive events.

## See also

[ITACDGroupEvent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itacdgroupevent)

[ITAddressEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddressevent)

[ITAgentEvent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentevent)

[ITAgentHandlerEvent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagenthandlerevent)

[ITAgentSessionEvent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentsessionevent)

[ITCallHubEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallhubevent)

[ITCallInfoChangeEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfochangeevent)

[ITCallMediaEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallmediaevent)

[ITCallNotificationEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallnotificationevent)

[ITCallStateEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallstateevent)

[ITQOSEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itqosevent)

[ITQueueEvent](https://learn.microsoft.com/windows/desktop/api/tapi3cc/nn-tapi3cc-itqueueevent)

[ITRequestEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itrequestevent)

[ITTAPI::RegisterCallNotifications](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-registercallnotifications)

[ITTAPIEventNotification::Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapieventnotification-event)

[ITTAPIObjectEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapiobjectevent)