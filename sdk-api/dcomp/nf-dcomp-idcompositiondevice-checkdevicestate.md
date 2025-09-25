# IDCompositionDevice::CheckDeviceState

## Description

Determines whether the DirectComposition device object is still valid.

## Parameters

### `pfValid` [out]

TRUE if the DirectComposition device object is still valid; otherwise FALSE.

## Return value

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

 If the Microsoft DirectX Graphics Infrastructure (DXGI) device is lost, the DirectComposition device associated with the DXGI device is also lost. When it detects a lost device, DirectComposition sends the [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) message to all windows that are composing DirectComposition content using the lost device. An application should call **CheckDeviceState** in response to each **WM_PAINT** message to ensure that the DirectComposition device object is still valid. The application must take steps to recover content if the device object becomes invalid. Steps include creating new DXGI and DirectComposition devices, and recreating all content. (It’s not possible to create just a new DXGI device and associate it with the existing DirectComposition device.) The system ensures that the device object remains valid between **WM_PAINT** messages.

## See also

[IDCompositionDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice)