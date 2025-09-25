# lineTranslateAddress function

## Description

The
**lineTranslateAddress** function translates the specified address into another format.

## Parameters

### `hLineApp`

Handle returned by
[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa). If a TAPI 2.x application has not yet called the
**lineInitializeEx** function, it can set this parameter to **NULL**. TAPI 1.4 applications must still call
[lineInitialize](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitialize) first.

### `dwDeviceID`

Device identifier of the line device upon which the call is to be dialed, so that variations in dialing procedures on different lines can be applied to the translation process.

### `dwAPIVersion`

Highest version of TAPI supported by the application (not necessarily the value negotiated by
[lineNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateapiversion) on some particular line device).

### `lpszAddressIn`

Pointer to a **null**-terminated string that contains the address of the information that is to be extracted for translation. Must be in either the canonical address format, or an arbitrary string of dialable digits (non-canonical). This parameter must not be **NULL**. If the *AddressIn* contains a subaddress or name field, or additional addresses separated from the first address by CR and LF characters, only the first address is translated.

### `dwCard`

Credit card to be used for dialing. This parameter is only valid if the CARDOVERRIDE bit is set in *dwTranslateOptions*. This parameter specifies the permanent identifier of a Card entry in the [Cards] section in the registry (as obtained from
[lineTranslateCaps](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslatecaps)) that should be used instead of the **PreferredCardID** specified in the definition of the **CurrentLocation**. It does not cause the *PreferredCardID* parameter of the current Location entry in the registry to be modified; the override applies only to the current translation operation. This parameter is ignored if the CARDOVERRIDE bit is not set in *dwTranslateOptions*.

### `dwTranslateOptions`

Associated operations to be performed prior to the translation of the address into a dialable string. This parameter uses one of the
[LINETRANSLATEOPTION_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linetranslateoption--constants).

If you have set the LINETRANSLATEOPTION_CANCELCALLWAITING bit, it is also advisable to set the LINECALLPARAMFLAGS_SECURE bit in the **dwCallParamFlags** member of the
[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams) structure (passed in to
[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall) through the *lpCallParams* parameter). This prevents the line device from using dialable digits to suppress call interrupts.

### `lpTranslateOutput`

Pointer to an application-allocated memory area to contain the output of the translation operation, of type
[LINETRANSLATEOUTPUT](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslateoutput). Prior to calling
**lineTranslateAddress**, the application must set the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_BADDEVICEID, LINEERR_INVALPOINTER, LINEERR_INCOMPATIBLEAPIVERSION, LINEERR_NODRIVER, LINEERR_INIFILECORRUPT, LINEERR_NOMEM, LINEERR_INVALADDRESS, LINEERR_OPERATIONFAILED, LINEERR_INVALAPPHANDLE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALCARD, LINEERR_STRUCTURETOOSMALL, LINEERR_INVALPARAM.

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[Canonical addresses](https://learn.microsoft.com/windows/win32/tapi/address-ovr#canonical-addresses)

[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams)

[LINETRANSLATEOUTPUT](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslateoutput)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[TAPI Version Negotiation](https://learn.microsoft.com/windows/desktop/Tapi/tapi-version-negotiation)

[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa)

[lineNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateapiversion)