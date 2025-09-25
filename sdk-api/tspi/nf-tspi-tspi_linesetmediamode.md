# TSPI_lineSetMediaMode function

## Description

The
**TSPI_lineSetMediaMode** function changes the call's media as stored in the call's
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) structure.

## Parameters

### `hdCall`

The handle to the call undergoing a change in media type. The call state of *hdCall* can be any state.

### `dwMediaMode`

The new media type(s) for the call. As long as the LINEMEDIAMODE_UNKNOWN media type flag is set, multiple other media type flags can be set as well. This is used to identify a call's media type as not fully determined, but narrowed down to one of just a small set of specified media types. If the LINEMEDIAMODE_UNKNOWN flag is not set, only a single media type can be specified. This parameter uses one (or more) of the
[LINEMEDIAMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linemediamode--constants).

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALMEDIAMODE, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL.

## Remarks

Other than changing the call's media as stored in the call's
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) structure, this procedure is simply advisory in the sense that it indicates an expected media change that is about to occur, rather than forcing a specific change to the call. Typical usage is to set a call's media type to a specific known media type, or to exclude possible media types as long as the call's media type is not fully known (the UNKNOWN media type flag is set).

TAPI makes the following guarantees regarding the passed media type: (1) there is at least one bit set, (2) there are no reserved bits set, and (3) if more than one bit is set, "Unknown" is also set. The service provider must perform any further validity checks on the media types, such as checking whether any media types are indeed supported by the service provider.

## See also

[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo)

[LINEMEDIAMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linemediamode--constants)

[TSPI_lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetcallinfo)