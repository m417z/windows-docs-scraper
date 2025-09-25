# ITextStrings::Item

## Description

Gets an [ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2) object for a selected index in a string collection.

## Parameters

### `Index` [in]

Type: **long**

The index of the string to retrieve. The default value is 1.

### `ppRange` [out, retval]

Type: **[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)****

The object to receive the range.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The first string corresponds to Index = 1 and the last to Count which is given by [ITextStrings_GetCount](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextstrings-getcount).

## See also

[ITextStrings](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstrings)