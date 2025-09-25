# TUISPI_providerRemove function

## Description

The
**TUISPI_providerRemove** function asks the user to confirm elimination of the service provider. This function makes the
[TSPI_providerRemove](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerremove) function obsolete in version 2.0 and later (supported in version 1.4 and earlier).

It is the responsibility of the service provider to remove any registry entries that the service provider added at **addProvider** time, as well as any other modules and files that are no longer needed.

Implementation is optional.

## Parameters

### `lpfnUIDLLCallback`

Pointer to a function the UI DLL can call to communicate with the service provider DLL to obtain information needed to display the dialog box.

### `hwndOwner`

The handle of the parent window in which the function can create any dialog box windows required during the removal.

### `dwPermanentProviderID`

The service provider's permanent provider identifier.

## Return value

Returns zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_OPERATIONFAILED, LINEERR_INIFILECORRUPT, LINEERR_NOMEM, LINEERR_INVALPARAM.

## Remarks

This function must guarantee that any service provider's privately-defined information is removed from the registry if it returns success.

This procedure must leave the system in a consistent state. It should run to completion, not allowing the user to abort the removal when it is partly completed. If removal fails, it is the provider's responsibility to "back out" what was done and return an error. This may imply pre-scanning to verify that a complete removal is possible, before the removal begins.

This function can be called while the service provider is in use (that is, between
[TSPI_providerInit](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerinit) and
[TSPI_providerShutdown](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providershutdown)). If this happens, the service provider should do an appropriate combination of displaying a user dialog box to announce any conflict and confirm removal, restricting removal options to those that can be performed transparently, or issuing
[LINE_CLOSE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725220(v=vs.85)) and
[PHONE_CLOSE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725255(v=vs.85)) messages to inform TAPI and applications that the affected devices have been forcibly closed for removal. In any case, any changes that affect the behavior visible through TSPI should take effect only when the service provider is shut down at the next
**TSPI_providerShutdown**.

**Note** This function should not return LINEERR_INUSE or other errors that might occur because the provider is in use by an application; instead, the provider should confer with the user directly about this problem, and then return LINEERR_OPERATIONFAILED if the user decides to abort the operation.

This procedure is called only once, at the time of removal of the service provider, until there is a call to
[TUISPI_providerInstall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_providerinstall).

The corresponding function at the TAPI level is
[lineRemoveProvider](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineremoveprovider). At that level, applications expect to have service providers already installed; otherwise their lines and phones do not appear within the available sequence of device identifiers. The
[LINE_CREATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725223(v=vs.85)) message informs applications that are running about dynamic reconfiguration.

## See also

[LINE_CLOSE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725220(v=vs.85))

[PHONE_CLOSE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725255(v=vs.85))

[PHONE_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725262(v=vs.85))

[TSPI_providerInit](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerinit)

[TSPI_providerShutdown](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providershutdown)

[TUISPI_providerInstall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_providerinstall)