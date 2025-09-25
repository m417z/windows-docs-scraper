# PFND3DDDI_UNLOCKCB callback function

## Description

The **pfnUnlockCb** function unlocks an allocation that was locked by a call to the [pfnLockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb) function.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDICB_UNLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_unlock) structure that describes the allocation to unlock.

## Return value

**pfnUnlockCb** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The allocation was successfully unlocked.|
|E_OUTOFMEMORY|pfnUnlockCb could not complete because of insufficient memory. (This error occurs when the system is in an extreme low memory situation and there is not sufficient space to allocate the array of pages.)|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|

This function might also return other HRESULT values.

## Remarks

The user-mode display driver must call the **pfnUnlockCb** function to unlock an allocation that was previously locked in a call to the [pfnLockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb) function. If the driver does not call **pfnUnlockCb**, coordination between the Microsoft Direct3D runtime, the user-mode display driver, and the display miniport driver is lost.

The user-mode display driver typically calls **pfnUnlockCb** in response to a call to its [Unlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_unlock) or [ResourceUnmap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceunmap) function (or other variations of *ResourceUnmap* such as *DynamicIABufferUnmap*) to unlock a resource or a surface within the resource. Before returning from the *Unlock* or *ResourceUnmap* call, the user-mode display driver must first map the resource or surface to the appropriate allocation and then call **pfnUnlockCb** to unlock the allocation.

The user-mode display driver can also call **pfnUnlockCb** in response to a call to its [DestroyDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroydevice) or [DestroyDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroydevice) function to free all of the resources that it allocated for the device. In the lifetime of a device, every call to [pfnLockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb) to lock an allocation must be paired with a call to the **pfnUnlockCb** function to unlock the allocation.

The user-mode display driver can unlock multiple allocations in one call to **pfnUnlockCb** by setting the **NumAllocations** member of the [D3DDDICB_UNLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_unlock) structure to the number of allocations in the array that is specified by the **phAllocations** member of D3DDDICB_UNLOCK.

The user-mode display driver should call **pfnUnlockCb** to unlock all of the allocations that are referred to in the command stream before calling the [pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb) function. The driver could have allocations locked to support--for example, the **NoOverwrite** bit-field flag. If the driver does not unlock all of these allocations, the video memory manager might be required to place these allocations in AGP memory.

The user-mode display driver should not call **pfnUnlockCb** to unlock an allocation that an application could be using. The driver is notified that the application is no longer reading from or writing to the allocation when the driver receives a call to its [Unlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_unlock) or [ResourceUnmap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceunmap) function on the corresponding resource.

#### Examples

The following code example shows how to unlock an allocation.

```cpp
HRESULT CD3DContext::SyncEnginesUsingLock(VOID) {
    HRESULT hr;
    D3DDDICB_LOCK   lockCB;
    D3DDDICB_UNLOCK Unlock;

    memset(&lockCB, 0, sizeof(D3DDDICB_LOCK));
    lockCB.hAllocation = m_HandleUsedInLastSubmit;
    lockCB.PrivateDriverData = 0;
    hr = m_d3dCallbacks.pfnLockCb(m_hD3D, &lockCB);
    if (FAILED(hr)) {
        DBG_BREAK;
        return hr;
    }
    Unlock.NumAllocations = 1;
    Unlock.phAllocations = &m_HandleUsedInLastSubmit;
    m_d3dCallbacks.pfnUnlockCb(m_hD3D, &Unlock);
    return hr;
}
```

## See also

[D3DDDICB_UNLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_unlock)

[D3DDDI_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks)

[DestroyDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroydevice)

[DestroyDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroydevice)

[ResourceUnmap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceunmap)

[Unlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_unlock)

[pfnLockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb)

[pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb)