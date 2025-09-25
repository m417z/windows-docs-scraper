# lineRemoveProvider function

## Description

The
**lineRemoveProvider** function removes an existing telephony service provider from the telephony system.

## Parameters

### `dwPermanentProviderID`

Permanent provider identifier of the service provider to be removed.

### `hwndOwner`

Handle to a window to which any dialog boxes that need to be displayed as part of the removal process (for example, a confirmation dialog box by the service provider's
[TSPI_providerRemove](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerremove) function) would be attached. Can be a **NULL** value to indicate that any window created during the function should have no owner window.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INIFILECORRUPT, LINEERR_NOMEM, LINEERR_INVALPARAM, LINEERR_OPERATIONFAILED.

## Remarks

If the call to
[TSPI_providerRemove](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerremove) succeeds, and the telephony system is active at the time, TAPI calls
[lineShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineshutdown) and/or
[phoneShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneshutdown) on the service provider (depending on which device types are active). Any line or phone handles still held by applications on associated devices are forcibly closed with
[LINE_CLOSE](https://learn.microsoft.com/windows/desktop/Tapi/line-close) or
[PHONE_CLOSE](https://learn.microsoft.com/windows/desktop/Tapi/phone-close) messages (it is preferable for service providers to issue these messages as part of
[TSPI_providerRemove](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerremove), after verification with the user). The devices previously under the control of that provider are then marked as "unavailable", so that any future attempts by applications to reference them by device identifier result in LINEERR_NODRIVER.

## See also

[LINE_CLOSE](https://learn.microsoft.com/windows/desktop/Tapi/line-close)

[PHONE_CLOSE](https://learn.microsoft.com/windows/desktop/Tapi/phone-close)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)