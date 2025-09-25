# lineConfigProvider function

## Description

The
**lineConfigProvider** function causes a service provider to display its configuration dialog box.

## Parameters

### `hwndOwner`

Handle to a window to which the configuration dialog box (displayed by
[TSPI_providerConfig](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerconfig)) is attached. Can be **NULL** to indicate that any window created during the function should have no owner window.

### `dwPermanentProviderID`

Permanent provider identifier of the service provider to be configured.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INIFILECORRUPT, LINEERR_NOMEM, LINEERR_INVALPARAM, LINEERR_OPERATIONFAILED.

## Remarks

This is basically a straight pass-through to
[TSPI_providerConfig](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerconfig).

## See also

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)