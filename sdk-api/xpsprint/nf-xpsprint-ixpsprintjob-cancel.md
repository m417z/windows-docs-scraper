# IXpsPrintJob::Cancel

## Description

[IXpsPrintJob::Cancel is not supported and may be altered or unavailable in the future. ]

Cancels the print job.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

Any spooling or printing that is in progress at the time this method is called will be canceled.

This function is thread-safe and synchronized with the job status of the print job object.

## See also

[Documents](https://learn.microsoft.com/previous-versions/windows/desktop/dd316975(v=vs.85))

[IXpsPrintJob](https://learn.microsoft.com/windows/desktop/api/xpsprint/nn-xpsprint-ixpsprintjob)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)