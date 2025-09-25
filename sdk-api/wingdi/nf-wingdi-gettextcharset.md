# GetTextCharset function

## Description

Retrieves a character set identifier for the font that is currently selected into a specified device context.

**Note** A call to this function is equivalent to a call to [GetTextCharsetInfo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextcharsetinfo) passing **NULL** for the data buffer.

## Parameters

### `hdc` [in]

Handle to a device context. The function obtains a character set identifier for the font that is selected into this device context.

## Return value

If successful, returns a value identifying the character set of the font that is currently selected into the specified device context.

For a list of possible values, see *lfCharSet* field of the [LOGFONT structure](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfontw).

If the function fails, it returns **DEFAULT_CHARSET**.

## See also

[GetTextCharsetInfo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextcharsetinfo)

[Unicode and Character Set Functions](https://learn.microsoft.com/windows/desktop/Intl/unicode-and-character-set-functions)

[Unicode and Character Sets](https://learn.microsoft.com/windows/desktop/Intl/unicode-and-character-sets)