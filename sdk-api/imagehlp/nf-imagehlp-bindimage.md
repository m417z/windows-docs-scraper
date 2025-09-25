# BindImage function

## Description

Computes the virtual address of each imported function.

This function has been superseded by the
[BindImageEx](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-bindimageex) function. Use
**BindImageEx** to provide a status routine or flags to control the image binding.

## Parameters

### `ImageName` [in]

The name of the file to be bound. This value can be a file name, a partial path, or a full path.

### `DllPath` [in]

The root of the search path to use if the file specified by the *ImageName* parameter cannot be opened.

### `SymbolPath` [in]

The root of the path to search for the file's corresponding symbol file.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A call to
**BindImage** is equivalent to the following call: `BindImageEx( 0, ImageName, DllPath, SymbolPath, NULL );`

All ImageHlp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[BindImageEx](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-bindimageex)

[ImageHlp Functions](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-functions)