# CALLINFOCHANGE_CAUSE enumeration

## Description

The
**CALLINFOCHANGE_CAUSE** enum is used by the
[ITCallInfoChangeEvent::get_Cause](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfochangeevent-get_cause) method to return a description of the type of call information that has changed.

You can retrieve specific information about the change by using the TAPI 3
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface. TAPI 2 applications use
[lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallinfo) or
[lineGetCallStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallstatus).

## Constants

### `CIC_OTHER:0`

Unspecified call information has changed.

### `CIC_DEVSPECIFIC`

Call information specific to a device has changed.

### `CIC_BEARERMODE`

The bearer mode for the call has changed.

### `CIC_RATE`

The rate has changed.

### `CIC_APPSPECIFIC`

Call information specific to an application has changed. Application-specific information is used to pass information between applications in a multi-application environment. The information is not interpreted by the API implementation or the service provider. Only applications with owner privileges for the call can set it

### `CIC_CALLID`

The call identifier has changed.

### `CIC_RELATEDCALLID`

The related call identifier has changed.

### `CIC_ORIGIN`

The call origin has changed.

### `CIC_REASON`

The call reason has changed.

### `CIC_COMPLETIONID`

The completion identifier has changed.

### `CIC_NUMOWNERINCR`

The number of owners has increased.

### `CIC_NUMOWNERDECR`

The number of owners has decreased.

### `CIC_NUMMONITORS`

The number of call monitors has changed.

### `CIC_TRUNK`

Trunk used on call has changed.

### `CIC_CALLERID`

The caller identifier has changed.

### `CIC_CALLEDID`

The called identifier has changed.

### `CIC_CONNECTEDID`

The connected identifier has changed.

### `CIC_REDIRECTIONID`

The redirection identifier has changed.

### `CIC_REDIRECTINGID`

The redirecting identifier has changed.

### `CIC_USERUSERINFO`

The user-user information buffer has changed.

### `CIC_HIGHLEVELCOMP`

The high-level compatibility information has changed (ISDN Q.931).

### `CIC_LOWLEVELCOMP`

The low-level compatibility information has changed (ISDN Q.931).

### `CIC_CHARGINGINFO`

The call's charging information has changed.

### `CIC_TREATMENT`

Treatment of calls on hold has changed.

### `CIC_CALLDATA`

The call data buffer has changed.

### `CIC_PRIVILEGE`

[Call privilege](https://learn.microsoft.com/windows/desktop/Tapi/linecallprivilege--constants) has changed.

### `CIC_MEDIATYPE`

The call
[media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) has changed.

### `CIC_LASTITEM`

## See also

[ITCallInfoChangeEvent::get_Cause](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfochangeevent-get_cause)