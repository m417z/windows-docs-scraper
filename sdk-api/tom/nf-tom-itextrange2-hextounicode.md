# ITextRange2::HexToUnicode

## Description

Converts and replaces the hexadecimal number at the end of this range to a Unicode character.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Some Unicode surrogates for hex values from 0x10000 up to 0x10FFFF are for internal use:

| Hex values | Available for use |
| --- | --- |
| 7, 0xFDD0 — 0xFDEF, 0xFFF9 — 0xFFFF | Internal use only |
| 0xA — 0xD in the C0 range (0-0x1F) | Available for use |
| C1 range (0x80 — 0x9F) | Internal use only |

## See also

[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)