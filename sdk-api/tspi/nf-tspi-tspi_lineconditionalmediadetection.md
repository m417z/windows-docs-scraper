# TSPI_lineConditionalMediaDetection function

## Description

The
**TSPI_lineConditionalMediaDetection** function is invoked by TAPI whenever a client application uses LINEMAPPER as the *dwDeviceID* in a
[lineOpen](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineopen) function call to request that lines be scanned to find one that supports the desired media types and call parameters. TAPI scans based on the union of the desired media type and the other media types currently being monitored on the line, to give the service provider the opportunity to indicate if it cannot simultaneously monitor for all of the requested media types. If the service provider can monitor for the indicated set of media types and support the capabilities indicated in *lpCallParams*, it replies with a success indication. It leaves the active media monitoring modes for the line unchanged.

## Parameters

### `hdLine`

The service provider's handle to the line on which media monitoring and parameter capabilities are to be set.

### `dwMediaModes`

The media type(s) currently of interest to the calling application. This parameter uses one of the
[LINEMEDIAMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linemediamode--constants).

### `lpCallParams`

A pointer to a structure of type
[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams). It describes the call parameters that the line device should be able to provide. The only relevant fields of *lpCallParams* for the purposes of this test are the following:

**dwBearerMode**

**dwMinRate**

**dwMaxRate**

**dwMediaMode**

**dwCallParamFlags**

**dwAddressMode**

If **dwAddressMode** is LINEADDRESSMODE_ADDRESSID, any address on the line is acceptable. If **dwAddressMode** is LINEADDRESSMODE_DIALABLEADDR, indicating that a specific originating address (phone number) is searched for, or if it is a provider-specific extension, then **dwOrigAddressSize/Offset** and the portion of the variable part they refer to are also relevant. If **dwAddressMode** is a provider-specific extension, additional information can be contained in the **dwDeviceSpecific** variably sized field. All other fields are irrelevant to the function.

## Return value

Returns zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALLINEHANDLE, LINEERR_OPERATIONFAILED, LINEERR_NODRIVER, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM, LINEERR_INVALMEDIAMODE, LINEERR_OPERATIONUNAVAIL.

## Remarks

A TAPI
[lineOpen](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineopen) function that specifies a device identifier of LINEMAPPER typically results in calling this procedure for multiple line devices to hunt for a suitable line, possibly also opening as-yet unopened lines. A success result indicates that the line is suitable for the calling application's requirements.

**Note** The media monitoring modes demanded at the TSPI level are the union of monitoring modes demanded by multiple applications at the TAPI level. As a consequence, it is most common for multiple media type flags to be set simultaneously at this level. The service provider must test to determine if it can support at least the specified set, regardless of what modes are currently in effect. TAPI ensures that the *dwMediaModes* parameter has at least one bit set and that no reserved bits are set. It is the service provider's responsibility to do any further validity checks on the media types, such as checking whether any media types are supported by the service provider.

The
**TSPI_lineConditionalMediaDetection** function checks the bits set in the **dwCallParamFlags** member of the
[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams) structure and handles the following cases:

The
**TSPI_lineConditionalMediaDetection** function returns success if passing the same bit values to the
[TSPI_lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linemakecall) function would also return success.

If the SECURE, ORIGOFFHOOK, and DESTOFFHOOK bits are set and the *dwAddressMode* parameter is LINEADDRESSMODE_ADDRESSID, the function returns success if it can succeed on one or more addresses on the line.

If the SECURE, ORIGOFFHOOK, and DESTOFFHOOK bits are set and the *dwAddressMode* parameter is LINEADDRESSMODE_DIALABLEADDR, the function returns success if it can succeed on the address identified by the *dwOrigAddress* parameter.

The service provider returns an error (for example, LINEERR_RESOURCEUNAVAIL) if, at the time this function is called, it is impossible to place a new call on the specified line device (if it would return LINEERR_CALLUNAVAIL or LINEERR_RESOURCEUNAVAIL should
[TSPI_lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linemakecall) be invoked immediately after opening the line).

There is no directly corresponding function at the TAPI level. This procedure corresponds to the test implied for each individual line by the
[lineOpen](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineopen) procedure when it is called with the device identifier LINEMAPPER.

## See also

[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams)

[LINEMEDIAMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linemediamode--constants)

[TSPI_lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linemakecall)