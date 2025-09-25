# TSPI_lineSelectExtVersion function

## Description

The
**TSPI_lineSelectExtVersion** function selects the indicated extension version for the indicated line device. Subsequent requests operate according to that extension version.

## Parameters

### `hdLine`

The handle to the line for which an extension version is to be selected.

### `dwExtVersion`

The extension version to be selected. This version number has been negotiated using
[TSPI_lineNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linenegotiateextversion). The most significant **WORD** is the major version number and the least significant **WORD** is the minor version number. Calling this function with a *dwExtVersion* of zero cancels the current selection.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INCOMPATIBLEEXTVERSION, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL, LINEERR_OPERATIONUNAVAIL.

## Remarks

The service provider selects the indicated extension version. Although the indicated version number may have been successfully negotiated, a different extension version may have been selected in the interim, in which case this function fails (returning LINEERR_INCOMPATIBLEEXTVERSION).

Subsequent operations on the line after an extension version has been selected behave according to that extension version. Subsequent attempts to negotiate the extension version report strictly the selected version or 0 (if the requested range does not include the selected version). Calling this procedure with the special extension version 0 cancels the current selection. The device becomes once again capable of supporting its full range of extension version numbers.

This function has no direct correspondence at the TAPI level, where selecting an extension version is bundled with the other functionality of
[lineOpen](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineopen). The
**TSPI_lineSelectExtVersion** function is typically called in two situations: (1) An application requested to open a line, the resulting change of media type monitoring was successful, the application requested that a particular extension version be used, and no extension version was currently selected. (2) The last application using a particular extension version closed the line, and the extension version selection can be canceled.

## See also

[TSPI_lineNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linenegotiateextversion)