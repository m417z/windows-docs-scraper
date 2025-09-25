# TUISPI_providerInstall function

## Description

Implementation of the
**TUISPI_providerInstall** function is the service provider's opportunity to install any additional "pieces" of the provider into the right directories (or at least verifying that they're there) and set up registry entries the provider needs. This function makes the
[TSPI_providerInstall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerinstall) function obsolete in version 2.0 and later (supported in version 1.4 and earlier).

If the service provider requires any privately-defined entries in the registry for proper operation, they must be installed at this time.

Implementation is optional.

## Parameters

### `lpfnUIDLLCallback`

Pointer to a function the UI DLL can call to communicate with the service provider DLL to obtain information needed to display the dialog box.

### `hwndOwner`

The handle of the parent window in which the function can create any dialog box windows that are required during installation.

### `dwPermanentProviderID`

The service provider's permanent provider identifier.

## Return value

Returns zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_OPERATIONFAILED, LINEERR_INIFILECORRUPT, LINEERR_NOMEM. LINEERR_INVALPARAM.

## Remarks

This function must leave the system in a consistent state. It should run to completion, not allowing the user to abort the installation when it is partly completed. If installation fails, it is the provider's responsibility to "back out" what was done and return an error. This may imply pre-scanning to verify that a complete installation is possible, before the installation begins.

This function can be invoked more than once during installation of the service provider, until there is a call to
[TUISPI_providerRemove](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_providerremove). If the service provider does not require or support multiple instances of the provider, however, it returns the
[LINEERR_ constant](https://learn.microsoft.com/windows/desktop/Tapi/lineerr--constants) LINEERR_NOMULTIPLEINSTANCE.

The corresponding function at the TAPI level is
[lineAddProvider](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineaddprovider). The
[LINE_CREATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725223(v=vs.85)) message informs applications that are running about dynamic reconfiguration.

## See also

[LINE_CREATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725223(v=vs.85))

[PHONE_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725262(v=vs.85))

[TSPI_providerInit](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerinit)

[TSPI_providerShutdown](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providershutdown)

[TUISPI_providerConfig](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_providerconfig)

[TUISPI_providerRemove](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_providerremove)