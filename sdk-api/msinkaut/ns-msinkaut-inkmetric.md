# INKMETRIC structure

## Description

Specifies display properties for a text ink object (tInk).

## Members

### `iHeight`

Ink height.

### `iFontAscent`

Assent height.

### `iFontDescent`

Descent height.

### `dwFlags`

Ink metric flags.

| Ink Metric Flags | Meaning |
| --- | --- |
| **IMF_FONT_SELECTED_IN_HDC** | Use the ambient properties of the surrounding text. |
| **IMF_ITALIC** | Apply the italic style. |
| **IMF_BOLD** | Apply the bold style. |

### `color`

Ink color.

## Remarks

The **iHeight**, **iFontAssent** and **iFontDescent** fields are in **HIMETRIC** units.

Applying italics to a text ink object slants the ink to the right.

## See also

[GetFormat Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinklineinfo-getformat)

[GetInkExtent Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinklineinfo-getinkextent)

[SetFormat Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinklineinfo-setformat)