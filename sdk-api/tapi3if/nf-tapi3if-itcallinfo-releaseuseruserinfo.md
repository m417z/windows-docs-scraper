# ITCallInfo::ReleaseUserUserInfo

## Description

The
**ReleaseUserUserInfo** method informs the service provider that the application has processed the user-user information obtained from the
[ITCallInfo::GetCallInfoBuffer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-getcallinfobuffer) method, called with the CIB_USERUSERINFO member of
[CALLINFO_BUFFER](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-callinfo_buffer), and subsequently received user-user information can now be written.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## See also

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo)