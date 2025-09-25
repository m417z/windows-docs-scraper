# IDWriteFactory3::GetSystemFontCollection

## Description

Retrieves a weight/width/slope tree of system fonts.

## Parameters

### `includeDownloadableFonts`

Type: **BOOL**

Indicates whether to include cloud fonts or only locally installed fonts.

### `fontCollection`

Type: **[IDWriteFontCollection1](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontcollection1)****

Holds the newly created font collection object, or NULL in case of failure.

### `checkForUpdates`

Type: **BOOL**

If this parameter is TRUE, the function performs an immediate check for changes
to the set of system fonts. If this parameter is FALSE, the function will still detect changes if the font
cache service is running, but there may be some latency. For example, an application might specify TRUE if
it has just installed a font and wants to be sure the font collection contains that font.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFactory3](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefactory3)