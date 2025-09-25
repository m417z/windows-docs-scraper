# PFND3DDDI_UNLOCK callback function

## Description

The *Unlock* function unlocks a resource or a surface within the resource that was previously locked by the *Lock* function.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_UNLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_unlock) structure that describes the resource or surface within the resource to unlock.

## Return value

*Unlock* returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The resource is successfully unlocked. |
| **E_OUTOFMEMORY** | Unlock could not allocate the required memory for it to complete. |
| **E_INVALIDARG** | The resource that [D3DDDIARG_UNLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_unlock) describes was not locked by a previous call to the driver's [Lock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lock) function. |

## Remarks

These comments are analogous to the description in the Remarks section of the [Lock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lock) reference page.

The user-mode display driver must call the Microsoft Direct3D runtime's [pfnUnlockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_unlockcb) function after *Unlock* is called. In this **pfnUnlockCb** call, the user-mode display driver passes an allocation handle. Before calling **pfnUnlockCb**, the user-mode display driver must first map the surface to an appropriate allocation.

The runtime calls the user-mode display driver's *Unlock* function to unlock preallocated system memory surfaces as well. The runtime sets the **NotifyOnly** bit-field flag in the **Flags** member of the [D3DDDIARG_UNLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_unlock) structure that is pointed to by *pData* to differentiate *Unlock* calls that unlock preallocated system memory from other *Unlock* calls. If the user-mode display driver's *Lock* function called [pfnLockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb) to lock the system memory allocation that corresponds to the surface, it must also call **pfnUnlockCb**. Not calling **pfnUnlockCb** stops the coordination between the runtime, the user-mode display driver, and the display miniport driver.

## See also

[D3DDDIARG_UNLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_unlock)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[Lock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lock)

[pfnLockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb)

[pfnUnlockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_unlockcb)