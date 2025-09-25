# lineGetAddressCapsA function

## Description

The
**lineGetAddressCaps** function queries the specified address on the specified line device to determine its telephony capabilities.

## Parameters

### `hLineApp`

Handle to the application's registration with TAPI.

### `dwDeviceID`

Line device containing the address to be queried.

### `dwAddressID`

Address on the given line device whose capabilities are to be queried. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `dwAPIVersion`

Version number of the Telephony API to be used. The high-order word contains the major version number; the low-order word contains the minor version number. This number is obtained by
[lineNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateapiversion).

### `dwExtVersion`

Version number of the service provider-specific extensions to be used. This number can be set to zero if no device-specific extensions are to be used. Otherwise, the high-order word contains the major version number; and the low-order word contains the minor version number.

### `lpAddressCaps`

Pointer to a variably sized structure of type
[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps). Upon successful completion of the request, this structure is filled with address capabilities information. Prior to calling
**lineGetAddressCaps**, the application should set the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

**Note** If the size parameters in the structure are not correct, there is a possibility that data could get overwritten. For more information on setting structure sizes, see the
[memory allocation](https://learn.microsoft.com/windows/desktop/Tapi/memory-allocation) topic.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_BADDEVICEID, LINEERR_NOMEM, LINEERR_INCOMPATIBLEAPIVERSION, LINEERR_OPERATIONFAILED, LINEERR_INCOMPATIBLEEXTVERSION, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALADDRESSID, LINEERR_STRUCTURETOOSMALL, LINEERR_INVALAPPHANDLE, LINEERR_UNINITIALIZED, LINEERR_INVALPOINTER, LINEERR_OPERATIONUNAVAIL, LINEERR_NODRIVER, LINEERR_NODEVICE.

## Remarks

Valid address identifiers range from zero to one less than the number of addresses returned by
[lineGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevcaps). The version number to be supplied is the version number that was returned as part of the line's device capabilities by
**lineGetDevCaps**.

> [!NOTE]
> The tapi.h header defines lineGetAddressCaps as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevcaps)

[lineNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateapiversion)