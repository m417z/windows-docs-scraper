# TSPI_providerEnumDevices function

## Description

TAPI calls the
**TSPI_providerEnumDevices** function before
[TSPI_providerInit](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerinit) to determine the number of line and phone devices supported by the service provider.

## Parameters

### `dwPermanentProviderID`

The permanent identifier, unique within the service providers on this system, of the service provider being initialized.

### `lpdwNumLines`

A pointer to a **DWORD**-sized memory location into which the service provider must write the number of line devices it is configured to support. TAPI initializes the value to 0, so if the service provider fails to write a different value, the value 0 is assumed.

### `lpdwNumPhones`

A pointer to a **DWORD**-sized memory location into which the service provider must write the number of phone devices it is configured to support. TAPI initializes the value to 0, so if the service provider fails to write a different value, the value 0 is assumed.

### `hProvider`

An opaque **DWORD**-sized value that uniquely identifies this instance of this service provider during this execution of the Telephony environment.

### `lpfnLineCreateProc`

A pointer to the
[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent) callback procedure supplied by TAPI. The service provider uses this function to send
[LINE_CREATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725223(v=vs.85)) messages when a new line device needs to be created.

### `lpfnPhoneCreateProc`

A pointer to the
[PHONEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-phoneevent) callback procedure supplied by TAPI. The service provider uses this function to send
[PHONE_CREATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725256(v=vs.85)) messages when a new phone device needs to be created.

## Return value

Returns zero if the request succeeds or an error number if an error occurs. Possible return values are:

LINEERR_NOMEM, LINEERR_OPERATIONFAILED.

## Remarks

In previous versions of TAPI, implementation of this function was optional. Beginning with TAPI 2.0, implementation of this function is mandatory in all service providers. TAPI no longer checks Telephon.ini or the Registry at TAPI startup to determine the initial number of lines and phones supported by a service provider.

A new device can appear prior to the completion of the
[TSPI_providerInit](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerinit) procedure. TAPI handles properly any _CREATE messages during the provider initialization.

## See also

[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent)

[LINE_CREATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725223(v=vs.85))

[PHONEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-phoneevent)

[PHONE_CREATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725256(v=vs.85))

[TSPI_providerInit](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerinit)