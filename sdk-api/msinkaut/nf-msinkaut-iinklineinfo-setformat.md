# IInkLineInfo::SetFormat

## Description

Specifies the display properties to set on the text ink object (tInk).

## Parameters

### `pim` [in]

A pointer to an [INKMETRIC](https://learn.microsoft.com/windows/desktop/api/msinkaut/ns-msinkaut-inkmetric) structure which contains the display properties to set on the text ink object.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pim* parameter is **NULL**. |
| **E_OUTOFMEMORY** | Could not complete the operation. The display properties are not changed. |

## Remarks

If the IMF_FONT_SELECTED_IN_HDC flag is set in the *pim* parameter, then the properties of the device context are applied to the ink; otherwise, the [INKMETRIC](https://learn.microsoft.com/windows/desktop/api/msinkaut/ns-msinkaut-inkmetric) settings of the text ink object are applied.

## See also

[GetFormat Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinklineinfo-getformat)

[GetInkExtent Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinklineinfo-getinkextent)

[IInkLineInfo](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinklineinfo)

[INKMETRIC Structure](https://learn.microsoft.com/windows/desktop/api/msinkaut/ns-msinkaut-inkmetric)