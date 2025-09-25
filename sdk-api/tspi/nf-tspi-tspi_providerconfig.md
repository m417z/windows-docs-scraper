# TSPI_providerConfig function

## Description

The
**TSPI_providerConfig** function is obsolete. TAPI version 1.4 or earlier service providers can implement this TSPI function. TAPI version 2.0 or later TSPs implement
[TUISPI_providerConfig](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_providerconfig).

The
**TSPI_providerConfig** function gathers configuration information from the user. It may use a dialog box, and this dialog box can include sub-dialog boxes associated with other APIs (such as Comm/datamodem) for the setup of specific devices.

## Parameters

### `hwndOwner`

The handle of the parent window in which the function can create any dialog box windows required during the configuration.

### `dwPermanentProviderID`

The service provider's permanent provider identifier.

## Return value

Returns zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_OPERATIONFAILED, LINEERR_NOMEM.

## Remarks

This function may be called while the service provider is in use (that is, between calls of
[TSPI_providerInit](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerinit) and
[TSPI_providerShutdown](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providershutdown)).

Any changes that affect the behavior visible through TSPI should take effect only when the service provider is restarted at the next
[TSPI_providerInit](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerinit).

The Telephony Control Panel utility supplied with Windows Telephony in versions 1.4 and earlier calls this function when the setup command is invoked.

There is no directly corresponding function at the TAPI level. In TAPI, applications have access to the functions
[lineConfigDialog](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineconfigdialog) and
[phoneConfigDialog](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneconfigdialog), which allow configuration of parameters of a particular line or phone once it has been installed.

## See also

[TSPI_lineConfigDialog](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineconfigdialog)

[TSPI_phoneConfigDialog](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phoneconfigdialog)

[TSPI_providerInstall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerinstall)

[TSPI_providerRemove](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerremove)

[TUISPI_providerConfig](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_providerconfig)