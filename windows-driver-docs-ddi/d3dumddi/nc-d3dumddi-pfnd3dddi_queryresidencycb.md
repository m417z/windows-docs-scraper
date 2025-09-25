# PFND3DDDI_QUERYRESIDENCYCB callback function

## Description

The **pfnQueryResidencyCb** function queries the residency status of a resource or list of allocations.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDICB_QUERYRESIDENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_queryresidency) structure that describes the residency status of a resource or list of allocations.

## Return value

**pfnQueryResidencyCb** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The residency status was successfully returned.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|

This function might also return other HRESULT values.

## Remarks

The user-mode display driver can call the **pfnQueryResidencyCb** function to query the residency status of allocations either through a resource or through a list of allocations. If the driver queries the residency status of allocations through a resource, all of the allocations that belong to the resource are queried. Typically, the user-mode display driver queries the residency of a resource or list of allocations after the Microsoft Direct3D runtime calls the user-mode display driver's [QueryResourceResidency](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryresourceresidency) or [QueryResourceResidencyDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function to determine the residency of a resource. However, the user-mode display driver can query the residency of a resource or list of allocations at any time.

#### Examples

The following code example shows how to query for residency status.

```cpp
HRESULT
CD3DContext::QueryResourceResidency(CONST D3DDDIARG_QUERYRESOURCERESIDENCY* pQRR)
{
    D3DDDICB_QUERYRESIDENCY queryRes;
    D3DDDI_RESIDENCYSTATUS  resStatus = (D3DDDI_RESIDENCYSTATUS)0;
    HRESULT hr;
    BOOL    bPartInSharedMem = FALSE;

    for (UINT i = 0; i < pQRR->NumResources; i++) {
        memset(&queryRes, 0, sizeof(queryRes));
        queryRes.hResource = m_RTbl[(DWORD)(DWORD_PTR)pQRR->pHandleList[i]].m_hResRuntime;
        if (! queryRes.hResource) {
            return (DDERR_INVALIDPARAMS);
        }
        queryRes.pResidencyStatus = &resStatus;
        hr = m_d3dCallbacks.pfnQueryResidencyCb(m_hD3D, &queryRes);
        if (FAILED(hr)) {
            return (hr);
        }
        switch (resStatus) {
        case D3DDDI_RESIDENCYSTATUS_NOTRESIDENT:
            return S_NOT_RESIDENT;
        case D3DDDI_RESIDENCYSTATUS_RESIDENTINSHAREDMEMORY:
            bPartInSharedMem = TRUE;
            break;
        case D3DDDI_RESIDENCYSTATUS_RESIDENTINGPUMEMORY:
            break;
        default:
            return DDERR_GENERIC;
        }
    }
    if (bPartInSharedMem) {
        return S_RESIDENT_IN_SHARED_MEMORY;
    }
    else {
        return  S_OK;
    }
}
```

## See also

[D3DDDICB_QUERYRESIDENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_queryresidency)

[D3DDDI_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks)

[QueryResourceResidency](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryresourceresidency)

[QueryResourceResidencyDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)