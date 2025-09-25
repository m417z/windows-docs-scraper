# IDCompositionTableTransferEffect::SetGreenDisable

## Description

Specifies whether to apply the transfer function to the green channel.

## Parameters

### `greenDisable` [in]

Type: **BOOL**

A boolean value that specifies whether to apply the transfer function to the green channel.
If you set this to TRUE the effect does not apply the transfer function to the green channel. If you set this to FALSE it applies the GreenTableTransfer function to the green channel.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDCompositionTableTransferEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontabletransfereffect)