# IDWriteFactory5::CreateInMemoryFontFileLoader

## Description

Creates a loader object that can be used to create font file references to in-memory fonts. The caller is responsible for registering and unregistering the loader.

## Parameters

### `newLoader` [out]

Type: **[IDWriteInMemoryFontFileLoader](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwriteinmemoryfontfileloader)****

Receives a pointer to the newly-created loader object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[Creating a custom font set using font data loaded into memory](https://learn.microsoft.com/windows/win32/directwrite/custom-font-sets-win10#creating-a-custom-font-set-using-font-data-loaded-into-memory)

[IDWriteFactory5](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefactory5)