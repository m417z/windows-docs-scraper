# tapiRequestDrop function

## Description

Closes a call request made by a previous call to [tapiRequestMediaCall](https://learn.microsoft.com/windows/desktop/Tapi/tapirequestmediacall).

**Note** The tapiRequestDrop function is nonfunctional and obsolete for all classes of Windows-based applications. It should not be used.

## Parameters

### `hwnd`

Handle to the Windows process that issued this request.

### `wRequestID`

Pointer to a 32-bit integer value that contains the ID of the call request.

## Return value

The function is obsolete and will always return an error code.

## See also

[Assisted Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/assisted-telephony-services-reference)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)