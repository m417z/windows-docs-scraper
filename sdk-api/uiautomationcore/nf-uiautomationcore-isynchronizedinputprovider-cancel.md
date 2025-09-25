# ISynchronizedInputProvider::Cancel

## Description

Cancels listening for input.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the provider is currently listening for input, it should revert to normal operation.

## See also

[ISynchronizedInputProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-isynchronizedinputprovider)