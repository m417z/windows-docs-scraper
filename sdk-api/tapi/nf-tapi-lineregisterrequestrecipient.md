# lineRegisterRequestRecipient function

## Description

The
**lineRegisterRequestRecipient** function registers the invoking application as a recipient of requests for the specified request mode.

## Parameters

### `hLineApp`

Application's usage handle for the line portion of TAPI.

### `dwRegistrationInstance`

Application-specific **DWORD** that is passed back as a parameter of the
[LINE_REQUEST](https://learn.microsoft.com/windows/desktop/Tapi/line-request) message. This message notifies the application that a request is pending. This parameter is ignored if *bEnable* is set to zero. This parameter is examined by TAPI only for registration, not for deregistration. The *dwRegistrationInstance* value used while deregistering need not match the *dwRegistrationInstance* used while registering for a request mode.

### `dwRequestMode`

Type of request for which the application registers. This parameter uses one or more of the
[LINEREQUESTMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linerequestmode--constants).

### `bEnable`

If **TRUE**, the application registers the specified request modes; if **FALSE**, the application deregisters for the specified request modes.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALAPPHANDLE, LINEERR_OPERATIONFAILED, LINEERR_INVALREQUESTMODE, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM, LINEERR_UNINITIALIZED.

## Remarks

A telephony-enabled application can request that a call be placed on its behalf by invoking
[tapiRequestMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-tapirequestmakecall). Additionally, other applications can request that information be logged with a given call. The
**tapiRequestMakeCall** requests are queued by TAPI, and the highest priority application that has registered to handle the request is sent a
[LINE_REQUEST](https://learn.microsoft.com/windows/desktop/Tapi/line-request) message with an indication of the mode of the request that is pending. This application is typically the user's call-control application.

Next, the call-control application that receives this message invokes
[lineGetRequest](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetrequest), specifying the request mode and a buffer that is large enough to hold the request. The call-control application then interprets and executes the request.

The recipient application is also automatically deregistered for all requests when it does a
[lineShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineshutdown).

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[LINE_REQUEST](https://learn.microsoft.com/windows/desktop/Tapi/line-request)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineGetRequest](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetrequest)

[lineShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineshutdown)

[tapiRequestMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-tapirequestmakecall)