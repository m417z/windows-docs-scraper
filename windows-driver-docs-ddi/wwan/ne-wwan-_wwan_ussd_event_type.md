# _WWAN_USSD_EVENT_TYPE enumeration

## Description

The WWAN_USSD_EVENT_TYPE enumeration lists the different types of Unstructured Supplementary Service Data (USSD) events.

## Constants

### `WwanUssdEventNoActionRequired`

Indicates no further action is required or information needed.

### `WwanUssdEventActionRequired`

Indicates the USSD session is still open and further information is needed, such as additional USSD strings.

### `WwanUssdEventTerminated`

Indicates the USSD session has been terminated.

### `WwanUssdEventOtherLocalClient`

Indicates an active USSD session already exists and that a new session cannot be established until the active session terminates. This includes sessions that are invisible to the MB stack such as a USSD session termination in the Subscriber Identity Module (SIM).

### `WwanUssdEventOperationNotSupported`

Indicates that the previous request is not supported by the miniport driver or MB device.

### `WwanUssdEventNetworkTimeOut`

Indicates that the USSD session was closed due to a session time-out either locally or by the network. The miniport driver or MB device is responsible for timing out an inactive USSD session after an implementation-specific time-out.

## Remarks

Network-initiated USSD events use *WwanUssdEventActionRequired* to indicate when further information is needed after an MB device initiated operation. *WwanUssdEventActionRequired* events also indicate that the session is still open. All other events indicate that the existing USSD session has been closed.

*WwanUssdEventNoActionRequired* and *WwanUssdEventActionRequired* are the only events that require a non-empty USSD string to accompany them with a string length from 1 to 160 bytes. All other events must set the USSD string length to 0 to indicate that the string is empty.

The value of the [WWAN_USSD_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_ussd_event)**SessionState** member is ignored if no string is present.

## See also

[WWAN_USSD_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_ussd_event)