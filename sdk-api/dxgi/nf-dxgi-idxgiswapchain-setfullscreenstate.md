## Description

Sets the display state to windowed or full screen.

## Parameters

### `Fullscreen`

Type: **[BOOL](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

A Boolean value that specifies whether to set the display state to windowed or full screen. **TRUE** for full screen, and **FALSE** for windowed.

### `pTarget`

Type: [in, optional] **[IDXGIOutput](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgioutput)***

If you pass **TRUE** to the *Fullscreen* parameter to set the display state to full screen, you can optionally set this parameter to a pointer to an [IDXGIOutput](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgioutput) interface for the output target that contains the swap chain. If you set this parameter to **NULL**, DXGI will choose the output based on the swap-chain's device and the output window's placement. If you pass **FALSE** to *Fullscreen*, then you must set this parameter to **NULL**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of these values.

- **S_OK** if the action succeeded and the swap chain was placed in the requested state.
- **DXGI_ERROR_NOT_CURRENTLY_AVAILABLE** if the action failed. When this error is returned, your application can continue to run in windowed mode and try to switch to full-screen mode later. There are many reasons why a windowed-mode swap chain cannot switch to full-screen mode. Here are some examples.
  - The application is running over Terminal Server.
  - The output window is occluded.
  - The output window does not have keyboard focus.
  - Another application is already in full-screen mode.
- **DXGI_STATUS_MODE_CHANGE_IN_PROGRESS** is returned if a fullscreen/windowed mode transition is occurring when this API is called.
- Other error codes if you run out of memory or encounter another unexpected fault; these codes may be treated as hard, non-continuable errors.

## Remarks

DXGI may change the display state of a swap chain in response to end user or system requests.

We recommend that you create a windowed swap chain and allow the end user to change the swap chain to full screen through **SetFullscreenState**; that is, do not set the **Windowed** member of [DXGI_SWAP_CHAIN_DESC](https://learn.microsoft.com/windows/win32/api/dxgi/ns-dxgi-dxgi_swap_chain_desc) to FALSE to force the swap chain to be full screen. However, if you create the swap chain as full screen, also provide the end user with a list of supported display modes because a swap chain that is created with an unsupported display mode might cause the display to go black and prevent the end user from seeing anything. Also, we recommend that you have a time-out confirmation screen or other fallback mechanism when you allow the end user to change display modes.

### Notes for Windows Store apps

If a Windows Store app calls **SetFullscreenState** to set the display state to full screen, **SetFullscreenState** fails with [DXGI_ERROR_NOT_CURRENTLY_AVAILABLE](https://learn.microsoft.com/windows/win32/direct3ddxgi/dxgi-error).

You cannot call **SetFullscreenState** on a swap chain that you created with [IDXGIFactory2::CreateSwapChainForComposition](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcomposition).

For the [flip presentation model](https://learn.microsoft.com/windows/win32/direct3ddxgi/dxgi-flip-model), after you transition the display state to full screen, you must call [ResizeBuffers](https://learn.microsoft.com/windows/win32/api/dxgi/nf-dxgi-idxgiswapchain-resizebuffers) to ensure that your call to [IDXGISwapChain1::Present1](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-present1) succeeds.

## See also

[IDXGISwapChain](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgiswapchain)