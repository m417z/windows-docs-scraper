# TSPI_phoneClose function

## Description

The
**TSPI_phoneClose** function closes the specified open phone device after completing or aborting all outstanding asynchronous operations on the device.

## Parameters

### `hdPhone`

The service provider's opaque handle to the phone to be closed. After the phone is successfully closed, this handle is no longer valid.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

PHONEERR_INVALPHONEHANDLE, PHONEERR_OPERATIONFAILED, PHONEERR_NOMEM, PHONEERR_OPERATIONUNAVAIL, PHONEERR_RESOURCEUNAVAIL.

## Remarks

The service provider must report completion for every asynchronous operation. If this procedure is called for a phone on which there are outstanding asynchronous operations, the operations should be reported complete with an appropriate result or error code before this procedure returns. Generally, TAPI waits for these to complete in an orderly fashion. However, the service provider should be prepared to handle an early call to
**TSPI_phoneClose** in "abort" or "emergency shutdown" situations.

After this procedure returns the service provider must report no further events on the phone. The service provider's opaque handle for the phone becomes invalid.

The service provider must relinquish nonsharable resources it reserves while the phone is open. For example, closing a phone accessed through a comm port and modem should result in closing the comm port, making it available for use by other applications.

This function should always succeed except in extraordinary circumstances. Most callers will probably ignore the return code because they will be unable to compensate for any error that occurs. The specified return values are more advisory for development diagnostic purposes than anything else.

## See also

[PHONE_CLOSE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725255(v=vs.85))