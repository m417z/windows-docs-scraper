# TTEMBEDINFO structure

## Description

The **TTEMBEDINFO** structure contains a list of URLs from which the embedded font object may be legitimately referenced.

## Members

### `usStructSize`

Size, in bytes, of this structure. The client should set this value to **sizeof**(TTEMBEDINFO).

### `usRootStrSize`

Size, in wide characters, of *pusRootStr* including NULL terminator(s).

### `pusRootStr`

One or more full URLs that the embedded font object may be referenced from. Multiple URLs, separated by NULL terminators, can be specified.

## See also

[TTEmbedFont](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttembedfont)

[TTEmbedFontEx](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttembedfontex)

[TTEmbedFontFromFileA](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttembedfontfromfilea)

[TTLoadEmbeddedFont](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttloadembeddedfont)