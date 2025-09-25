# ITextDocument2::GetImmContext

## Description

Gets the Input Method Manager (IMM) input context from the Text Object Model (TOM) host.

## Parameters

### `pContext` [out, retval]

Type: **__int64***

The IMM input context.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)

[ITextDocument2::ReleaseIMMContext](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument2-releaseimmcontext)