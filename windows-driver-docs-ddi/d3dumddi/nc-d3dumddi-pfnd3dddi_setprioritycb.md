# PFND3DDDI_SETPRIORITYCB callback function

## Description

The *pfnSetPriorityCb* function sets the priority level of a resource or list of allocations.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDICB_SETPRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_setpriority) structure that describes the priority level to set a resource or list of allocations to.

## Return value

*pfnSetPriorityCb* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The priority level was successfully set.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|

This function might also return other HRESULT values.

## Remarks

The user-mode display driver can call the *pfnSetPriorityCb* function to set the priority of the underlying resource or list of allocations. If the priority level of a resource is set, all of the allocations that belong to the resource are set to the specified priority level. Typically, the user-mode display driver sets the priority of a resource or list of allocations after the Microsoft Direct3D runtime calls the user-mode display driver's [SetPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setpriority) or [SetResourcePriorityDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function to set the eviction-from-memory priority for a resource. However, the user-mode display driver can set the priority of allocations at any time.

After an application requests to set the priority level of a surface, the user-mode display driver should set the appropriate resource or list of allocations to the priority level that is specified by the application.

**Note** Priority levels are only a hint to the video memory manager; they can be ignored by the memory manager under various conditions.

An allocation priority defines both the likelihood that the allocation remains resident and the likelihood of how hard the video memory manager will try to respect the driver's preference for the placement of the allocation. The following priority levels are defined in the D3dukmdt.h header file:

The driver can use priority levels other than the preceding defined values when appropriate. For example, marking an allocation with a priority level of 0x78000001 indicates that the allocation is slightly above normal.

#### Examples

The following code example shows how to set priority level.

```cpp
HRESULT CD3DContext::SetPriority(CONST D3DDDIARG_SETPRIORITY* pSetPriority) {
    DWORD  dwSurfaceHandle = (DWORD)(DWORD_PTR)pSetPriority->hResource;
    CResource   &res = m_RTbl[dwSurfaceHandle];
    D3DDDICB_SETPRIORITY    setPri;
    UINT                    priority;

    priority = pSetPriority->Priority;

    memset(&setPri, 0, sizeof(setPri));

    setPri.hResource   = res.m_hResRuntime;
    setPri.pPriorities = &priority;

    return (m_d3dCallbacks.pfnSetPriorityCb(m_hD3D, &setPri));
}
```

## See also

[D3DDDICB_SETPRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_setpriority)

[D3DDDI_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks)

[DxgkCbCreateContextAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createcontextallocation)

[SetPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setpriority)

[SetResourcePriorityDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)