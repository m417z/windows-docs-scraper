# ITextDocument2::GetCallManager

## Description

Gets the call manager.

## Parameters

### `ppVoid` [out, retval]

Type: **IUnknown****

The call manager object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The call manager object is opaque to the caller. The Text Object Model (TOM) engine uses the object to handle internal notifications for particular scenarios.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)

[ITextDocument2::ReleaseCallManager](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument2-releasecallmanager)