# IDWriteFontFace::TryGetFontTable

## Description

 Finds the specified OpenType font table if it exists and returns a pointer to it.
The function accesses the underlying font data through the [IDWriteFontFileStream](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfilestream) interface
implemented by the font file loader.

## Parameters

### `openTypeTableTag` [in]

Type: **UINT32**

The four-character tag of a OpenType font table to find.
Use the **DWRITE_MAKE_OPENTYPE_TAG** macro to create it as an **UINT32**.
Unlike GDI, it does not support the special TTCF and null tags to access the whole font.

### `tableData` [out]

Type: **const void****

When this method returns, contains the address of a pointer to the base of the table in memory.
The pointer is valid only as long as the font face used to get the font table still exists;
(not any other font face, even if it actually refers to the same physical font).
This parameter is passed uninitialized.

### `tableSize` [out]

Type: **UINT32***

When this method returns, contains a pointer to the size, in bytes, of the font table.

### `tableContext` [out]

Type: **void****

When this method returns, the address of a pointer to the opaque context, which must be freed by calling [ReleaseFontTable](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefontface-releasefonttable).
The context actually comes from the lower-level [IDWriteFontFileStream](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfilestream),
which may be implemented by the application or DWrite itself.
It is possible for a **NULL** *tableContext* to be returned, especially if
the implementation performs direct memory mapping on the whole file.
Nevertheless, always release it later, and do not use it as a test for function success.
The same table can be queried multiple times,
but because each returned context can be different, you must release each context separately.

### `exists` [out]

Type: **BOOL***

When this method returns, **TRUE** if the font table exists; otherwise, **FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 The context for the same tag may be different for each call,
so each one must be held and released separately.

## See also

[IDWriteFontFace](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontface)