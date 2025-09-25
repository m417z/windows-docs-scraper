# lineAddProviderW function

## Description

The
**lineAddProvider** function installs a new telephony service provider into the telephony system.

## Parameters

### `lpszProviderFilename`

Pointer to a

**null**-terminated string containing the path of the service provider to be added.

### `hwndOwner`

Handle to a window in which any dialog boxes that need to be displayed as part of the installation process (for example, by the service provider's
[TSPI_providerInstall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerinstall) function) would be attached. Can be **NULL** to indicate that any window created during the function should have no owner window.

### `lpdwPermanentProviderID`

Pointer to a variable that receives the permanent provider identifier of the newly installed service provider.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INIFILECORRUPT, LINEERR_INVALPARAM, LINEERR_INVALPOINTER, LINEERR_NOMEM, LINEERR_NOMULTIPLEINSTANCE, LINEERR_OPERATIONFAILED.

## Remarks

During this function call, TAPI checks to ensure that it can access the service provider by calling its
[TSPI_providerInstall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerinstall) function; if this is unsuccessful (if the DLL or function cannot be found, or if
**TSPI_providerInstall** returns an error), the function fails and the provider is not added to the telephony system. If this succeeds, and the Telephony system is active (one or more applications have called
[lineInitialize](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitialize) or
[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa)), TAPI does not attempt to launch the newly-added service provider. Instead, in order to activate the new service provider, TAPI issues a message to restart Windows. When the activation succeeds, applications are informed of any new devices created by way of
[LINE_CREATE](https://learn.microsoft.com/windows/desktop/Tapi/line-create) or
[PHONE_CREATE](https://learn.microsoft.com/windows/desktop/Tapi/phone-create) messages, or by a
[LINE_LINEDEVSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-linedevstate) message requesting reinitialization (if the application does not support the CREATE messages).

This function copies no files—not the service provider DLL itself nor any supporting files; the application managing the addition of the provider must ensure that the provider is installed in a directory where it can be found by TAPI (for example, \WINDOWS, \WINDOWS\SYSTEM, or elsewhere on the path).

> [!NOTE]
> The tapi.h header defines lineAddProvider as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[LINE_CREATE](https://learn.microsoft.com/windows/desktop/Tapi/line-create)

[LINE_LINEDEVSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-linedevstate)

[PHONE_CREATE](https://learn.microsoft.com/windows/desktop/Tapi/phone-create)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineInitialize](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitialize)

[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa)