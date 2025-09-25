# IXpsOMPackageWriter3D::SetModelPrintTicket

## Description

Creates a print ticket with the specified part.

## Parameters

### `printTicketPartName` [in]

The part is added to package and becomes a target of relationship from model part.

### `printTicketData` [in]

A readable stream that holds the 3D model print ticket.

## Return value

Returns the appropriate HRESULT error code. Calling this method more than once per package writer returns the error XPS_E_MULTIPLE_PRINTICKETS_ON_DOCUMENT.

## Remarks

Call this method at most once per package writer. Calling this method creates a part with content type “application/vnd.ms-printing.printticket+xml”. It is linked from model part with relationship type “http://schemas.microsoft.com/3dmanufacturing/2013/01/printticket” .

## See also

[IXpsOMPackageWriter3D](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel_2/nn-xpsobjectmodel_2-ixpsompackagewriter3d)