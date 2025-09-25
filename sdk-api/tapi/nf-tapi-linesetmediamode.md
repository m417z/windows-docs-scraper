# lineSetMediaMode function

## Description

The
**lineSetMediaMode** function sets the media type(s) of the specified call in its
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) structure. For more information, see
[ITLegacyCallMediaControl::SetMediaType](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacycallmediacontrol-setmediatype).

## Parameters

### `hCall`

Handle to the call whose media type is to be changed. The application must be an owner of the call. The call state of *hCall* can be any state.

### `dwMediaModes`

New media type(s) for the call. This parameter uses the
[LINEMEDIAMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linemediamode--constants). As long as the UNKNOWN media type flag is set, other media type flags may be set as well. This is used to identify a call's media type as not fully determined, but narrowed down to one of a small set of specified media types. If the UNKNOWN flag is not set, only a single media type can be specified.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONFAILED, LINEERR_INVALMEDIAMODE, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM, LINEERR_UNINITIALIZED, LINEERR_OPERATIONUNAVAIL.

## Remarks

The
**lineSetMediaMode** function changes the call's media type in its
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) structure. Typical usage of this operation is either to set a call's media type to a specific known media type or to exclude possible media types as long as the call's media type is officially unknown (the UNKNOWN media type flag is set).

## See also

[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)