# ADDRESS_CAPABILITY enumeration

## Description

A member of the
**ADDRESS_CAPABILITY** enum is used by the
[ITAddressCapabilities::get_AddressCapability](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddresscapabilities-get_addresscapability) method to indicate the address capability required.

## Constants

### `AC_ADDRESSTYPES:0`

An address may support more than one
[address type](https://learn.microsoft.com/windows/desktop/Tapi/lineaddresstype--constants), but please note that one may be used during
[ITAddress::CreateCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-createcall).

### `AC_BEARERMODES`

[Bearer modes](https://learn.microsoft.com/windows/desktop/Tapi/linebearermode--constants).

### `AC_MAXACTIVECALLS`

The maximum number of (minimum bandwidth) calls that can be active (connected) on the line at any one time. The actual number of active calls can be lower if higher bandwidth calls are established on the line.

### `AC_MAXONHOLDCALLS`

Maximum number of calls that can be on hold at once.

### `AC_MAXONHOLDPENDINGCALLS`

Maximum number of calls that can be simultaneously pending transfer or conference.

### `AC_MAXNUMCONFERENCE`

Contains the maximum number of parties that can join a single conference call on this address.

### `AC_MAXNUMTRANSCONF`

Specifies the number of parties (including "self") that can be added in a conference call that is initiated as a generic consultation call using
[ITBasicCallControl::Transfer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-transfer) and
[ITBasicCallControl::Finish](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-finish) (FM_ASCONFERENCE).

### `AC_MONITORDIGITSUPPORT`

Specifies digit modes detectable on this address using the
[LINEDIGITMODE_](https://learn.microsoft.com/windows/desktop/Tapi/linedigitmode--constants) flags. If no flag is set, digit monitoring is not supported.

### `AC_GENERATEDIGITSUPPORT`

Specifies digit modes that can be generated on this address using a subset of the
[LINEDIGITMODE_](https://learn.microsoft.com/windows/desktop/Tapi/linedigitmode--constants) flags: LINEDIGITMODE_PULSE indicates digits can be generated as pulse/rotary tones, and LINEDIGITMODE_DTMF indicates digits can be generated as DTMF tones. If no flag is set, digit generation is not supported.

### `AC_GENERATETONEMODES`

Specifies the different kinds of tones that can be generated on this line, of type
[LINETONEMODE_](https://learn.microsoft.com/windows/desktop/Tapi/linetonemode--constants).

### `AC_GENERATETONEMAXNUMFREQ`

Contains the maximum number of frequencies that can be specified in describing a general tone.

### `AC_MONITORTONEMAXNUMFREQ`

Contains the maximum number of frequencies that can be specified when monitoring a general tone. A value of 0 indicates that tone monitor is not available.

### `AC_MONITORTONEMAXNUMENTRIES`

Contains the maximum number of entries that can be specified in a tone list.

### `AC_DEVCAPFLAGS`

[Device capability flags](https://learn.microsoft.com/windows/desktop/Tapi/linedevcapflags--constants).

### `AC_ANSWERMODES`

[Answer modes](https://learn.microsoft.com/windows/desktop/Tapi/lineanswermode--constants).

### `AC_LINEFEATURES`

Specifies the features available for this line using the
[LINEFEATURE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linefeature--constants). Invoking a supported feature requires the line to be in the proper state and the underlying line device to be opened in a compatible mode. A zero in a bit position indicates that the corresponding feature is never available. A one indicates that the corresponding feature may be available if the line is in the appropriate state for the operation to be meaningful. This member allows an application to discover which line features can be (and which can never be) supported by the device.

### `AC_SETTABLEDEVSTATUS`

Indicates
[LINEDEVSTATUS_](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevstatus) values that can be modified.

### `AC_PARKSUPPORT`

Indicates whether park is supported using the
[LINEPARKMODE_](https://learn.microsoft.com/windows/desktop/Tapi/lineparkmode--constants) flags.

### `AC_CALLERIDSUPPORT`

Identifies support for caller number identification using the
[LINECALLPARTYID_](https://learn.microsoft.com/windows/desktop/Tapi/linecallpartyid--constants) flags.

### `AC_CALLEDIDSUPPORT`

Identifies support for called number identification using the
[LINECALLPARTYID_](https://learn.microsoft.com/windows/desktop/Tapi/linecallpartyid--constants) flags.

### `AC_CONNECTEDIDSUPPORT`

Indicates whether connected ID is supported using the
[LINECALLPARTYID_](https://learn.microsoft.com/windows/desktop/Tapi/linecallpartyid--constants) flags.

### `AC_REDIRECTIONIDSUPPORT`

Indicates whether redirection ID is supported using the
[LINECALLPARTYID_](https://learn.microsoft.com/windows/desktop/Tapi/linecallpartyid--constants) flags.

### `AC_REDIRECTINGIDSUPPORT`

Indicates whether redirecting ID is supported using the
[LINECALLPARTYID_](https://learn.microsoft.com/windows/desktop/Tapi/linecallpartyid--constants) flags.

### `AC_ADDRESSCAPFLAGS`

The address
[capability flags](https://learn.microsoft.com/windows/desktop/Tapi/lineaddrcapflags--constants) describe various Boolean address capabilities. For example, LINEADDRCAPFLAGS_FWDNUMRINGS indicates whether the number of rings for a no-answer can be specified when forwarding on a no-answer.

### `AC_CALLFEATURES1`

[Call feature set one](https://learn.microsoft.com/windows/desktop/Tapi/linecallfeature--constants).

### `AC_CALLFEATURES2`

[Supplemental call features](https://learn.microsoft.com/windows/desktop/Tapi/linecallfeature2--constants) for conferencing, transferring, and parking calls.

### `AC_REMOVEFROMCONFCAPS`

Specifies the address's capabilities for removing calls from a conference call. This member uses the
[LINEREMOVEFROMCONF_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineremovefromconf--constants).

### `AC_REMOVEFROMCONFSTATE`

Uses the
[LINECALLSTATE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallstate--constants) to specify the state of the call after it has been removed from a conference call.

### `AC_TRANSFERMODES`

[Transfer modes](https://learn.microsoft.com/windows/desktop/Tapi/linetransfermode--constants).

### `AC_ADDRESSFEATURES`

The
[line address features](https://learn.microsoft.com/windows/desktop/Tapi/lineaddrfeature--constants) describe operations that can be invoked on an address. For example, if LINEADDRFEATURE_FORWARD is set, the address can be forwarded.

### `AC_PREDICTIVEAUTOTRANSFERSTATES`

The call state or states upon which a call made by a predictive dialer can be set to automatically transfer the call to another address; one or more of the
[LINECALLSTATE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallstate--constants). The value 0 indicates automatic transfer based on call state is unavailable.

### `AC_MAXCALLDATASIZE`

Maximum data block size allowed.

### `AC_LINEID`

Returns the device identifier of the line device with which this address is associated. TAPI 2.1 cross-reference:
[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps).

### `AC_ADDRESSID`

Address identifier. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `AC_FORWARDMODES`

[Forwarding modes](https://learn.microsoft.com/windows/desktop/Tapi/lineforwardmode--constants).

### `AC_MAXFORWARDENTRIES`

The maximum number of different forwarding entries that can be supported by the current address.

### `AC_MAXSPECIFICENTRIES`

Specifies the maximum number of entries that can be set using
[ITForwardInformation::SetForwardType](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itforwardinformation-setforwardtype) that can contain forwarding instructions based on a specific caller (selective call forwarding). This member is zero if selective call forwarding is not supported.

### `AC_MINFWDNUMRINGS`

Specifies the minimum number of rings that can be set to determine when a call is officially considered "no answer."

### `AC_MAXFWDNUMRINGS`

Specifies the maximum number of rings that can be set to determine when a call is officially considered "no answer."

### `AC_MAXCALLCOMPLETIONS`

The maximum number of concurrent call completion requests that can be outstanding on this address. Zero implies that call completion is not available.

### `AC_CALLCOMPLETIONCONDITIONS`

[Call completion conditions](https://learn.microsoft.com/windows/desktop/Tapi/linecallcomplcond--constants).

### `AC_CALLCOMPLETIONMODES`

[Call completion modes](https://learn.microsoft.com/windows/desktop/Tapi/linecallcomplmode--constants).

### `AC_PERMANENTDEVICEID`

The permanent identifier by which the line device is known in the system's configuration. This value does not change as lines are added and removed from the system. It can therefore be used to link line-specific information in the registry or other files in a way that is not affected by changes in other lines. If a line has more than one address, all addresses will have the same permanent device identifier. TSP writers should note that this value must be preserved across operating system upgrades.

### `AC_GATHERDIGITSMINTIMEOUT`

### `AC_GATHERDIGITSMAXTIMEOUT`

### `AC_GENERATEDIGITMINDURATION`

### `AC_GENERATEDIGITMAXDURATION`

### `AC_GENERATEDIGITDEFAULTDURATION`

## See also

[Address object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)

[ITAddressCapabilities::get_AddressCapability](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddresscapabilities-get_addresscapability)