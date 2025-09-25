# IInkLineInfo::GetInkExtent

## Description

Specifies the display properties to set on the text ink object (tInk), and retrieves the width of the text ink object in HIMETRIC units.

## Parameters

### `pim` [in]

A pointer to an [INKMETRIC](https://learn.microsoft.com/windows/desktop/api/msinkaut/ns-msinkaut-inkmetric) structure, which contains the display properties to set on the text ink object, or **NULL**.

### `pnWidth` [out]

The width of the text ink object in HIMETRIC units.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | The *pnWidth* parameter is **NULL**. |
| **E_OUTOFMEMORY** | Could not complete the operation. The display properties are not changed. |

## Remarks

If the *pim* parameter is **NULL**, then the display properties are not changed and the existing properties are used to calculate the extent of the text ink object; otherwise, the display properties are updated, and the extent is calculated from the new properties.

If the IMF_FONT_SELECTED_IN_HDC flag is set in the *pim* parameter, then the properties of the device context are applied to the ink; otherwise, the [INKMETRIC](https://learn.microsoft.com/windows/desktop/api/msinkaut/ns-msinkaut-inkmetric) settings of the text ink object are applied.

## See also

[GetFormat Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinklineinfo-getformat)

[IInkLineInfo](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinklineinfo)

[INKMETRIC Structure](https://learn.microsoft.com/windows/desktop/api/msinkaut/ns-msinkaut-inkmetric)

[SetFormat Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinklineinfo-setformat)