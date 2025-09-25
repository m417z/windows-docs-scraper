# ITextDocument2::CheckTextLimit

## Description

Checks whether the number of characters to be added would exceed the maximum text limit.

## Parameters

### `cch` [in]

Type: **long**

The number of characters to be added.

### `pcch` [out]

Type: **long***

The number of characters that exceed the maximum text limit. This parameter is 0 if the number of characters does not exceed the limit.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)