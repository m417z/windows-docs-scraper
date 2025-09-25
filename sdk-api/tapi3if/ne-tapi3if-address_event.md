# ADDRESS_EVENT enumeration

## Description

The
**ADDRESS_EVENT** enum describes address events. The
[ITAddressEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddressevent-get_event) method returns a member of this enum to indicate the type of address event that occurred.

## Constants

### `AE_STATE:0`

The address state has changed. See
[ITAddress::get_State](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-get_state).

### `AE_CAPSCHANGE`

Address capabilities have changed. See
[capability flags](https://learn.microsoft.com/windows/desktop/Tapi/lineaddrcapflags--constants).

### `AE_RINGING`

There is ringing on the address.

### `AE_CONFIGCHANGE`

The address configuration has changed.

### `AE_FORWARD`

Forwarding has changed. See
[ITAddress::get_CurrentForwardInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-get_currentforwardinfo).

### `AE_NEWTERMINAL`

A new terminal has been added. The application should respond by selecting the terminal if it is going to be used on an active call.

### `AE_REMOVETERMINAL`

A terminal has been removed. The application should respond by unselecting the terminal if it is currently selected to an active call.

### `AE_MSGWAITON`

The message waiting indicator has been turned on. This applies only to phone addresses.

### `AE_MSGWAITOFF`

The message waiting indicator has been turned off. This applies only to phone addresses.

### `AE_LASTITEM`

Last item in this enum.

## Remarks

Certain events on PnP devices will not be received until after the first time static terminals are enumerated using
[ITTerminalSupport::EnumerateStaticTerminals](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminalsupport-enumeratestaticterminals) or
[ITTerminalSupport::get_StaticTerminals](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminalsupport-get_staticterminals).

## See also

[Event Notification
overview](https://learn.microsoft.com/windows/desktop/Tapi/event-notification)

[ITAddressEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddressevent-get_event)

[ITCallNotificationEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallnotificationevent)