# ID3D11Device1::CreateDeviceContextState

## Description

Creates a context state object that holds all Microsoft Direct3D state and some Direct3D behavior.

## Parameters

### `Flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of
[D3D11_1_CREATE_DEVICE_CONTEXT_STATE_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ne-d3d11_1-d3d11_1_create_device_context_state_flag)
values that are combined by using a bitwise **OR** operation.
The resulting value specifies how to create the context state object.
The
[D3D11_1_CREATE_DEVICE_CONTEXT_STATE_SINGLETHREADED](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ne-d3d11_1-d3d11_1_create_device_context_state_flag) flag is currently the only defined flag.
If the original device was created with
[D3D11_CREATE_DEVICE_SINGLETHREADED](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_create_device_flag),
you must create all context state objects from that device with the
**D3D11_1_CREATE_DEVICE_CONTEXT_STATE_SINGLETHREADED** flag.

If you set the single-threaded flag for both the context state object and the device, you guarantee that you will call the whole set of context methods and device methods only from one thread.
You therefore do not need to use critical sections to synchronize access to the device context, and the runtime can avoid working with those processor-intensive critical sections.

### `pFeatureLevels` [in]

Type: **const [D3D_FEATURE_LEVEL](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level)***

A pointer to an array of [D3D_FEATURE_LEVEL](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level) values. The array can contain elements from the following list and determines the order of feature levels for which creation is attempted.
Unlike [D3D11CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-d3d11createdevice), you can't set *pFeatureLevels* to **NULL** because there is no default feature level array.

```
{
    D3D_FEATURE_LEVEL_11_1,
    D3D_FEATURE_LEVEL_11_0,
    D3D_FEATURE_LEVEL_10_1,
    D3D_FEATURE_LEVEL_10_0,
    D3D_FEATURE_LEVEL_9_3,
    D3D_FEATURE_LEVEL_9_2,
    D3D_FEATURE_LEVEL_9_1,
};

```

### `FeatureLevels`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of elements in *pFeatureLevels*. Unlike [D3D11CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-d3d11createdevice), you must set *FeatureLevels* to greater than 0 because you can't set *pFeatureLevels* to **NULL**.

### `SDKVersion`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The SDK version. You must set this parameter to **D3D11_SDK_VERSION**.

### `EmulatedInterface`

Type: **REFIID**

The globally unique identifier (GUID) for the emulated interface. This value specifies the behavior of the device when the context state object is active. Valid values are obtained by using the **__uuidof** operator on the [ID3D10Device](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device), [ID3D10Device1](https://learn.microsoft.com/windows/desktop/api/d3d10_1/nn-d3d10_1-id3d10device1), [ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device), and [ID3D11Device1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11device1) interfaces. See Remarks.

### `pChosenFeatureLevel` [out, optional]

Type: **[D3D_FEATURE_LEVEL](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level)***

A pointer to a variable that receives a [D3D_FEATURE_LEVEL](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level) value from the *pFeatureLevels* array. This is the first array value with which **CreateDeviceContextState** succeeded in creating the context state object. If the call to **CreateDeviceContextState** fails, the variable pointed to by *pChosenFeatureLevel* is set to zero.

### `ppContextState` [out, optional]

Type: **[ID3DDeviceContextState](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3ddevicecontextstate)****

The address of a pointer to an [ID3DDeviceContextState](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3ddevicecontextstate) object that represents the state of a Direct3D device.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

The **REFIID** value of the emulated interface is a GUID obtained by use of the **__uuidof** operator. For example, `__uuidof(ID3D11Device)` gets the GUID of the interface to a Microsoft Direct3D 11 device.

Call the [ID3D11DeviceContext1::SwapDeviceContextState](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-swapdevicecontextstate) method to activate the context state object. When the context state object is active, the device behaviors that are associated with both the context state object's feature level and its compatible interface are activated on the Direct3D device until the next call to **SwapDeviceContextState**.

When a context state object is active, the runtime disables certain methods on the device and context interfaces. For example, a context state object that is created with `__uuidof(ID3D11Device)` will cause the runtime to turn off most of the Microsoft Direct3D 10 device interfaces, and a context state object that is created with `__uuidof(ID3D10Device1)` or `__uuidof(ID3D10Device)` will cause the runtime to turn off most of the [ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext) methods.
This behavior ensures that a user of either emulated interface cannot set device state that the other emulated interface is unable to express. This restriction helps guarantee that the [ID3D10Device1](https://learn.microsoft.com/windows/desktop/api/d3d10_1/nn-d3d10_1-id3d10device1) emulated interface accurately reflects the full state of the pipeline and that the emulated interface will not operate contrary to its original interface definition.

For example, suppose the tessellation stage is made active through the [ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext) interface
when you create the device through [D3D11CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-d3d11createdevice) or [D3D11CreateDeviceAndSwapChain](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-d3d11createdeviceandswapchain), instead of through the Direct3D 10 equivalents. Because the Direct3D 11 context is active, a Direct3D 10 interface is inactive when you first retrieve it via [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)). This means that you cannot immediately pass a Direct3D 10 interface that you retrieved from a Direct3D 11 device to a function. You must first call [SwapDeviceContextState](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-swapdevicecontextstate) to activate a Direct3D 10-compatible context state object.

The following table shows the methods that are active and inactive for each emulated interface.

| Emulated interface | Active device or immediate context interfaces | Inactive device or immediate context interfaces |
| --- | --- | --- |
| [ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device) or<br><br>[ID3D11Device1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11device1) | [ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)<br><br>[IDXGIDevice](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice) +<br><br>[IDXGIDevice1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice1) +<br><br>[IDXGIDevice2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgidevice2)<br><br>[ID3D10Multithread](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10multithread) | [ID3D10Device](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device) |
| [ID3D10Device1](https://learn.microsoft.com/windows/desktop/api/d3d10_1/nn-d3d10_1-id3d10device1) or<br><br>[ID3D10Device](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device) | [ID3D10Device](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)<br><br>[ID3D10Device1](https://learn.microsoft.com/windows/desktop/api/d3d10_1/nn-d3d10_1-id3d10device1)<br><br>[IDXGIDevice](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice) +<br><br>[IDXGIDevice1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice1)<br><br>[ID3D10Multithread](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10multithread) | [ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)<br><br>[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext) (As published by the immediate context. The Direct3D 10 or Microsoft Direct3D 10.1 emulated interface has no effect on deferred contexts.) |

The following table shows the immediate context methods that the runtime disables when the indicated context state objects are active.

| Methods of [ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext) when `__uuidof(ID3D10Device1)` or `__uuidof(ID3D10Device)` is active | Methods of [ID3D10Device](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device) when `__uuidof(ID3D11Device)` is active |
| --- | --- |
| [ClearDepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-cleardepthstencilview) | [ClearDepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-cleardepthstencilview) |
| [ClearRenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-clearrendertargetview) | [ClearRenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-clearrendertargetview) |
| [ClearState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-clearstate) | [ClearState](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-clearstate) |
| [ClearUnorderedAccessViewUint](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-clearunorderedaccessviewuint) |  |
| [ClearUnorderedAccessViewFloat](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-clearunorderedaccessviewfloat) |  |
| [CopyResource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-copyresource) | [CopyResource](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-copyresource) |
| [CopyStructureCount](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-copystructurecount) |  |
| [CopySubresourceRegion](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-copysubresourceregion) | [CopySubresourceRegion](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-copysubresourceregion) |
| [CSGetConstantBuffers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-csgetconstantbuffers) |  |
| [CSGetSamplers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-csgetsamplers) |  |
| [CSGetShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-csgetshader) |  |
| [CSGetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-csgetshaderresources) |  |
| [CSGetUnorderedAccessViews](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-csgetunorderedaccessviews) |  |
| [CSSetConstantBuffers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-cssetconstantbuffers) |  |
| [CSSetSamplers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-cssetsamplers) |  |
| [CSSetShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-cssetshader) |  |
| [CSSetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-cssetshaderresources) |  |
| [CSSetUnorderedAccessViews](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-cssetunorderedaccessviews) |  |
| [Dispatch](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-dispatch) |  |
| [DispatchIndirect](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-dispatchindirect) |  |
|  | [CreateBlendState](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-createblendstate) |
| [Draw](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-draw) | [Draw](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-draw) |
| [DrawAuto](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-drawauto) | [DrawAuto](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-drawauto) |
| [DrawIndexed](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-drawindexed) | [DrawIndexed](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-drawindexed) |
| [DrawIndexedInstanced](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-drawindexedinstanced) | [DrawIndexedInstanced](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-drawindexedinstanced) |
| [DrawIndexedInstancedIndirect](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-drawindexedinstancedindirect) |  |
| [DrawInstanced](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-drawinstanced) | [DrawInstanced](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-drawinstanced) |
| [DrawInstancedIndirect](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-drawinstancedindirect) |  |
| [DSGetConstantBuffers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-dsgetconstantbuffers) |  |
| [DSGetSamplers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-dsgetsamplers) |  |
| [DSGetShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-dsgetshader) |  |
| [DSGetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-dsgetshaderresources) |  |
| [DSSetConstantBuffers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-dssetconstantbuffers) |  |
| [DSSetSamplers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-dssetsamplers) |  |
| [DSSetShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-dssetshader) |  |
| [DSSetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-dssetshaderresources) |  |
| [ExecuteCommandList](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-executecommandlist) |  |
| [FinishCommandList](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-finishcommandlist) |  |
| [Flush](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-flush) | [Flush](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-flush) |
| [GenerateMips](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-generatemips) | [GenerateMips](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-generatemips) |
| [GetPredication](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getpredication) | [GetPredication](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-getpredication) |
| [GetResourceMinLOD](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getresourceminlod) |  |
| [GetType](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-gettype) |  |
|  | [GetTextFilterSize](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-gettextfiltersize) |
| [GSGetConstantBuffers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-gsgetconstantbuffers) | [GSGetConstantBuffers](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-gsgetconstantbuffers) |
| [GSGetSamplers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-gsgetsamplers) | [GSGetSamplers](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-gsgetsamplers) |
| [GSGetShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-gsgetshader) | [GSGetShader](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-gsgetshader) |
| [GSGetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-gsgetshaderresources) | [GSGetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-gsgetshaderresources) |
| [GSSetConstantBuffers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-gssetconstantbuffers) | [GSSetConstantBuffers](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-gssetconstantbuffers) |
| [GSSetSamplers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-gssetsamplers) | [GSSetSamplers](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-gssetsamplers) |
| [GSSetShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-gssetshader) | [GSSetShader](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-gssetshader) |
| [GSSetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-gssetshaderresources) | [GSSetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-gssetshaderresources) |
| [HSGetConstantBuffers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-hsgetconstantbuffers) |  |
| [HSGetSamplers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-hsgetsamplers) |  |
| [HSGetShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-hsgetshader) |  |
| [HSGetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-hsgetshaderresources) |  |
| [HSSetConstantBuffers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-hssetconstantbuffers) |  |
| [HSSetSamplers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-hssetsamplers) |  |
| [HSSetShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-hssetshader) |  |
| [HSSetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-hssetshaderresources) |  |
| [IAGetIndexBuffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-iagetindexbuffer) | [IAGetIndexBuffer](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-iagetindexbuffer) |
| [IAGetInputLayout](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-iagetinputlayout) | [IAGetInputLayout](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-iagetinputlayout) |
| [IAGetPrimitiveTopology](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-iagetprimitivetopology) | [IAGetPrimitiveTopology](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-iagetprimitivetopology) |
| [IAGetVertexBuffers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-iagetvertexbuffers) | [IAGetVertexBuffers](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-iagetvertexbuffers) |
| [IASetIndexBuffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-iasetindexbuffer) | [IASetIndexBuffer](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-iasetindexbuffer) |
| [IASetInputLayout](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-iasetinputlayout) | [IASetInputLayout](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-iasetinputlayout) |
| [IASetPrimitiveTopology](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-iasetprimitivetopology) | [IASetPrimitiveTopology](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-iasetprimitivetopology) |
| [IASetVertexBuffers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-iasetvertexbuffers) | [IASetVertexBuffers](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-iasetvertexbuffers) |
| [OMGetBlendState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-omgetblendstate) | [OMGetBlendState](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-omgetblendstate) |
| [OMGetDepthStencilState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-omgetdepthstencilstate) | [OMGetDepthStencilState](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-omgetdepthstencilstate) |
| [OMGetRenderTargets](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-omgetrendertargets) | [OMGetRenderTargets](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-omgetrendertargets) |
| [OMGetRenderTargetsAndUnorderedAccessViews](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-omgetrendertargetsandunorderedaccessviews) |  |
| [OMSetBlendState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-omsetblendstate) | [OMSetBlendState](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-omsetblendstate) |
| [OMSetDepthStencilState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-omsetdepthstencilstate) | [OMSetDepthStencilState](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-omsetdepthstencilstate) |
| [OMSetRenderTargets](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-omsetrendertargets) | [OMSetRenderTargets](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-omsetrendertargets) |
| [OMSetRenderTargetsAndUnorderedAccessViews](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-omsetrendertargetsandunorderedaccessviews) |  |
| [PSGetConstantBuffers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-psgetconstantbuffers) | [PSGetConstantBuffers](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-psgetconstantbuffers) |
| [PSGetSamplers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-psgetsamplers) | [PSGetSamplers](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-psgetsamplers) |
| [PSGetShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-psgetshader) | [PSGetShader](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-psgetshader) |
| [PSGetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-psgetshaderresources) | [PSGetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-psgetshaderresources) |
| [PSSetConstantBuffers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-pssetconstantbuffers) | [PSSetConstantBuffers](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-pssetconstantbuffers) |
| [PSSetSamplers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-pssetsamplers) | [PSSetSamplers](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-pssetsamplers) |
| [PSSetShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-pssetshader) | [PSSetShader](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-pssetshader) |
| [PSSetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-pssetshaderresources) | [PSSetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-pssetshaderresources) |
| [ResolveSubresource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-resolvesubresource) | [ResolveSubresource](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-resolvesubresource) |
| [RSGetScissorRects](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-rsgetscissorrects) | [RSGetScissorRects](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-rsgetscissorrects) |
| [RSGetState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-rsgetstate) | [RSGetState](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-rsgetstate) |
| [RSGetViewports](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-rsgetviewports) | [RSGetViewports](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-rsgetviewports) |
| [RSSetScissorRects](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-rssetscissorrects) | [RSSetScissorRects](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-rssetscissorrects) |
| [RSSetState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-rssetstate) | [RSSetState](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-rssetstate) |
| [RSSetViewports](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-rssetviewports) | [RSSetViewports](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-rssetviewports) |
| [SetPredication](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-setpredication) | [SetPredication](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-setpredication) |
| [SetResourceMinLOD](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-setresourceminlod) |  |
|  | [SetTextFilterSize](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-settextfiltersize) |
| [SOGetTargets](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-sogettargets) | [SOGetTargets](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-sogettargets) |
| [SOSetTargets](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-sosettargets) | [SOSetTargets](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-sosettargets) |
| [UpdateSubresource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-updatesubresource) | [UpdateSubresource](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-updatesubresource) |
| [VSGetConstantBuffers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-vsgetconstantbuffers) | [VSGetConstantBuffers](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-vsgetconstantbuffers) |
| [VSGetSamplers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-vsgetsamplers) | [VSGetSamplers](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-vsgetsamplers) |
| [VSGetShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-vsgetshader) | [VSGetShader](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-vsgetshader) |
| [VSGetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-vsgetshaderresources) | [VSGetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-vsgetshaderresources) |
| [VSSetConstantBuffers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-vssetconstantbuffers) | [VSSetConstantBuffers](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-vssetconstantbuffers) |
| [VSSetSamplers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-vssetsamplers) | [VSSetSamplers](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-vssetsamplers) |
| [VSSetShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-vssetshader) | [VSSetShader](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-vssetshader) |
| [VSSetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-vssetshaderresources) | [VSSetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-vssetshaderresources) |

The following table shows the immediate context methods that the runtime does not disable when the indicated context state objects are active.

| Methods of [ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext) when `__uuidof(ID3D10Device1)` or `__uuidof(ID3D10Device)` is active | Methods of [ID3D10Device](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device) when `__uuidof(ID3D11Device)` is active |
| --- | --- |
| [Begin](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-begin) |  |
| [End](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-end) |  |
|  | [GetCreationFlags](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-getcreationflags) |
|  | [GetPrivateData](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-getprivatedata) |
| [GetContextFlags](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getcontextflags) |  |
| [GetData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getdata) |  |
| [Map](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-map) |  |
| [Unmap](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-unmap) |  |

The following table shows the [ID3D10Device](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device) interface methods that the runtime does not disable because they are not immediate context methods.

| Methods of [ID3D10Device](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device) |
| --- |
| [CheckCounter](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-checkcounter) |
| [CheckCounterInfo](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-checkcounterinfo) |
| Create*, like [CreateQuery](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-createquery) |
| [GetDeviceRemovedReason](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-getdeviceremovedreason) |
| [GetExceptionMode](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-getexceptionmode) |
| [OpenSharedResource](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-opensharedresource) |
| [SetExceptionMode](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-setexceptionmode) |
| [SetPrivateData](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-setprivatedata) |
| [SetPrivateDataInterface](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-setprivatedatainterface) |

**Windows Phone 8:** This API is supported.

## See also

[ID3D11Device1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11device1)