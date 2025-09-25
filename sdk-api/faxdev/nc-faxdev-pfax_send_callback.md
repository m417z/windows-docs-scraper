# PFAX_SEND_CALLBACK callback function

## Description

The *FaxSendCallback* function is an application-defined or library-defined callback function that a fax service provider (FSP) calls to notify the fax service that an outgoing fax call is in progress.

The **PFAX_SEND_CALLBACK** data type is a pointer to a *FaxSendCallback* function. *FaxSendCallback* is a placeholder for an application-defined or library-defined function name.

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies a fax handle returned by the [FaxDevStartJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevstartjob) function.

### `CallHandle` [in]

Type: **HCALL**

Specifies a call handle returned by the TAPI 2.x [LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate) message.

### `Reserved1` [in]

Type: **DWORD**

This parameter is reserved for future use by Microsoft. It must be set to zero.

### `Reserved2` [in]

Type: **DWORD**

This parameter is reserved for future use by Microsoft. It must be set to zero.

## Return value

Type: **BOOL**

The fax service returns a value of **TRUE** to indicate that the active fax operation should continue.

The fax service returns a value of **FALSE** to indicate that the active fax operation should be terminated. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The *FaxSendCallback* callback function provides the fax service with the *CallHandle* that TAPI assigns. This handle is necessary for TAPI message routing. If the FSP does not call *FaxSendCallback*, it will miss all further call events.

A virtual FSP does not need the *FaxSendCallback* function.

## See also

[Fax Service Provider Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-provider-functions)

[FaxDevSend](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevsend)

[FaxDevStartJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevstartjob)

[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate)

[Using the Fax Service Provider API](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-using-the-fax-service-provider-api)