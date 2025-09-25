# Region::Region(IN const BYTE,IN INT)

## Description

Creates a region that is defined by data obtained from another region.

## Parameters

### `regionData` [in]

Type: **const BYTE***

Pointer to an array of bytes that specifies a region. The data contained in the bytes is obtained from another region by using the
[Region::GetData](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-region-getdata) method.

### `size` [in]

Type: **INT**

Integer that specifies the number of bytes in the
*regionData* array.