# IFaxDocument2::put_Bodies

## Description

Provides a collection of one or more documents to the fax document.

**Note** This property is supported only in Windows Vista and later.

This property is read/write.

## Parameters

## Remarks

Examples of documents that you can send as fax bodies include text files (.txt), Microsoft Word documents (.doc), or Microsoft Excel spreadsheets (.xls). Filenames are separated with semi-colons ";". For example, "myfile.txt;anotherfile.doc".

Either the **IFaxDocument2::Bodies** property or the [Body](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument-body-vb) property must be **NULL**. You must use **IFaxDocument2::Bodies** if you will be submitting using either [IFaxDocument2::ConnectedSubmit2](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument2-connectedsubmit2-vb) or [IFaxDocument2::Submit2](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument2-submit2-vb) (both available only in Windows Vista or later). You must use **Body** if you will be submitting using either [ConnectedSubmit](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument-connectedsubmit) or [Submit](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument-submit-vb).

## See also

[FaxDocument](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument)

[IFaxDocument2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdocument2)