# IBitmapData::GetSourceBitmapDescription

## Description

Gets a [BitmapDescription](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/ns-xamlom-bitmapdescription) that describes the original format of the bitmap data stored in the [IBitmapData](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ibitmapdata).

## Parameters

### `pBitmapDescription` [out]

Information about the original format of the bitmap stored in the [IBitmapData](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ibitmapdata).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This will have the same value as the [BitmapDescription](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/ns-xamlom-bitmapdescription) returned by [GetBitmapDescription](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nf-xamlom-ibitmapdata-getbitmapdescription) unless the bitmap data was format converted or scaled. Format conversion and scaling will occur as necessary to meet the contract of the method that returned the [IBitmapData](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ibitmapdata).

## See also

[IBitmapData](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ibitmapdata)