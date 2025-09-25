# TSPI_lineSetDefaultMediaDetection function

## Description

The
**TSPI_lineSetDefaultMediaDetection** procedure tells the service provider the new set of media types to detect for the indicated line (replacing any previous set). It also sets the initial set of media types that should be monitored for on subsequent calls (inbound or outbound) on this line.

## Parameters

### `hdLine`

The handle to the line to have media monitoring set.

### `dwMediaModes`

The media type(s) of interest to TAPI. This parameter uses one of the
[LINEMEDIAMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linemediamode--constants):

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALLINEHANDLE, LINEERR_OPERATIONFAILED, LINEERR_INVALMEDIAMODE, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM, LINEERR_NODRIVER, LINEERR_OPERATIONUNAVAIL.

## Remarks

TAPI typically calls this function to update the set of detected media types for the line to the union of all modes selected by all outstanding lineOpens whenever a line is Opened or Closed at the TAPI level. A
[lineOpen](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineopen) call attempt is rejected if media detection is rejected. A single call to this procedure is typically the result of a
**lineOpen** call that does not specify the device identifier LINEMAPPER. The device identifier LINEMAPPER is never used at the TSPI level.

TAPI must compute the union of media types desired by all clients and pass the result to this function. The service provider uses the set passed to this function by TAPI. TAPI ensures that the *dwMediaModes* parameter has at least one bit set and that no reserved bits are set. The service provider must perform any further validity checks on the media types, such as checking whether any media types are indeed supported by the service provider. The union of all media types can be the value 0 if the applications that have the line open are all either monitors or not interested in handling incoming calls.

There is no directly corresponding function at the TAPI level. This procedure corresponds to the "request media types" implied for the specific line by the
[lineOpen](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineopen) procedure when it is called with the specific device identifier (other than LINEMAPPER).

## See also

[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams)

[LINEMEDIAMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linemediamode--constants)

[TSPI_lineClose](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineclose)