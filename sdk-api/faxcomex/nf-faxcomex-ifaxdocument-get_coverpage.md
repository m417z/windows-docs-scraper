# IFaxDocument::get_CoverPage

## Description

The **IFaxDocument::get_CoverPage** property is a null-terminated string that contains the name of the cover page template file (.cov) to associate with the fax document.

This property is read/write.

## Parameters

## Remarks

To specify a server-based cover page file, you must set the [IFaxDocument::get_CoverPageType](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument-coverpagetype-vb) property to [fcptSERVER](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_coverpage_type_enum).

To specify a local or personal cover page file, you must set the [IFaxDocument::get_CoverPageType](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument-coverpagetype-vb) property to [fcptLOCAL](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_coverpage_type_enum).

## See also

[FaxDocument](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument)

[IFaxDocument](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdocument)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-sending-a-fax)