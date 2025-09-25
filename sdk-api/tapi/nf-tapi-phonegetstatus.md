# phoneGetStatus function

## Description

The
**phoneGetStatus** function enables an application to query the specified open phone device for its overall status.

## Parameters

### `hPhone`

Handle to the open phone device to be queried.

### `lpPhoneStatus`

Pointer to a variably sized data structure of type
[PHONESTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonestatus), which is loaded with the returned information about the phone's status.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALPHONEHANDLE, PHONEERR_NOMEM, PHONEERR_INVALPOINTER, PHONEERR_RESOURCEUNAVAIL, PHONEERR_OPERATIONFAILED, PHONEERR_STRUCTURETOOSMALL, PHONEERR_OPERATIONUNAVAIL, PHONEERR_UNINITIALIZED.

## Remarks

An application can use this function to determine the current state of an open phone device. The status information describes information about the phone device's hookswitch devices, ringer, volume, display, and lamps.

## See also

[PHONESTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonestatus)

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)