# TSPI_providerInstall function

## Description

The
**TSPI_providerInstall** function is obsolete. TAPI version 1.4 or earlier service providers can implement this TSPI function. TAPI version 2.0 or later TSPs implement
[TUISPI_providerInstall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_providerinstall).

The
**TSPI_providerInstall** function installs any additional "pieces" of the provider into the right directories (or at least verifying that they're there), sets up the provider's registry entries for its lines and phones, and creates any other entries necessary for the service provider. It is called from the Telephony Control Panel utility (supplied with Windows Telephony in versions 1.4 and earlier) when the
**Add** button is pressed.

## Parameters

### `hwndOwner`

The handle of the parent window in which the function can create any dialog box windows that are required during installation.

### `dwPermanentProviderID`

The service provider's permanent provider identifier.

## Return value

Returns zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_OPERATIONFAILED, LINEERR_INIFILECORRUPT, LINEERR_NOMEM, LINEERR_INVALPARAM.

## Remarks

This function completes the installation of other pieces required by the service provider after its entries in the [Providers] section in the registry have been made. If the service provider requires any additional privately-defined entries in the registry for proper operation, they must also be installed. A typical way to install this section with its entries is to call
[TSPI_providerConfig](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerconfig).

This function must leave the system in a consistent state. It should run to completion, not allowing the user to abort the installation when it is partly completed. If installation fails, it is the provider's responsibility to "back out" what was done and return an error. This may imply pre-scanning to verify that a complete installation is possible, before the installation begins.

This function is called only once, during installation of the service provider, until there is a call to
[TSPI_providerRemove](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerremove). It must be called before any other TSPI-defined function.

The Telephony Control Panel utility supplied with Windows Telephony in versions 1.4 and earlier calls this function (with external sequence requirements met as described here) when the "add" command is invoked. It does not call
[TSPI_providerConfig](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerconfig) for the "add" command.

There is no corresponding function at the TAPI level. At that level, applications expect to have service providers already installed. Running applications are informed about dynamic reconfiguration through the LINEDEVSTATE_REINIT or PHONESTATE_REINIT value in the LINE_LINEDEVSTATE or PHONE_STATE message.

## See also

[LINE_LINEDEVSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725231(v=vs.85))

[PHONE_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725262(v=vs.85))

[TSPI_providerConfig](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerconfig)

[TSPI_providerInit](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerinit)

[TSPI_providerRemove](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerremove)

[TSPI_providerShutdown](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providershutdown)