# IDWriteFactory::GetSystemFontCollection

## Description

 Gets an object which represents the set of installed fonts.

## Parameters

### `fontCollection` [out]

Type: **[IDWriteFontCollection](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontcollection)****

When this method returns, contains the address of a pointer to the system font collection object, or **NULL** in case of failure.

### `checkForUpdates`

Type: **BOOL**

If this parameter is nonzero, the function performs an immediate check for changes to the set of
installed fonts. If this parameter is **FALSE**, the function will still detect changes if the font cache service is running, but
there may be some latency. For example, an application might specify **TRUE** if it has itself just installed a font and wants to
be sure the font collection contains that font.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFactory](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefactory)