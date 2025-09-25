# PrivateFontCollection::AddMemoryFont

## Description

The **PrivateFontCollection::AddMemoryFont** method adds a font that is contained in system memory to a Windows GDI+ font collection.

## Parameters

### `memory` [in]

Type: **const VOID***

Pointer to a font that is contained in memory.

### `length` [in]

Type: **INT**

Integer that specifies the number of bytes of data in the font.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

When you use the GDI+ API, you must never allow your application to download arbitrary fonts from untrusted sources.
The operating system requires elevated privileges to assure that all installed fonts are trusted.

## See also

[Creating a Private Font Collection](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-private-font-collection-use)

[PrivateFontCollection](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-privatefontcollection)

[PrivateFontCollection::AddFontFile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-privatefontcollection-addfontfile)

[Using Text and Fonts](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-text-and-fonts-use)