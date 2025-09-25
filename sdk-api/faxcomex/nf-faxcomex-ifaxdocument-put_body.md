# IFaxDocument::put_Body

## Description

The **IFaxDocument::get_Body** property provides the path to the file that comprises the body of a fax. The body of a fax consists of the fax pages other than the cover page.

This property is read/write.

## Parameters

## Remarks

Examples of documents that you can send as a fax body are a text file (.txt), a Microsoft Word document (.doc), or a Microsoft Excel spreadsheet (.xls). When you send a fax from a client computer, the body has to be associated with an application that is installed on that computer, and the application has to support the **PrintTo** verb; otherwise, the fax will fail.

Either the [Bodies](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument2-bodies-vb) property or the **IFaxDocument::get_Body** property must be **NULL**. You must use **Bodies** if you will be submitting with either [ConnectedSubmit2](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument2-connectedsubmit2-vb) or [Submit2](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument2-submit2-vb) (both available only in Windows Vista or later). You must use **IFaxDocument::get_Body** if you will be submitting with either [ConnectedSubmit](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument-connectedsubmit) or [IFaxDocument::Submit](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument-submit-vb).

## See also

[FaxDocument](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument)

[IFaxDocument](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdocument)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-sending-a-fax)