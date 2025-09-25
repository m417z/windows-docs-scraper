# IDXGIAdapter2::GetDesc2

## Description

Gets a Microsoft DirectX Graphics Infrastructure (DXGI) 1.2 description of an adapter or video card. This description includes information about the granularity at which the graphics processing unit (GPU) can be preempted from performing its current task.

## Parameters

### `pDesc` [out]

A pointer to a [DXGI_ADAPTER_DESC2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_adapter_desc2) structure that describes the adapter.
This parameter must not be **NULL**. On [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9 graphics hardware, earlier versions of **GetDesc2** ([GetDesc](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiadapter-getdesc) and [GetDesc1](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiadapter1-getdesc1)) return zeros for **VendorId**, **DeviceId**, **SubSysId**, and **Revision** members of the adapter description structure and “Software Adapter” for the description string in the **Description** member. **GetDesc2** returns the actual feature level 9 hardware values in these members.

## Return value

Returns S_OK if successful; otherwise, returns E_INVALIDARG if the *pDesc* parameter is **NULL**.

## Remarks

Use the **GetDesc2** method to get a DXGI 1.2 description of an adapter. To get a DXGI 1.1 description, use the [IDXGIAdapter1::GetDesc1](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiadapter1-getdesc1) method. To get a DXGI 1.0 description, use the [IDXGIAdapter::GetDesc](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiadapter-getdesc) method.

The Windows Display Driver Model (WDDM) scheduler can preempt the GPU's execution of application tasks. The granularity at which the GPU can be preempted from performing its current task in the WDDM 1.1 or earlier driver model is a direct memory access (DMA) buffer for graphics tasks or a compute packet for compute tasks. The GPU can switch between tasks only after it completes the currently executing unit of work, a DMA buffer or a compute packet.

A DMA buffer is the largest independent unit of graphics work that the WDDM scheduler can submit to the GPU. This buffer contains a set of GPU instructions that the WDDM driver and GPU use. A compute packet is the largest independent unit of compute work that the WDDM scheduler can submit to the GPU. A compute packet contains dispatches (for example, calls to the [ID3D11DeviceContext::Dispatch](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-dispatch) method), which contain thread groups. The WDDM 1.2 or later driver model allows the GPU to be preempted at finer granularity levels than a DMA buffer or compute packet. You can use the **GetDesc2** method to retrieve the granularity levels for graphics and compute tasks.

## See also

[IDXGIAdapter2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgiadapter2)