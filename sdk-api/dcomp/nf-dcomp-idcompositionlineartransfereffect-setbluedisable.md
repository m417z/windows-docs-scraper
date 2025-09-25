# IDCompositionLinearTransferEffect::SetBlueDisable

## Description

Specifies whether to apply the transfer function to the blue channel.

## Parameters

### `blueDisable` [in]

Type: **BOOL**

A boolean value that specifies whether to apply the transfer function to the blue channel.
If you set this to TRUE the effect does not apply the transfer function to the blue channel. If you set this to FALSE it applies the BlueLinearTransfer function to the blue channel.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDCompositionLinearTransferEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionlineartransfereffect)