# GetTextCharsetInfo function

## Description

Retrieves information about the character set of the font that is currently selected into a specified device context.

## Parameters

### `hdc` [in]

Handle to a device context. The function obtains information about the font that is selected into this device context.

### `lpSig` [out, optional]

Pointer to a [FONTSIGNATURE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-fontsignature) data structure that receives font-signature information.

If a TrueType font is currently selected into the device context, the [FONTSIGNATURE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-fontsignature) structure receives information that identifies the code page and Unicode subranges for which the font provides glyphs.

If a font other than TrueType is currently selected into the device context, the [FONTSIGNATURE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-fontsignature) structure receives zeros. In this case, the application should use the [TranslateCharsetInfo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-translatecharsetinfo) function to obtain generic font-signature information for the character set.

The *lpSig* parameter specifies **NULL** if the application does not require the [FONTSIGNATURE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-fontsignature) information. In this case, the application can also call the [GetTextCharset](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextcharset) function, which is equivalent to calling **GetTextCharsetInfo** with *lpSig* set to **NULL**.

### `dwFlags` [in]

Reserved; must be set to 0.

## Return value

If successful, returns a value identifying the character set of the font currently selected into the specified device context.

For a list of possible values, see *lfCharSet* field of the [LOGFONT structure](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfontw).

If the function fails, the return value is **DEFAULT_CHARSET**.

## See also

[FONTSIGNATURE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-fontsignature)

[GetTextCharset](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextcharset)

[TranslateCharsetInfo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-translatecharsetinfo)

[Unicode and Character Set Functions](https://learn.microsoft.com/windows/desktop/Intl/unicode-and-character-set-functions)

[Unicode and Character Sets](https://learn.microsoft.com/windows/desktop/Intl/unicode-and-character-sets)