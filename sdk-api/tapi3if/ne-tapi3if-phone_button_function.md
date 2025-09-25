# PHONE_BUTTON_FUNCTION enumeration

## Description

The
**PHONE_BUTTON_FUNCTION** enum provides detailed information on a button's function.

## Constants

### `PBF_UNKNOWN:0`

A "dummy" function assignment that indicates that the exact function of the button is unknown or has not been assigned.

### `PBF_CONFERENCE`

Initiates a conference call or adds a call to a conference call.

### `PBF_TRANSFER`

Initiates a call transfer or completes the transfer of a call.

### `PBF_DROP`

Drops the active call.

### `PBF_HOLD`

Places the active call on hold.

### `PBF_RECALL`

Takes a call off hold.

### `PBF_DISCONNECT`

Disconnects a call, such as after initiating a transfer.

### `PBF_CONNECT`

Reconnects a call that is on consultation hold.

### `PBF_MSGWAITON`

Turns on a message waiting lamp.

### `PBF_MSGWAITOFF`

Turns off a message waiting lamp.

### `PBF_SELECTRING`

Allows the user to select the ring pattern of the phone.

### `PBF_ABBREVDIAL`

Indicates that the number to be dialed will be a short, abbreviated number consisting of one digit or a few digits.

### `PBF_FORWARD`

Initiates or changes call forwarding to this phone.

### `PBF_PICKUP`

Picks up a call ringing on another phone.

### `PBF_RINGAGAIN`

Initiates a request to be notified if a call cannot be completed normally because of a busy signal or no answer.

### `PBF_PARK`

Parks the active call on another phone, placing it on hold there.

### `PBF_REJECT`

Rejects an incoming call before the call has been answered.

### `PBF_REDIRECT`

Redirects an incoming call to another extension before the call has been answered.

### `PBF_MUTE`

Mutes the phone's microphone device.

### `PBF_VOLUMEUP`

Increases the volume of audio through the phone's handset speaker or speakerphone.

### `PBF_VOLUMEDOWN`

Decreases the volume of audio through the phone's handset speaker or speakerphone.

### `PBF_SPEAKERON`

Turns the phone's external speaker on.

### `PBF_SPEAKEROFF`

Turns the phone's external speaker off.

### `PBF_FLASH`

Generates the equivalent of an onhook/offhook sequence. A flash typically indicates that any digits typed next are to be understood as commands to the switch. On many switches, places an active call on consultation hold.

### `PBF_DATAON`

Indicates that the next call is a data call.

### `PBF_DATAOFF`

Indicates that the next call is not a data call.

### `PBF_DONOTDISTURB`

Places the phone in "do not disturb" mode; incoming calls receive a busy signal or are forwarded to an operator or voicemail system.

### `PBF_INTERCOM`

Connects to the intercom to broadcast a page.

### `PBF_BRIDGEDAPP`

Selects a particular appearance of a bridged address.

### `PBF_BUSY`

Makes the phone appear "busy" to incoming calls.

### `PBF_CALLAPP`

Selects a particular call appearance.

### `PBF_DATETIME`

Causes the phone to display the current date and time; this information would be sent by the switch.

### `PBF_DIRECTORY`

Calls up directory service from the switch.

### `PBF_COVER`

Forwards all calls destined for this phone to another phone used for coverage.

### `PBF_CALLID`

Requests display of the caller ID on the phone's display.

### `PBF_LASTNUM`

Redials the last number dialed.

### `PBF_NIGHTSRV`

Places the phone in the mode it is configured for during night hours.

### `PBF_SENDCALLS`

Sends all calls to another phone used for coverage; same as the
[PHONEBUTTONFUNCTION_COVER constant](https://learn.microsoft.com/windows/desktop/Tapi/phonebuttonfunction--constants).

### `PBF_MSGINDICATOR`

Controls the message indicator lamp.

### `PBF_REPDIAL`

Repertory dialing—the number to be dialed is provided as a shorthand following the pressing of this button.

### `PBF_SETREPDIAL`

Programs the shorthand-to-phone number mappings accessible by means of repertory dialing (the "REPDIAL" button).

### `PBF_SYSTEMSPEED`

The number to be dialed is provided as a shorthand following the pressing of this button. The mappings for system speed dialing are configured inside the switch.

### `PBF_STATIONSPEED`

The number to be dialed is provided as a shorthand following pressing of this button. The mappings for station speed dialing are specific to this station (phone).

### `PBF_CAMPON`

Camps on an extension that returns a busy indication. When the remote station returns to idle, the phone will be rung with a distinctive pattern. Picking up the local phone reinitiates the call.

### `PBF_SAVEREPEAT`

When pressed while a call or call attempt is active, it will remember that call's number or command. When pressed while no call is active (such as during dial tone), it repeats the most recently saved command.

### `PBF_QUEUECALL`

Queues a call to an outside number after it encounters a trunk-busy indication. When a trunk becomes available later, the phone will be rung with a distinctive pattern. Picking up the local phone reinitiates the call.

### `PBF_NONE`

A "dummy" function assignment that indicates that the button does not have a function.

### `PBF_SEND`

Sends a request for a communications session.

## See also

[ITPhone::get_ButtonFunction](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-get_buttonfunction)

[ITPhone::put_ButtonFunction](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-put_buttonfunction)