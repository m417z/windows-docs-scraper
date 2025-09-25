# lineGetCountryA function

## Description

The
**lineGetCountry** function fetches the stored dialing rules and other information related to a specified country/region, the first country/region in the country/region list, or all countries/regions.

## Parameters

### `dwCountryID`

Country/region identifier (not the country code) of the country/region for which information is to be obtained. If the value 1 is specified, information on the first country/region in the country/region list is obtained. If the value 0 is specified, information on all countries/regions is obtained (which can require a great deal of memory — 20 KB or more).

### `dwAPIVersion`

Highest version of TAPI supported by the application (not necessarily the value negotiated by
[lineNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateapiversion) on some particular line device).

### `lpLineCountryList`

Pointer to a location to which a [LINECOUNTRYLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecountrylist) structure is loaded. Prior to calling
**lineGetCountry**, the application must set the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

**Note** If the size parameters in the structure are not correct, there is a possibility that data could get overwritten. For more information on setting structure sizes, see the
[memory allocation](https://learn.microsoft.com/windows/desktop/Tapi/memory-allocation) topic.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INCOMPATIBLEAPIVERSION, LINEERR_NOMEM, LINEERR_INIFILECORRUPT, LINEERR_OPERATIONFAILED, LINEERR_INVALCOUNTRYCODE, LINEERR_STRUCTURETOOSMALL, LINEERR_INVALPOINTER.

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[LINECOUNTRYLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecountrylist)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateapiversion)

## Remarks

> [!NOTE]
> The tapi.h header defines lineGetCountry as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).