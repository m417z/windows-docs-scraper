# IXpsDocumentConsumer::GetNewEmptyPart

## Description

The `GetNewEmptyPart` method creates a new XPS part.

## Parameters

### `uri` [in]

The URI for the new part to be created.

### `riid` [in]

A reference identifier (REFIID) for one of the following interfaces:

* [IFixedDocument](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-ifixeddocument)
* [IFixedPage](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-ifixedpage)
* [IPartImage](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-ipartimage)
* [IPartThumbnail](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-ipartthumbnail)
* [IPartFont](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-ipartfont)
* [IPartPrintTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-ipartprintticket)
* [IPartColorProfile](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-ipartcolorprofile)

### `ppNewObject` [out]

A pointer to the new object to be created.

### `ppWriteStream` [out]

A data stream object that the part will be written to. Each part is associated with a data stream object.

## Return value

`GetNewEmptyPart` returns an **HRESULT**.

## Remarks

A filter can create new XPS parts by using the `GetNewEmptyPart` method. Typically, the filter receives XPS parts from the inter-filter object.

## See also

[IFixedDocument](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-ifixeddocument)

[IFixedPage](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-ifixedpage)

[IPartColorProfile](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-ipartcolorprofile)

[IPartFont](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-ipartfont)

[IPartImage](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-ipartimage)

[IPartPrintTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-ipartprintticket)

[IPartThumbnail](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-ipartthumbnail)

[IXpsDocumentConsumer](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-ixpsdocumentconsumer)