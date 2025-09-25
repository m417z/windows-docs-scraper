## Description

Trims the graphics memory allocated by the [IDXGIDevice3](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nn-dxgi1_3-idxgidevice3) DXGI device on the app's behalf.

For apps that render with DirectX, graphics drivers periodically allocate internal memory buffers in order to speed up subsequent rendering requests. These memory allocations count against the app's memory usage for PLM and in general lead to increased memory usage by the overall system.

Starting in Windows 8.1, apps that render with Direct2D and/or Direct3D (including [CoreWindow](https://learn.microsoft.com/uwp/api/Windows.UI.Core.CoreWindow) and XAML interop) must call **Trim** in response to the PLM suspend callback. The Direct3D runtime and the graphics driver will discard internal memory buffers allocated for the app, reducing its memory footprint.

Calling this method does not change the rendering state of the graphics device and it has no effect on rendering operations. There is a brief performance hit when internal buffers are reallocated during the first rendering operations after the **Trim** call, therefore apps should only call **Trim** when going idle for a period of time (in response to PLM suspend, for example).

Apps should ensure that they call **Trim** as one of the last D3D operations done before going idle. Direct3D will normally defer the destruction of D3D objects. Calling **Trim**, however, forces Direct3D to destroy objects immediately. For this reason, it is not guaranteed that releasing the final reference on Direct3D objects after calling **Trim** will cause the object to be destroyed and memory to be deallocated before the app suspends.

Similar to [ID3D11DeviceContext::Flush](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-flush), apps should call [ID3D11DeviceContext::ClearState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-clearstate) before calling **Trim**. **ClearState** clears the Direct3D pipeline bindings, ensuring that Direct3D does not hold any references to the Direct3D objects you are trying to release.

It is also prudent to release references on middleware before calling **Trim**, as that middleware may also need to release references
to Direct3D objects.

## See also

[IDXGIDevice3](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nn-dxgi1_3-idxgidevice3)