# lineSetCallParams function

## Description

The
**lineSetCallParams** function allows an application to change bearer mode and/or the rate parameters of an existing call.

## Parameters

### `hCall`

Handle to the call whose parameters are to be changed. The application must be an owner of the call. The call state of *hCall* can be any state except *idle* or *disconnected*.

### `dwBearerMode`

New bearer mode for the call. This parameter uses one and only one of the
[LINEBEARERMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linebearermode--constants).

### `dwMinRate`

Lower bound for the call's new data rate. The application can accept a new rate as low as this one.

### `dwMaxRate`

Upper bound for the call's new data rate. This is the maximum data rate the application can accept. If an exact data rate is required, *dwMinRate* and *dwMaxRate* should be equal.

### `lpDialParams`

Pointer to the new dial parameters for the call, of type
[LINEDIALPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedialparams). This parameter can be left **NULL** if the call's current dialing parameters are to be used.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_BEARERMODEUNAVAIL, LINEERR_NOTOWNER, LINEERR_INVALBEARERMODE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONFAILED, LINEERR_INVALCALLSTATE, LINEERR_RATEUNAVAIL, LINEERR_INVALPOINTER, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALRATE, LINEERR_UNINITIALIZED, LINEERR_NOMEM.

## Remarks

This operation is used to change the parameters of an existing call. Examples of its usage include changing the bearer mode and/or the data rate of an existing call.

## See also

[LINEDIALPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedialparams)

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)