# phoneShutdown function

## Description

The
**phoneShutdown** function shuts down the application's usage of TAPI's phone abstraction.

## Parameters

### `hPhoneApp`

Application's usage handle for TAPI.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALAPPHANDLE, PHONEERR_NOMEM, PHONEERR_UNINITIALIZED, PHONEERR_RESOURCEUNAVAIL.

## Remarks

If this function is called when the application has open phone devices, these devices are closed.