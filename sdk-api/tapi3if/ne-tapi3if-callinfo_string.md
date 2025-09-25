# CALLINFO_STRING enumeration

## Description

The
**CALLINFO_STRING** enum is used by
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) methods that set and get call information involving the use of strings.

## Constants

### `CIS_CALLERIDNAME:0`

The name of the caller.

### `CIS_CALLERIDNUMBER`

The number of the caller.

### `CIS_CALLEDIDNAME`

The name of the called location.

### `CIS_CALLEDIDNUMBER`

The number of the called location.

### `CIS_CONNECTEDIDNAME`

The name of the connected location.

### `CIS_CONNECTEDIDNUMBER`

The number of the connected location.

### `CIS_REDIRECTIONIDNAME`

The name of the location to which a call has been redirected.

### `CIS_REDIRECTIONIDNUMBER`

The number of the location to which a call has been redirected.

### `CIS_REDIRECTINGIDNAME`

The name of the location that redirected the call.

### `CIS_REDIRECTINGIDNUMBER`

The number of the location that redirected the call.

### `CIS_CALLEDPARTYFRIENDLYNAME`

The called party friendly name.

### `CIS_COMMENT`

A comment about the call provided by the application that originated the call. The call state must be CS_IDLE when setting the comment.

### `CIS_DISPLAYABLEADDRESS`

A displayable version of the called or calling address.

### `CIS_CALLINGPARTYID`

The identifier of the calling party.

## See also

[ITCallInfo::get_CallInfoString](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-get_callinfostring)

[ITCallInfo::put_CallInfoString](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-put_callinfostring)