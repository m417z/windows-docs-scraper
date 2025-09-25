# lineGetDevCapsA function

## Description

The
**lineGetDevCaps** function queries a specified line device to determine its telephony capabilities. The returned information is valid for all addresses on the line device.

## Parameters

### `hLineApp`

Handle to the application's registration with TAPI.

### `dwDeviceID`

Identifier of the line device to be queried.

### `dwAPIVersion`

Version number of the Telephony API to be used. The high-order word contains the major version number; the low-order word contains the minor version number. This number is obtained by
[lineNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateapiversion).

### `dwExtVersion`

Version number of the service provider-specific extensions to be used. This number is obtained by
[lineNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateextversion). It can be left zero if no device-specific extensions are to be used. Otherwise, the high-order word contains the major version number; the low-order word contains the minor version number.

### `lpLineDevCaps`

Pointer to a variably sized structure of type
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps). Upon successful completion of the request, this structure is filled with line device capabilities information. Prior to calling
**lineGetDevCaps**, the application must set the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

**Note** If the size parameters in the structure are not correct, there is a possibility that data could get overwritten. For more information on setting structure sizes, see the
[memory allocation](https://learn.microsoft.com/windows/desktop/Tapi/memory-allocation) topic.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_BADDEVICEID, LINEERR_NOMEM, LINEERR_INCOMPATIBLEAPIVERSION, LINEERR_OPERATIONFAILED, LINEERR_INCOMPATIBLEEXTVERSION, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALAPPHANDLE, LINEERR_STRUCTURETOOSMALL, LINEERR_INVALPOINTER, LINEERR_UNINITIALIZED, LINEERR_NODRIVER, LINEERR_OPERATIONUNAVAIL, LINEERR_NODEVICE.

## Remarks

Before using
**lineGetDevCaps**, the application must negotiate the API version number to use, and, if desired, the extension version to use.

The API and extension version numbers are those under which TAPI and the service provider must operate. If version ranges do not overlap, the application, API, or service-provider versions are incompatible and an error is returned.

One of the members in the
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) structure returned by this function contains the number of addresses assigned to the specified line device. The actual address identifiers used to reference individual addresses vary from zero to one less than the returned number. The capabilities of each address can be different. Use
[lineGetAddressCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetaddresscaps) for each available <*dwDeviceID*, *dwAddressID*> combination to determine the exact capabilities of each address. Note that an address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

> [!NOTE]
> The tapi.h header defines lineGetDevCaps as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineGetAddressCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetaddresscaps)

[lineNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateapiversion)

[lineNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateextversion)