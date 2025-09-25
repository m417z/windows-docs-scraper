# ID3D11DeviceContext2::IsAnnotationEnabled

## Description

Allows apps to determine when either a capture or profiling request is enabled.

## Return value

Returns **TRUE** if capture or profiling is enabled and **FALSE** otherwise.

## Remarks

Returns **TRUE** if the capture tool is present and capturing or the app is being profiled such that [SetMarkerInt](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nf-d3d11_2-id3d11devicecontext2-setmarkerint) or [BeginEventInt](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nf-d3d11_2-id3d11devicecontext2-begineventint) will be logged to [ETW](https://learn.microsoft.com/previous-versions/dotnet/netframework-3.0/ms751538(v=vs.85)). Otherwise, it returns **FALSE**. Apps can use this to turn off self-throttling mechanisms in order to accurately capture what is currently being seen as app output. Apps can also avoid generating event markers and the associated overhead it may entail when there is no benefit to do so.

If apps detect that capture is being performed, they can prevent the Direct3D debugging tools, such as Microsoft Visual Studio 2013, from capturing them. The purpose of the [D3D11_CREATE_DEVICE_PREVENT_ALTERING_LAYER_SETTINGS_FROM_REGISTRY](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_create_device_flag) flag prior to Windows 8.1 was to allow the Direct3D runtime to prevent debugging tools from capturing apps.

## See also

[ID3D11DeviceContext2](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nn-d3d11_2-id3d11devicecontext2)