# TSPI_lineDevSpecific function

## Description

The
**TSPI_lineDevSpecific** function is used as a general extension mechanism to enable service providers to provide access to features not described in other operations. The meanings of the extensions are device-specific, and to take advantage of these extensions the application must be fully aware of them.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdLine`

The service provider's handle to the line to be operated on.

### `dwAddressID`

The address on the specified line to be operated on. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `hdCall`

The service provider's handle to the call to be operated on. This field may have the value **NULL**. The call state of *hdCall* is device specific.

### `lpParams`

A pointer to a memory area used to hold a parameter block. The format of this parameter block is device specific.

### `dwSize`

The size in bytes of the parameter block area. If the *lpParams* parameter is a pointer to a string, the size must include the **null** terminator.

## Return value

Returns *dwRequestID* or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALLINEHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALADDRESSID, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL.

## Remarks

Additional return values are device specific.

This operation provides a generic parameter profile. The interpretation of the parameter structure is device specific. TAPI always specifies the *hdLine* parameter. Whether *dwAddressID* and/or *hdCall* are expected to be valid is device specific. If specified, they must belong to *hdLine*. Indications and replies sent back to the application that are device specific use the
[LINE_DEVSPECIFIC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725225(v=vs.85)) message.

This function is called in direct response to an application calling the TAPI function
[lineDevSpecific](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedevspecific). TAPI translates the *hLine* and *hdCall* parameters used at the TAPI level to the corresponding *hdLine* and *hdCall* parameters used at the TSPI level. The *lpParams* buffer is passed unmodified.

**Note** The *lpParams* data structure should not contain any pointers because they would not be properly translated (thunked) when running a 16-bit application in a 32-bit version of TAPI and vice versa.

A service provider can provide access to device-specific functions by defining parameters for use with this operation. Applications that want to make use of these device-specific extensions should consult the device-specific documentation (in this case meaning vendor-specific) that describes which extensions are defined.

**Note** An application that relies on device-specific extensions is not portable in working with other service provider environments. Use vendor-specific extensions.

This operation is part of the Extended Telephony services. It only provides access to a device-specific feature without defining its meaning. This operation is only available if the application has successfully negotiated and selected a device-specific extension version.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[LINE_DEVSPECIFIC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725225(v=vs.85))

[TSPI_lineNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linenegotiateextversion)