# ITextFont2::GetCompressionMode

## Description

Gets the East Asian compression mode.

## Parameters

### `pValue` [out, retval]

Type: **long***

The compression mode, which can be one of these values:

#### tomCompressNone (default)

#### tomCompressPunctuation

#### tomCompressPunctuationAndKana

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)

[ITextFont2::SetCompressionMode](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont2-setcompressionmode)