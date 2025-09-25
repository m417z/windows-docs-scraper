# LPD3DHAL_CONTEXTDESTROYCB callback function

## Description

The **D3dContextDestroy** function deletes the specified context.

## Parameters

### `unnamedParam1`

*pcdd* [in]

Points to a [D3DHAL_CONTEXTDESTROYDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_contextdestroydata) structure that contains the information required for the driver to destroy the context.

## Return value

**D3dContextDestroy** returns one of the following callback codes:

## Remarks

All Microsoft Direct3D drivers must support **D3dContextDestroy**.

The driver should free all resources it allocated to the context that is being deleted. For example, the driver should free the following resources it associated with the context:

* Texture resources
* Vertex and pixel [shaders](https://learn.microsoft.com/windows-hardware/drivers/display/direct3d-shaders)
* [Declarations and code for vertex shaders](https://learn.microsoft.com/windows-hardware/drivers/display/separating-declarations-and-code-for-vertex-shaders)
* Resources for [asynchronous queries](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-asynchronous-query-operations)

The driver should not free the Microsoft DirectDraw surfaces associated with the context because these will be freed by DirectDraw in response to an application or Direct3D runtime request.

If the driver cached the pointer to the [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that was passed in as the **lpDDLcl** member of the [D3DHAL_CONTEXTCREATEDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_contextcreatedata) structure when [D3dContextCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_contextcreatecb) was called, the pointer might become invalid before **D3dContextDestroy** is called. Therefore, **D3dContextDestroy** must not dereference this DD_DIRECTDRAW_LOCAL pointer because an access violation might result or random data might be returned. For example, if the driver's [D3dDestroyDDLocal](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_destroyddlocal) function is called before **D3dContextDestroy**, the operating system releases this DD_DIRECTDRAW_LOCAL pointer before the **D3dContextDestroy** call.

**D3dContextDestroy** can be called with a disabled [PDEV](https://learn.microsoft.com/windows-hardware/drivers/). A PDEV is disabled or enabled by calling the display driver's [DrvAssertMode](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvassertmode) function. See [Managing PDEVs](https://learn.microsoft.com/windows-hardware/drivers/display/managing-pdevs) for more information.

## See also

[D3DHAL_CONTEXTCREATEDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_contextcreatedata)

[D3DHAL_CONTEXTDESTROYDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_contextdestroydata)

[D3dContextCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_contextcreatecb)

[D3dDestroyDDLocal](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_destroyddlocal)

[DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_directdraw_local)