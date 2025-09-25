# TSPI_phoneGetDevCaps function

## Description

The
**TSPI_phoneGetDevCaps** function queries a specified phone device to determine its telephony capabilities.

## Parameters

### `dwDeviceID`

The phone device to be queried.

### `dwTSPIVersion`

The negotiated TSPI version number. This value is negotiated for this device through the
[TSPI_phoneNegotiateTSPIVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonenegotiatetspiversion) function.

### `dwExtVersion`

The negotiated extension version number. This value is negotiated for this device through the
[TSPI_phoneNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonenegotiateextversion) function.

### `lpPhoneCaps`

A pointer to memory into which the service provider writes a variably sized structure of type
[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps). Upon successful completion of the request, this structure is filled with phone device capability information. Prior to calling
**TSPI_phoneGetDevCaps**, the application sets the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

PHONEERR_INCOMPATIBLEAPIVERSION, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INCOMPATIBLEEXTVERSION, PHONEERR_OPERATIONFAILED, PHONEERR_NODRIVER, PHONEERR_OPERATIONUNAVAIL, PHONEERR_NOMEM.

## Remarks

The service provider fills in all the members of the
[PHONEBUTTONINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonebuttoninfo) data structure, except for **dwTotalSize**, which is filled in by TAPI. The service provider must not overwrite the **dwTotalSize** member.

If *dwExtVersion* is zero, no extension information is requested. If it is nonzero, it holds a value that has already been negotiated for this device with the
[TSPI_phoneNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonenegotiateextversion) function. The service provider fills in device- and vendor-specific extended information according to the extension version specified.

After the service provider returns from the
**TSPI_phoneGetDevCaps** function, TAPI sets the **dwPhoneStates** member of the
[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps) structure as follows:

``` syntax
PHONECAPS.dwPhoneStates |=
    PHONESTATE_OWNER |
    PHONESTATE_MONITORS |
    PHONESTATE_REINIT;
```

## See also

[PHONEBUTTONINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonebuttoninfo)

[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)

[TSPI_phoneNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonenegotiateextversion)