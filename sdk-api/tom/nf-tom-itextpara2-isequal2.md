# ITextPara2::IsEqual2

## Description

Determines whether this text paragraph object has the same properties as the specified text paragraph object.

## Parameters

### `pPara` [in]

Type: **ITextPara2***

The text paragraph object to compare against.

### `pB` [out, retval]

Type: **long***

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that is **tomTrue** if the text paragraph objects have the same properties, or **tomFalse** if they don't. This parameter can be **NULL**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextPara2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara2)