# IFaxDocument::get_CoverPageType

## Description

The **IFaxDocument::get_CoverPageType** property is a value from an enumeration that indicates whether a specified cover page template file (.cov) is a server-based cover page file or a local-computer-based cover page file. You can also specify that no file is used.

This property is read/write.

## Parameters

## Remarks

By default, **IFaxDocument::get_CoverPageType** is set to [fcptNONE](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_coverpage_type_enum), indicating that no file is used.

Provide the name of the cover page in the [IFaxDocument::get_CoverPage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument-coverpage-vb) property.

## See also

[FaxDocument](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument)

[IFaxDocument](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdocument)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-sending-a-fax)