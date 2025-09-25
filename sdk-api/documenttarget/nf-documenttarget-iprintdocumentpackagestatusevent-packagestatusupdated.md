# IPrintDocumentPackageStatusEvent::PackageStatusUpdated

## Description

Updates the status of the package when the print job in progress raises an event, or the job completes.

## Parameters

### `packageStatus` [in]

The status update.

## Return value

If the **PackageStatusUpdated** method completes successfully, it returns an S_OK. Otherwise it returns an appropriate HRESULT error code.

## See also

[IPrintDocumentPackageStatusEvent](https://learn.microsoft.com/windows/desktop/api/documenttarget/nn-documenttarget-iprintdocumentpackagestatusevent)

[PrintDocumentPackageStatus](https://learn.microsoft.com/windows/win32/api/documenttarget/ns-documenttarget-printdocumentpackagestatus)