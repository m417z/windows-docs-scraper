# AddFontMemResourceEx function

## Description

The **AddFontMemResourceEx** function adds the font resource from a memory image to the system.

## Parameters

### `pFileView` [in]

A pointer to a font resource.

### `cjSize` [in]

The number of bytes in the font resource that is pointed to by *pbFont*.

### `pvResrved` [in]

Reserved. Must be 0.

### `pNumFonts` [in]

A pointer to a variable that specifies the number of fonts installed.

## Return value

If the function succeeds, the return value specifies the handle to the font added. This handle uniquely identifies the fonts that were installed on the system. If the function fails, the return value is zero. No extended error information is available.

## Remarks

This function allows an application to get a font that is embedded in a document or a webpage. A font that is added by **AddFontMemResourceEx** is always private to the process that made the call and is not enumerable.

A memory image can contain more than one font. When this function succeeds, *pcFonts* is a pointer to a **DWORD** whose value is the number of fonts added to the system as a result of this call. For example, this number could be 2 for the vertical and horizontal faces of an Asian font.

When the function succeeds, the caller of this function can free the memory pointed to by *pbFont* because the system has made its own copy of the memory. To remove the fonts that were installed, call [RemoveFontMemResourceEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-removefontmemresourceex). However, when the process goes away, the system will unload the fonts even if the process did not call [RemoveFontMemResource](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-removefontmemresourceex).

## See also

[DESIGNVECTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-designvector)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[RemoveFontMemResourceEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-removefontmemresourceex)

[SendMessage](https://learn.microsoft.com/previous-versions/windows/desktop/oe/oe-ihttpmailtransport-sendmessage)