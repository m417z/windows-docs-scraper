# lineGetRequest function

## Description

The
**lineGetRequest** function retrieves the next by-proxy request for the specified request mode.

## Parameters

### `hLineApp`

The application usage handle for the line portion of TAPI.

### `dwRequestMode`

A type of request to be obtained. Be aware that *dwRequestMode* can only have one bit set. This parameter uses one and only one of the
[LINEREQUESTMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linerequestmode--constants).

### `lpRequestBuffer`

A pointer to a memory buffer where the parameters of the request are to be placed. The size of the buffer and the interpretation of the data placed in the buffer depends on the request mode. The application-allocated buffer is assumed to be of sufficient size to hold the request.

If *dwRequestMode* is LINEREQUESTMODE_MAKECALL, interpret the content of the request buffer using the
[LINEREQMAKECALL](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linereqmakecall) structure.

LINEREQUESTMODE_MEDIACALL is obsolete. For more information, see tapiRequestMediaCall.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

**LINEERR_INVALAPPHANDLE**, **LINEERR_NOTREGISTERED**, **LINEERR_INVALPOINTER**, **LINEERR_OPERATIONFAILED**, **LINEERR_INVALREQUESTMODE**, **LINEERR_RESOURCEUNAVAIL**, **LINEERR_NOMEM**, **LINEERR_UNINITIALIZED**, **LINEERR_NOREQUEST**.

## Remarks

A telephony-enabled application can request that a call be placed on its behalf by invoking
[tapiRequestMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-tapirequestmakecall). These requests are queued by TAPI and the highest priority application that has registered to handle the request is sent a
[LINE_REQUEST](https://learn.microsoft.com/windows/desktop/Tapi/line-request) message with indication of the mode of the request that is pending. Typically, this application is the user's call-control application. The LINE_REQUEST message indicates that zero or more requests may be pending for the registered application to process; after receiving LINE_REQUEST, it is the responsibility of the recipient application to call
**lineGetRequest** until LINEERR_NOREQUEST is returned, indicating that no more requests are pending.

Next, the call-control application that receives this message invokes
**lineGetRequest**, specifying the request mode and a buffer that is large enough to hold the request. The call-control application then interprets and executes the request.

After execution of
**lineGetRequest**, TAPI purges the request from its internal queue, making room available for a subsequent request. It is therefore possible for a new
[LINE_REQUEST](https://learn.microsoft.com/windows/desktop/Tapi/line-request) message to be received immediately upon execution of
**lineGetRequest**, should the same or another application issue another request. It is the responsibility of the request recipient application to handle this scenario by some mechanism; for example, by noting the additional LINE_REQUEST and deferring a subsequent
**lineGetRequest** until processing of the preceding request completes, by getting the subsequent request and buffer as necessary, or by another appropriate means.

The subsequent LINE_REQUEST should not be ignored because it is not repeated by TAPI.

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[LINEREQMAKECALL](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linereqmakecall)

[LINE_REQUEST](https://learn.microsoft.com/windows/desktop/Tapi/line-request)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[tapiRequestMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-tapirequestmakecall)