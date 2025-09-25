# IDirect3DDevice9Ex::CheckResourceResidency

## Description

Checks an array of resources to determine if it is likely that they will cause a large stall at Draw time because the system must make the resources GPU-accessible.

## Parameters

### `pResourceArray` [in]

Type: **[IDirect3DResource9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dresource9)****

An array of [IDirect3DResource9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dresource9) pointers that indicate the resources to check.

### `NumResources` [in]

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value indicating the number of resources passed into the *pResourceArray* parameter up to a maximum of 65535.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If all the resources are in GPU-accessible memory, the method will return S_OK. The system may need to perform a remapping operation to promote the resources, but will not have to copy data.

 If no allocation that comprises the resources is on disk, but at least one allocation is not in GPU-accessible memory, the method will return S_RESIDENT_IN_SHARED_MEMORY. The system may need to perform a copy to promote the resource.

 If at least one allocation that comprises the resources is on disk, this method will return S_NOT_RESIDENT. The system may need to perform a copy to promote the resource.

## Remarks

This API is no more than a reasonable guess at residency, since resources may have been demoted by the time the application uses them.

The expected usage pattern is as follows. If the application determines that a set of resources are not resident, then the application will substitute a lower-LOD version of the resource and continue with rendering. The video memory manager API, offers a feature to allow the application to express that it would like these lower-LOD resources to be made more likely to stay resident in GPU-accessible memory. It is the app's responsibility to create, fill and destroy these lower-LOD versions, if it so chooses.

The application also needs to begin promotion of the higher-LOD versions when the residency check indicates that the resource is not resident in GPU-accessible memory. Since a per-process lock exists in kernel mode, a performant implementation will spawn a separate process whose sole job is to promote resources. The application communicates resource identity between the two process by means of the [Sharing Resources](https://learn.microsoft.com/windows/desktop/direct3d9/dx9lh) shared surfaces API and promotes them by means of the [SetPriority](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dresource9-setpriority).

## See also

[IDirect3DDevice9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3ddevice9ex)