# ID3D11DeviceContext::SetPredication

## Description

Set a rendering predicate.

## Parameters

### `pPredicate` [in, optional]

Type: **[ID3D11Predicate](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11predicate)***

A pointer to the [ID3D11Predicate](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11predicate) interface that represents the rendering predicate. A **NULL** value indicates "no" predication; in this case, the value of *PredicateValue* is irrelevant but will be preserved for [ID3D11DeviceContext::GetPredication](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getpredication).

### `PredicateValue` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If **TRUE**, rendering will be affected by when the predicate's conditions are met. If **FALSE**, rendering will be affected when the conditions are not met.

## Remarks

The predicate must be in the "issued" or "signaled" state to be used for predication. While the predicate is set for predication, calls to [ID3D11DeviceContext::Begin](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-begin) and [ID3D11DeviceContext::End](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-end) are invalid.

Use this method to denote that subsequent rendering and resource manipulation commands are not actually performed if the resulting predicate data of the predicate is equal to the *PredicateValue*. However, some predicates are only hints, so they may not actually prevent operations from being performed.

The primary usefulness of predication is to allow an application to issue rendering and resource manipulation commands without taking the performance hit of spinning, waiting for [ID3D11DeviceContext::GetData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getdata) to return. So, predication can occur while **ID3D11DeviceContext::GetData** returns **S_FALSE**. Another way to think of it: an application can also use predication as a fallback, if it is possible that **ID3D11DeviceContext::GetData** returns **S_FALSE**. If **ID3D11DeviceContext::GetData** returns **S_OK**, the application can skip calling the rendering and resource manipulation commands manually with its own application logic.

Rendering and resource manipulation commands for Direct3D 11 include these Draw, Dispatch, Copy, Update, Clear, Generate, and Resolve operations.

* [Draw](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-draw)
* [DrawAuto](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-drawauto)
* [DrawIndexed](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-drawindexed)
* [DrawIndexedInstanced](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-drawindexedinstanced)
* [DrawIndexedInstancedIndirect](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-drawindexedinstancedindirect)
* [DrawInstanced](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-drawinstanced)
* [DrawInstancedIndirect](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-drawinstancedindirect)
* [Dispatch](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-dispatch)
* [DispatchIndirect](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-dispatchindirect)
* [CopyResource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-copyresource)
* [CopyStructureCount](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-copystructurecount)
* [CopySubresourceRegion](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-copysubresourceregion)
* [CopySubresourceRegion1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-copysubresourceregion1)
* [CopyTiles](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nf-d3d11_2-id3d11devicecontext2-copytiles)
* [CopyTileMappings](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nf-d3d11_2-id3d11devicecontext2-copytilemappings)
* [UpdateSubresource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-updatesubresource)
* [UpdateSubresource1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-updatesubresource1)
* [UpdateTiles](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nf-d3d11_2-id3d11devicecontext2-updatetiles)
* [UpdateTileMappings](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nf-d3d11_2-id3d11devicecontext2-updatetilemappings)
* [ClearRenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-clearrendertargetview)
* [ClearUnorderedAccessViewFloat](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-clearunorderedaccessviewfloat)
* [ClearUnorderedAccessViewUint](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-clearunorderedaccessviewuint)
* [ClearView](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-clearview)
* [ClearDepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-cleardepthstencilview)
* [GenerateMips](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-generatemips)
* [ResolveSubresource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-resolvesubresource)

You can set a rendering predicate on an immediate or a deferred context. For info about immediate and deferred contexts, see [Immediate and Deferred Rendering](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-render-multi-thread-render).

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)