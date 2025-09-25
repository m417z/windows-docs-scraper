# IPrintDocumentPackageTargetFactory::CreateDocumentPackageTargetForPrintJob

## Description

Acts as the entry point for creating an [IPrintDocumentPackageTarget](https://learn.microsoft.com/windows/desktop/api/documenttarget/nn-documenttarget-iprintdocumentpackagetarget) object.

## Parameters

### `printerName` [in]

The name of the target printer.

### `jobName` [in]

The name to apply to the job.

**Note** Job name strings longer than 63 characters will be truncated to 63 characters and a terminating **NULL**.

### `jobOutputStream` [in]

The job content. The application must set the seek pointer to the beginning before specifying the job output stream.

### `jobPrintTicketStream` [in]

A pointer to the **IStream** interface that is used by the caller to write the job-level print ticket that will be associated with this job.

### `docPackageTarget` [out]

The target output.

## Return value

If the **CreateDocumentPackageTargetForPrintJob** method completes successfully, it returns an S_OK. Otherwise it returns the appropriate HRESULT error code.

## See also

[IPrintDocumentPackageTarget](https://learn.microsoft.com/windows/desktop/api/documenttarget/nn-documenttarget-iprintdocumentpackagetarget)

[IPrintDocumentPackageTargetFactory](https://learn.microsoft.com/windows/desktop/api/documenttarget/nn-documenttarget-iprintdocumentpackagetargetfactory)