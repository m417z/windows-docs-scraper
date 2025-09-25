# IDCompositionLinearTransferEffect::SetAlphaDisable

## Description

Specifies whether to apply the transfer function to the alpha channel.

## Parameters

### `alphaDisable` [in]

Type: **BOOL**

A boolean value that specifies whether to apply the transfer function to the alpha channel.
If you set this to TRUE the effect does not apply the transfer function to the Alpha channel. If you set this to FALSE it applies the AlphaLinearTransfer function to the Alpha channel.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDCompositionLinearTransferEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionlineartransfereffect)