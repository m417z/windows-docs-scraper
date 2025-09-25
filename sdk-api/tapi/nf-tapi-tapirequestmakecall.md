# tapiRequestMakeCall function

## Description

The
**tapiRequestMakeCall** function requests the establishment of a voice call. A call-manager application is responsible for establishing the call on behalf of the requesting application, which is then controlled by the user's call-manager application.

## Parameters

### `lpszDestAddress`

Pointer to a memory location where the **null**-terminated destination address of the call request is located. The address can use the
[canonical address](https://learn.microsoft.com/windows/win32/tapi/address-ovr#canonical-addresses) format. Validity of the specified address is not checked by this operation. The maximum length of the address is TAPIMAXDESTADDRESSSIZE characters, which includes the **NULL** terminator.

### `lpszAppName`

Pointer to a memory location where the **null**-terminated user-friendly application name of the call request is located. This pointer can be left **NULL** if the application does not supply an application name. The maximum length of the address is TAPIMAXAPPNAMESIZE characters, which includes the **NULL** terminator. Longer strings are truncated.

### `lpszCalledParty`

Pointer to a memory location where the **null**-terminated called party name for the called party of the call is located. This pointer can be left **NULL** if the application does not wish to supply this information. The maximum length of the string is TAPIMAXCALLEDPARTYSIZE characters, which includes the **NULL** terminator. Longer strings are truncated.

### `lpszComment`

Pointer to a memory location where the **null**-terminated comment about the call is located. This pointer can be left **NULL** if the application does not supply a comment. The maximum length of the address is TAPIMAXCOMMENTSIZE characters, which includes the **NULL** terminator. Longer strings are truncated.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible error return value are:

TAPIERR_NOREQUESTRECIPIENT, TAPIERR_INVALDESTADDRESS, TAPIERR_REQUESTQUEUEFULL, TAPIERR_INVALPOINTER.

## Remarks

A telephony-enabled application can request that a call be placed on its behalf by invoking
**tapiRequestMakeCall**, providing only the destination address for the call. This request is forwarded to the user's call-control application, which places the call on behalf of the original application. A default call-control application is provided as part of Telephony. Users can replace this with a call-control application of their choice.

Invoking
**tapiRequestMakeCall** when no call control application is running returns the TAPIERR_NOREQUESTRECIPIENT error indication. If the call control application is not running, TAPI attempts to launch the highest-priority call control application (which is listed for **RequestMakeCall** in the registry). Invoking this function when the Assisted TAPI request queue is full returns the TAPIERR_REQUESTQUEUEFULL error.

## See also

[Assisted Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/assisted-telephony-services-reference)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)