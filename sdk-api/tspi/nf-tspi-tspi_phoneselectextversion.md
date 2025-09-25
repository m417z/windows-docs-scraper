# TSPI_phoneSelectExtVersion function

## Description

The
**TSPI_phoneSelectExtVersion** function selects the indicated extension version for the indicated phone device. Subsequent requests operate according to that extension version.

## Parameters

### `hdPhone`

The handle to the phone for which an extension version is to be selected.

### `dwExtVersion`

The extension version to be selected. This version number is negotiated using
[TSPI_phoneNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonenegotiateextversion). The most-significant **WORD** is the major version number and the least-significant **WORD** is the minor version number. Calling this function with a *dwExtVersion* of zero cancels the current selection.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

PHONEERR_INCOMPATIBLEEXTVERSION, PHONEERR_OPERATIONFAILED, PHONEERR_NOMEM, PHONEERR_OPERATIONUNAVAIL, PHONEERR_RESOURCEUNAVAIL.

## Remarks

This function selects the indicated extension version. Although the indicated version number may have been successfully negotiated, a different extension version may have been selected in the interim, in which case this function fails (returning PHONEERR_INCOMPATIBLEEXTVERSION).

Subsequent operations on the phone after an extension version is selected behave according to that extension version. Subsequent attempts to negotiate the extension version report strictly the selected version or zero (if the requested range does not include the selected version). Calling this procedure with the special extension version 0 cancels the current selection. The device once again becomes capable of supporting its full range of extension version numbers.

**TSPI_phoneSelectExtVersion** is typically called in two situations: (1) An application requested to open a phone, the application requested that a particular extension version be used, and no extension version was currently selected; or (2) the last application using a particular extension version closed the phone, and the extension version selection can be canceled.

## See also

[TSPI_phoneNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonenegotiateextversion)