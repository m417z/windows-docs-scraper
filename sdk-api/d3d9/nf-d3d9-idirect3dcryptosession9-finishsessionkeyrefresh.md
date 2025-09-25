# IDirect3DCryptoSession9::FinishSessionKeyRefresh

## Description

Switches to a new session key.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Before calling this method, call the [IDirect3DCryptoSession9::StartSessionKeyRefresh](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcryptosession9-startsessionkeyrefresh) method. The **StartSessionKeyRefresh** method gets a random number from the driver, which is used to create a new session key. The new session key does not become active until the application calls **FinishSessionKeyRefresh**. After the application calls **FinishSessionKeyRefresh**, all protected surfaces are encrypted using the new session key.

## See also

[GPU-Based Content Protection](https://learn.microsoft.com/windows/desktop/medfound/gpu-based-content-protection)

[IDirect3DCryptoSession9](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3dcryptosession9)