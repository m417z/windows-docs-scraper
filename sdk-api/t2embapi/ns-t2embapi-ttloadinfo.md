# TTLOADINFO structure

## Description

The **TTLOADINFO** structure contains the URL from which the embedded font object has been obtained.

## Members

### `usStructSize`

Size, in bytes, of this structure. The client should set this value to **sizeof**(TTLOADINFO).

### `usRefStrSize`

Size, in wide characters, of *pusRefStr*, including the terminating null character.

### `pusRefStr`

Pointer to the string containing the current URL.

## See also

[TTEMBEDINFO](https://learn.microsoft.com/windows/desktop/api/t2embapi/ns-t2embapi-ttembedinfo)

[TTLoadEmbeddedFont](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttloadembeddedfont)