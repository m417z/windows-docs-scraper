# TSPI_phoneDevSpecific function

## Description

The
**TSPI_phoneDevSpecific** function is used as a general extension mechanism to enable a Telephony API implementation to provide features not described in the other operations. The meanings of these extensions are device specific.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdPhone`

The handle to the phone on which a device-specific operation is to be performed.

### `lpParams`

A pointer to a memory area used to hold a parameter block. Its interpretation is device specific. The *lpParams* parameter should not contain pointers. To get information back to the application from
**TSPI_phoneDevSpecific**, the service provider sends a
[PHONE_DEVSPECIFIC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725258(v=vs.85)) message with the information.

### `dwSize`

The size in bytes of the parameter block area.

## Return value

Returns *dwRequestID* or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds or it is an error number if an error occurs. Possible return values are as follows:

PHONEERR_INVALPHONEHANDLE, PHONEERR_OPERATIONUNAVAIL, PHONEERR_INVALPOINTER, PHONEERR_NOMEM, PHONEERR_OPERATIONFAILED, PHONEERR_RESOURCEUNAVAIL.

## Remarks

Additional return values are device specific.

This operation provides a generic parameter profile. The interpretation of the parameter block is device specific. Indications and replies that are device specific should use the
[PHONE_DEVSPECIFIC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725258(v=vs.85)) message.

This function is called in direct response to an application that has called the TAPI
[phoneDevSpecific](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonedevspecific) function. TAPI translates the *hPhone* parameter used at the TAPI level to the corresponding *hdPhone* parameter used at the TSPI level. The *lpParams* buffer is passed through unmodified.

A service provider can provide access to device-specific functions by defining parameters for use with this operation. Applications that want to make use of these device-specific extensions should consult the device-specific (vendor-specific) documentation that describes what extensions are defined.

**Note** An application that relies on these device-specific extensions is typically not portable in working with other service provider environments.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[PHONE_DEVSPECIFIC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725258(v=vs.85))