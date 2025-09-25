# PFND3DDDI_LOCK callback function

## Description

The *Lock* function locks the given resource or a surface within the resource.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDIARG_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_lock) structure that describes the resource or surface within the resource to lock.

## Return value

*Lock* returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The resource is successfully locked. |
| **E_OUTOFMEMORY** | Lock could not allocate the required memory for it to complete. |
| **D3DDDIERR_WASSTILLDRAWING** | The resource was not idle when the Microsoft Direct3D runtime called the Lock function with the DoNotWait bit-field flag set in the Flags member of [D3DDDIARG_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_lock) . |

## Remarks

The Microsoft Direct3D runtime calls the user-mode display driver's *Lock* function to lock a resource or a surface within the resource. This locked resource or surface can be read from or written to by using read and write operations from the CPU. When the runtime calls *Lock*, the user-mode display driver must call the runtime's [pfnLockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb) callback function to lock an allocation corresponding to the resource or surface. Note that because the user-mode display driver can allocate multiple allocations for each resource or surface, the user-mode display driver might be required to appropriately convert or process the allocation pointer that is returned from **pfnLockCb** before returning the *Lock* call to the runtime.

Typically, calls to *Lock* are followed by matching calls to the driver's [Unlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_unlock) function before the driver receives any calls to its draw-primitive functions (that is, calls to [DrawIndexedPrimitive](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawindexedprimitive), [DrawIndexedPrimitive2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawindexedprimitive2), [DrawPrimitive](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawprimitive), and [DrawPrimitive2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawprimitive2)). This order guarantees that a driver is never requested to draw from a locked resource. However, on occasion, when performing software transform and lighting, the runtime must call one of the driver's draw-primitive functions before unlocking a resource (currently, only vertex buffers exhibit this behavior). The runtime marks vertex buffers on which this uncommon behavior might occur with the **MightDrawFromLocked** bit-field flag in the **Flags** member of the [D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource) and [D3DDDIARG_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_lock) structures (that is, both at creation and at lock time). When the hardware actively renders from a locked vertex buffer, the driver is not required to take any special action because the runtime will not overwrite any data in the locked vertex buffer .

The runtime calls the user-mode display driver's *Lock* function to lock preallocated system memory surfaces as well. This operation allows the user-mode display driver to properly synchronize references to such surfaces that might be in the hardware command stream. The user-mode display driver can accomplish the synchronization by:

* Flushing (that is, calling the runtime's [pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb) callback function) any outstanding commands as necessary.
* Calling **pfnLockCb** with the appropriate allocation handle for commands that have already been submitted to hardware.

The user-mode display driver returns a pointer to the memory for the locked surface and the pitch of the surface in the **pSurfData** and **Pitch** members of the D3DDDIARG_LOCK structure. However, for preallocated system memory surfaces, the runtime ignores the driver-set memory and pitch, although the driver can still fail the *Lock* call (and thus fail back to the application). The runtime sets the **NotifyOnly** bit-field flag in the **Flags** member of the [D3DDDIARG_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_lock) structure to differentiate *Lock* calls that lock preallocated system memory surfaces from other *Lock* calls.

## See also

[D3DDDIARG_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_lock)

[D3DDDI_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationinfo)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[pfnLockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb)

[pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb)