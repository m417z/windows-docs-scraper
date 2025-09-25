# IDCompositionLinearTransferEffect::SetRedDisable

## Description

Specifies whether to apply the transfer function to the red channel.

## Parameters

### `redDisable` [in]

Type: **BOOL**

A boolean value that specifies whether to apply the transfer function to the red channel.
If you set this to TRUE the effect does not apply the transfer function to the red channel. If you set this to FALSE the effect applies the RedLinearTransfer function to the red channel.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDCompositionLinearTransferEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionlineartransfereffect)