# TSPI_lineDevSpecificFeature function

## Description

The
**TSPI_lineDevSpecificFeature** function is used as an extension mechanism to enable service providers to provide access to features not described in other operations. The meanings of these extensions are device specific, and taking advantage of these extensions requires TAPI or its client application to be fully aware of them.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdLine`

The service provider's handle to the line device.

### `dwFeature`

The feature to invoke on the line device. This parameter uses
[PHONEBUTTONFUNCTION_ constants](https://learn.microsoft.com/windows/desktop/Tapi/phonebuttonfunction--constants).

### `lpParams`

A pointer to a memory area used to hold a feature-dependent parameter block. The format of this parameter block is device specific.

### `dwSize`

The size of the buffer in bytes. If the *lpParams* parameter is a pointer to a string, the size must include the null terminator.

## Return value

Returns *dwRequestID* or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALFEATURE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALLINEHANDLE, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL.

## Remarks

Additional return values are device specific. The call state of *hdCall* is device-specific.

This function provides TAPI applications with phone feature button emulation capabilities. When TAPI invokes this operation on behalf of a client application, it specifies the equivalent of a "button press" event. This method of invoking features is highly device dependent, as the API does not define their meaning. When an application relies on device-specific extensions, the application does not port well to other service provider environments.

This function is called in direct response to an application calling the TAPI
[lineDevSpecificFeature](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedevspecificfeature) function. TAPI translates the *hLine* parameter used at the TAPI level to the corresponding *hdLine* parameter used at the TSPI level. The *lpParams* buffer is passed through unmodified.

**Note** The *lpParams* data structure should not contain any pointers because they are not properly translated (thunked) when running a 16-bit application in a 32-bit version of TAPI and vice versa.

This operation is part of the Extended Telephony services. It only provides access to a device-specific feature without defining its meaning. This operation is only available if TAPI has successfully negotiated and selected a device-specific extension version.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[LINE_DEVSPECIFICFEATURE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725227(v=vs.85))

[PHONEBUTTONFUNCTION_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonebuttonfunction--constants)