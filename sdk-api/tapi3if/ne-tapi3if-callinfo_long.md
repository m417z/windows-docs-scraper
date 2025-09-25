# CALLINFO_LONG enumeration

## Description

The
**CALLINFO_LONG** enum is used by
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) methods that set and get call information of type **LONG**.

## Constants

### `CIL_MEDIATYPESAVAILABLE:0`

The
[media types](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) available on the call.

### `CIL_BEARERMODE`

The bearer mode of a call is described by the
[LINEBEARERMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linebearermode--constants).

### `CIL_CALLERIDADDRESSTYPE`

The
[address type](https://learn.microsoft.com/windows/desktop/Tapi/lineaddresstype--constants) of the caller.

### `CIL_CALLEDIDADDRESSTYPE`

The
[address type](https://learn.microsoft.com/windows/desktop/Tapi/lineaddresstype--constants) of the called party.

### `CIL_CONNECTEDIDADDRESSTYPE`

The
[address type](https://learn.microsoft.com/windows/desktop/Tapi/lineaddresstype--constants) of the connected party.

### `CIL_REDIRECTIONIDADDRESSTYPE`

The
[address type](https://learn.microsoft.com/windows/desktop/Tapi/lineaddresstype--constants) of the destination to which a call has been redirected.

### `CIL_REDIRECTINGIDADDRESSTYPE`

The
[address type](https://learn.microsoft.com/windows/desktop/Tapi/lineaddresstype--constants) of the location that redirected the call.

### `CIL_ORIGIN`

The origin of a call is described by the
[LINECALLORIGIN_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallorigin--constants), such as LINECALLORIGIN_EXTERNAL.

### `CIL_REASON`

The reason for a call is described by the
[LINECALLREASON_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallreason--constants), such as LINECALLREASON_FWDUNCOND.

### `CIL_APPSPECIFIC`

Application-specific information is used to pass information between applications in a multi-application environment. The information is not interpreted by the API implementation or the service provider. Only applications with owner privileges for the call can set it.

### `CIL_CALLPARAMSFLAGS`

Call parameter flags are described by
[LINECALLPARAMFLAGS_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallparamflags--constants), such as LINECALLPARAMFLAGS_BLOCKID. These flags are normally set during the creation of an outgoing call.

### `CIL_CALLTREATMENT`

Call treatment identifies how a call that is on hold or unanswered gets handled, and is described by
[LINECALLTREATMENT_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linecalltreatment--constants), such as LINECALLTREATMENT_MUSIC.

### `CIL_MINRATE`

The minimum rate for a call's data stream in bps (bits per second).

### `CIL_MAXRATE`

The maximum rate for a call's data stream in bps (bits per second).

### `CIL_COUNTRYCODE`

Country or region code.

### `CIL_CALLID`

Call identifier. Some service providers assign a unique code to each call.

### `CIL_RELATEDCALLID`

Call identifier for a call related to the current call, such as on a conference.

### `CIL_COMPLETIONID`

Completion identifier. The completion identifier is used to identify individual completion requests in progress. A completion identifier becomes invalid and can be reused after the request completion or after an outstanding request is canceled.

### `CIL_NUMBEROFOWNERS`

The number of applications having owner privileges for the current call.

### `CIL_NUMBEROFMONITORS`

The number of applications having monitor privileges for the current call.

### `CIL_TRUNK`

The trunk identifier for the current call.

### `CIL_RATE`

The current rate for a call's data stream in bps (bits per second).

### `CIL_GENERATEDIGITDURATION`

### `CIL_MONITORDIGITMODES`

### `CIL_MONITORMEDIAMODES`

## See also

[ITCallInfo::get_CallInfoLong](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-get_callinfolong)

[ITCallInfo::put_CallInfoLong](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-put_callinfolong)