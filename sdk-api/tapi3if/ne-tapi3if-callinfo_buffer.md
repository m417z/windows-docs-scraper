# CALLINFO_BUFFER enumeration

## Description

The
**CALLINFO_BUFFER** enum indicates the type of buffer accessed by the
[ITCallInfo::GetCallInfoBuffer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-getcallinfobuffer) method or the
[ITCallInfo::SetCallInfoBuffer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-setcallinfobuffer) method.

The
[ITCallInfo::get_CallInfoBuffer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-get_callinfobuffer) and
[ITCallInfo::put_CallInfoBuffer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-put_callinfobuffer) methods are provided for Automation client applications, such as those written in Visual Basic.

## Constants

### `CIB_USERUSERINFO:0`

The user-user information buffer allows an application to send information to the remote party on a call or receive information from that party.

### `CIB_DEVSPECIFICBUFFER`

The device-specific buffer allows an application to communicate with a TSP concerning device-specific capabilities. The precise nature of these capabilities depends on the implementation of the service provider.

### `CIB_CALLDATABUFFER`

The call data buffer allows an application to communicate with a TSP concerning a specific call. The precise nature of this information depends on the implementation of the service provider.

### `CIB_CHARGINGINFOBUFFER`

The charging information buffer's format is specified by other standards (ISDN Q.931).

### `CIB_HIGHLEVELCOMPATIBILITYBUFFER`

The high-level compatibility buffer's format is specified by other standards (ISDN Q.931).

### `CIB_LOWLEVELCOMPATIBILITYBUFFER`

The low-level compatibility buffer's format is specified by other standards (ISDN Q.931).

## See also

[ITCallInfo::GetCallInfoBuffer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-getcallinfobuffer)

[ITCallInfo::SetCallInfoBuffer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-setcallinfobuffer)

[ITCallInfo::get_CallInfoBuffer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-get_callinfobuffer)

[ITCallInfo::put_CallInfoBuffer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-put_callinfobuffer)