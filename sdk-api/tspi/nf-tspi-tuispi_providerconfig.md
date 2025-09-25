# TUISPI_providerConfig function

## Description

The
**TUISPI_providerConfig** function implements the UI elements that must execute in the context of the calling application. This function makes the
[TSPI_providerConfig](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerconfig) function obsolete in version 2.0 and later (supported in version 1.4 and earlier).

The
**TUISPI_providerConfig** function gathers configuration information from the user. It can use a dialog box, and this dialog box can include sub-dialog boxes associated with other APIs (such as Comm/datamodem) for the setup of specific devices.

Implementation is optional.

## Parameters

### `lpfnUIDLLCallback`

Pointer to a function the UI DLL can call to communicate with the service provider DLL to obtain information needed to display the dialog box and to send updated configuration to the service provider.

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

There is no directly corresponding function at the TAPI level. In TAPI, applications have access to the functions
[lineConfigDialog](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineconfigdialog) and
[phoneConfigDialog](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneconfigdialog), which allow configuration of parameters of a particular line or phone once it has been installed.

## See also

[TUISPI_lineConfigDialog](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_lineconfigdialog)

[TUISPI_phoneConfigDialog](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_phoneconfigdialog)

[TUISPI_providerInstall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_providerinstall)

[TUISPI_providerRemove](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_providerremove)