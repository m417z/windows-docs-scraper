# Region::FromHRGN

## Description

The **Region::FromHRGN** method creates a Windows GDI+[Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region) object from a Windows Graphics Device Interface (GDI) region.

## Parameters

### `hRgn` [in]

Type: **HRGN**

Handle to an existing GDI region.

## Return value

Type: **[Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region)***

This method returns a pointer to the new
[Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region) object.