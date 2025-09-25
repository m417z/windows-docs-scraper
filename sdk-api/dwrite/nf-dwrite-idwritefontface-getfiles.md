# IDWriteFontFace::GetFiles

## Description

 Obtains the font files representing a font face.

## Parameters

### `numberOfFiles` [in, out]

Type: **UINT32***

If *fontFiles* is **NULL**, receives the number of files representing the font face. Otherwise, the number of font files being requested should be passed. See the Remarks section below for more information.

### `fontFiles` [out, optional]

Type: **[IDWriteFontFile](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfile)****

When this method returns, contains a pointer to a user-provided array that stores pointers to font files representing the font face.
This parameter can be **NULL** if the user wants only the number of files representing the font face.
This API increments reference count of the font file pointers returned according to COM conventions, and the client
should release them when finished.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **IDWriteFontFace::GetFiles** method should be called twice. The first time you call **GetFiles***fontFiles* should be **NULL**. When the method returns, *numberOfFiles* receives the number of font files that represent the font face.

Then, call the method a second time, passing the *numberOfFiles* value that was output the first call, and a non-null buffer of the correct size to store the [IDWriteFontFile](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfile) pointers.

## See also

[IDWriteFontFace](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontface)