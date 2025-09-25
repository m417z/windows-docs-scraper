# lineGetTranslateCapsW function

## Description

The
**lineGetTranslateCaps** function returns address translation capabilities.

## Parameters

### `hLineApp`

Handle returned by the
[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa) function. If an application has not yet called the
**lineInitializeEx** function, this parameter can be zero.

**Note** TAPI 1.4 applications must set this parameter to a valid hLineApp handle, as returned by the [lineInitialize](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitialize) function.

### `dwAPIVersion`

Highest version of TAPI supported by the application (not necessarily the value negotiated by
[lineNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateapiversion) on some particular line device).

### `lpTranslateCaps`

Pointer to a location to which a
[LINETRANSLATECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslatecaps) structure is loaded. Prior to calling
**lineGetTranslateCaps**, the application must set the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

**Note** If the size parameters in the structure are not correct, there is a possibility that data could get overwritten. For more information on setting structure sizes, see the
[memory allocation](https://learn.microsoft.com/windows/desktop/Tapi/memory-allocation) topic.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INCOMPATIBLEAPIVERSION, LINEERR_NOMEM, LINEERR_INIFILECORRUPT, LINEERR_OPERATIONFAILED, LINEERR_INVALAPPHANDLE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALPOINTER, LINEERR_STRUCTURETOOSMALL, LINEERR_NODRIVER.

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[LINETRANSLATECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslatecaps)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa)

[lineNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateapiversion)

## Remarks

> [!NOTE]
> The tapi.h header defines lineGetTranslateCaps as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).