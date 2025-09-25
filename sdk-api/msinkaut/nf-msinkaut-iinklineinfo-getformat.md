# IInkLineInfo::GetFormat

## Description

Returns the display properties currently set on the text ink object (tInk).

## Parameters

### `pim` [out]

A pointer to an [INKMETRIC](https://learn.microsoft.com/windows/desktop/api/msinkaut/ns-msinkaut-inkmetric) structure that stores the display properties of the text ink object.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pim* parameter is **NULL**. |

## See also

[GetInkExtent Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinklineinfo-getinkextent)

[IInkLineInfo](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinklineinfo)

[INKMETRIC Structure](https://learn.microsoft.com/windows/desktop/api/msinkaut/ns-msinkaut-inkmetric)

[SetFormat Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinklineinfo-setformat)