# TTDeleteEmbeddedFont function

## Description

Releases memory used by an embedded font, *hFontReference*.

By default, **TTDeleteEmbeddedFont** also removes the installed version of the font from the user's system. When an installable font is loaded, this function still must be called to release the memory used by the embedded font structure, but a flag can be specified indicating that the font should remain installed on the system.

## Parameters

### `hFontReference` [in]

Handle identifying font, as provided in the [TTLoadEmbeddedFont](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttloadembeddedfont) function.

### `ulFlags` [in]

Flag specifying font deletion options. Currently, this flag can be set to zero or the following value:

| Value | Meaning |
| --- | --- |
| **TTDELETE_DONTREMOVEFONT** | Do not remove the installed font from the system, but release the memory previously occupied by the embedded font structure. |

### `pulStatus` [out]

Currently undefined.

## Return value

If successful, **TTDeleteEmbeddedFont** returns a value of E_NONE.

The memory occupied by the embedded font structure is cleared. By default, the font indicated by *hFontReference* is also permanently removed (uninstalled and deleted) from the system.

Otherwise, returns an error code described in [Embedding-Function Error Messages](https://learn.microsoft.com/windows/desktop/gdi/font-embedding-function-error-messages).

## Remarks

The client is responsible for calling this function to remove fonts when the embedding privileges do not allow a font to be permanently installed on a user's system.

## See also

[TTLoadEmbeddedFont](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttloadembeddedfont)