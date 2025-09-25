# ITextHost::TxImmReleaseContext

## Description

Releases an input context returned by the [ITextHost::TxImmGetContext](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-tximmgetcontext) method and unlocks the memory associated with the context.

This method is used only in Asian-language versions of the operating system.

## Parameters

### `himc` [in]

Type: **HIMC**

The input context.

## See also

**Conceptual**

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

**Reference**

[TxImmGetContext](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-tximmgetcontext)

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)