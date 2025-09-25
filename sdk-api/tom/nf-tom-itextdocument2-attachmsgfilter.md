# ITextDocument2::AttachMsgFilter

## Description

Attaches a new message filter to the edit instance. All window messages that the edit instance receives are forwarded to the message filter.

## Parameters

### `pFilter` [in]

Type: **IUnknown***

The message filter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 The message filter must be bound to the document before it can be used.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)