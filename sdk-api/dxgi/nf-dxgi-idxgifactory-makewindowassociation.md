## Description

Allows DXGI to monitor an application's message queue for the alt-enter key sequence (which causes the application to switch from windowed to full screen or vice versa).

## Parameters

### `WindowHandle`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The handle of the window that is to be monitored. This parameter can be **NULL**; but only if *Flags* is also 0.

### `Flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

One or more of the following values.

* DXGI_MWA_NO_WINDOW_CHANGES - Prevent DXGI from monitoring an applications message queue; this makes DXGI unable to respond to mode changes.
* DXGI_MWA_NO_ALT_ENTER - Prevent DXGI from responding to an alt-enter sequence.
* DXGI_MWA_NO_PRINT_SCREEN - Prevent DXGI from responding to a print-screen key.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

[DXGI_ERROR_INVALID_CALL](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) if *WindowHandle* is invalid, or E_OUTOFMEMORY.

## Remarks

**Note** If you call this API in a Session 0 process, it returns [DXGI_ERROR_NOT_CURRENTLY_AVAILABLE](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

The combination of *WindowHandle* and *Flags* informs DXGI to stop monitoring window messages for the previously-associated window.

If the application switches to full-screen mode, DXGI will choose a full-screen resolution to be the smallest supported resolution that is larger or the same size as the current back buffer size.

Applications can make some changes to make the transition from windowed to full screen more efficient. For example, on a WM_SIZE message, the application should release any outstanding swap-chain back buffers, call [IDXGISwapChain::ResizeBuffers](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-resizebuffers), then re-acquire the back buffers from the swap chain(s). This gives the swap chain(s) an opportunity to resize the back buffers, and/or recreate them to enable full-screen flipping operation. If the application does not perform this sequence, DXGI will still make the full-screen/windowed transition, but may be forced to use a stretch operation (since the back buffers may not be the correct size), which may be less efficient. Even if a stretch is not required, presentation may not be optimal because the back buffers might not be directly interchangeable with the front buffer. Thus, a call to **ResizeBuffers** on WM_SIZE is always recommended, since WM_SIZE is always sent during a fullscreen transition.

While windowed, the application can, if it chooses, restrict the size of its window's client area to sizes to which it is comfortable rendering. A fully flexible application would make no such restriction, but UI elements or other design considerations can, of course, make this flexibility untenable. If the application further chooses to restrict its window's client area to just those that match supported full-screen resolutions, the application can field WM_SIZING, then check against [IDXGIOutput::FindClosestMatchingMode](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgioutput-findclosestmatchingmode). If a matching mode is found, allow the resize. (The IDXGIOutput can be retrieved from [IDXGISwapChain::GetContainingOutput](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-getcontainingoutput). Absent subsequent changes to desktop topology, this will be the same output that will be chosen when alt-enter is fielded and fullscreen mode is begun for that swap chain.)

Applications that want to handle mode changes or Alt+Enter themselves should call **MakeWindowAssociation** with the DXGI_MWA_NO_WINDOW_CHANGES flag after swap chain creation. The *WindowHandle* argument, if non-**NULL**, specifies that the application message queues will not be handled by the DXGI runtime for all swap chains of a particular target [HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types). Calling **MakeWindowAssociation** with the DXGI_MWA_NO_WINDOW_CHANGES flag after swapchain creation ensures that DXGI will not interfere with application's handling of window mode changes or Alt+Enter.

You must call the **MakeWindowAssociation** method on the factory object associated with the target HWND swap chain(s). You can guarantee that by calling the [IDXGIObject::GetParent](https://learn.microsoft.com/windows/win32/api/dxgi/nf-dxgi-idxgiobject-getparent) method on the swap chain(s) to locate the factory. Here's a code example of doing that.

```cppwinrt
void MakeWindowAssociationWithLocatedFactory(
    winrt::com_ptr<IDXGISwapChain> const& swapChain,
    HWND hWnd,
    UINT flags)
{
    winrt::com_ptr<IDXGIFactory1> factory;
    factory.capture(swapChain, &IDXGISwapChain::GetParent);
    factory->MakeWindowAssociation(hWnd, flags);
}
```

### Notes for Windows Store apps

If a Windows Store app calls **MakeWindowAssociation**, it fails with [DXGI_ERROR_NOT_CURRENTLY_AVAILABLE](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

A Microsoft Win32 application can use **MakeWindowAssociation** to control full-screen transitions through the Alt+Enter key combination and print screen behavior for full screen. For Windows Store apps, because DXGI can't perform full-screen transitions, a Windows Store app has no way to control full-screen transitions.

## See also

[DXGI interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGIFactory](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory)