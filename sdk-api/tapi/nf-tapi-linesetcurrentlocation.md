# lineSetCurrentLocation function

## Description

The
**lineSetCurrentLocation** function sets the location used as the context for address translation.

## Parameters

### `hLineApp`

Application handle returned by
[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa). If an application has not yet called the
**lineInitializeEx** function, it can set the *hLineApp* parameter to zero.

### `dwLocation`

New value for the CurrentLocation entry in the [Locations] section in the registry. It must contain a valid permanent identifier of a Location entry in the [Locations] section, as obtained from
[lineGetTranslateCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegettranslatecaps). If it is valid, the CurrentLocation entry is updated.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INIFILECORRUPT, LINEERR_NOMEM, LINEERR_INVALAPPHANDLE, LINEERR_OPERATIONFAILED, LINEERR_INVALLOCATION, LINEERR_RESOURCEUNAVAIL, LINEERR_NODRIVER, LINEERR_UNINITIALIZED.

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineGetTranslateCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegettranslatecaps)

[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa)