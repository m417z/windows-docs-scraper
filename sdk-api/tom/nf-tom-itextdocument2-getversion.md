# ITextDocument2::GetVersion

## Description

Gets the version number of the Text Object Model (TOM) engine.

## Parameters

### `pValue` [out, retval]

Type: **long***

The version number. Byte 3 gives the major version number, byte 2 the minor version number, and the low-order 16 bits give the build number.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)

[ITextDocument2::GetGenerator](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument2-getgenerator)