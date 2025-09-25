# HH_POPUP structure

## Description

Use this structure to specify or modify the attributes of a pop-up window.

## Members

### `cbStruct`

Specifies the size of the structure. This value must always be filled in before passing the structure to HtmlHelp().

### `hinst`

Instance handle of the program or DLL to retrieve the string resource from. Ignored if *idString* is zero, or if *idString* specifies a file name.

### `idString`

Specifies zero, a resource ID, or a topic number in a text file.

### `pszText`

Specifies the text to display if *idString* is zero.

### `pt`

Specifies (in pixels) where the top center of the pop-up window should be located.

### `clrForeground`

Specifies the RGB value to use for the foreground color of the pop-up window. To use the system color for the window text, specify -1.

### `clrBackground`

Specifies the RGB value to use for the background color of the pop-up window. To use the system color for the window background, specify -1.

### `rcMargins`

Specifies (in pixels) the margins to use on the left, top, right, and bottom sides of the pop-up window. The default for all rectangle members is -1.

### `pszFont`

Specifies the font attributes to use for the text in the pop-up window.

Use the following format to specify font family, point size, character set, and font format:

facename[, point size[, charset[ BOLD ITALIC UNDERLINE]]]

To omit an attribute, enter a comma. For example, to specify bold, 10-pt, MS Sans Serif font, *pszFont* would be:

MS Sans Serif, 10, , BOLD

## See also

[About Structures](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/about-structures)