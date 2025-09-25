# CALL_PRIVILEGE enumeration

## Description

A
**CALL_PRIVILEGE** member is returned by the
[ITCallInfo::get_Privilege](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-get_privilege) method, and indicates when the current application owns or is monitoring the current call.

## Constants

### `CP_OWNER:0`

The application is the owner of the call.

### `CP_MONITOR`

The application is a monitor of the call.

## See also

[ITCallInfo::get_Privilege](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-get_privilege)