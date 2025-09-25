# lineSetCallData function

## Description

The
**lineSetCallData** function sets the **CallData** member in
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo). Depending on the service provider implementation, the **CallData** member can be propagated to all applications having handles to the call, including those on other machines (through the server), and can travel with the call when it is transferred.

## Parameters

### `hCall`

Handle to the call. The application must have OWNER privilege.

### `lpCallData`

Address of the data to be copied to the **CallData** member in
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo), replacing any existing data. For more information, see the
[call data](https://learn.microsoft.com/windows/desktop/Tapi/call-data-ovr) topic.

### `dwSize`

Number of bytes of data to be copied. A value of 0 causes any existing data to be removed.

**Note** If *lpCallData* is a pointer to a string, the size must include the null terminator.

## Return value

Returns a positive request identifier if the asynchronous operation starts; otherwise, the function returns one of these negative error values:

LINEERR_INVALCALLHANDLE, LINEERR_INVALCALLSTATE, LINEERR_INVALPARAM, LINEERR_INVALPOINTER, LINEERR_NOMEM, LINEERR_NOTOWNER, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL, LINEERR_RESOURCEUNAVAIL, LINEERR_UNINITIALIZED.

## See also

[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)