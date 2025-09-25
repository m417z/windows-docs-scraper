# lineGetProviderList function

## Description

The
**lineGetProviderList** function returns a list of service providers currently installed in the telephony system.

## Parameters

### `dwAPIVersion`

Highest version of TAPI supported by the application (not necessarily the value negotiated by
[lineNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateapiversion) on some particular line device).

### `lpProviderList`

Pointer to a memory location where TAPI can return a
[LINEPROVIDERLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproviderlist) structure. Prior to calling
**lineGetProviderList**, the application must set the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

**Note** If the size parameters in the structure are not correct, there is a possibility that data could get overwritten. For more information on setting structure sizes, see the
[memory allocation](https://learn.microsoft.com/windows/desktop/Tapi/memory-allocation) topic.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INCOMPATIBLEAPIVERSION, LINEERR_NOMEM, LINEERR_INIFILECORRUPT, LINEERR_OPERATIONFAILED, LINEERR_INVALPOINTER, LINEERR_STRUCTURETOOSMALL.

## See also

[LINEPROVIDERLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproviderlist)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateapiversion)