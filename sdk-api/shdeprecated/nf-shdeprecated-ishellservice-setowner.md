# IShellService::SetOwner

## Description

Deprecated. Declares an owner reference to the service object.

## Parameters

### `punkOwner`

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

The address of an interface pointer to the owner object. If **NULL**, the object should call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) to release the existing reference.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The client calls [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) for [IShellService](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nn-shdeprecated-ishellservice), then calls **SetOwner(this)** to declare ownership. When the client is dismissed, typically when the window is closed, it calls **SetOwner(NULL)** to instruct the service object to release the reference to the owner object.