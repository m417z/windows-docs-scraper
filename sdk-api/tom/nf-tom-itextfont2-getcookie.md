# ITextFont2::GetCookie

## Description

Gets the client cookie.

## Parameters

### `pValue` [out, retval]

Type: **long***

The client cookie.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This value is purely for the use of the client and has no meaning to the Text Object Model (TOM) engine. There are exceptions where different values correspond to different character format runs.

## See also

[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)

[ITextFont2::SetCookie](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont2-setcookie)