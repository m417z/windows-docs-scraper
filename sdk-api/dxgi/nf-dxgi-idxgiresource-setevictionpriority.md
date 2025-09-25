# IDXGIResource::SetEvictionPriority

## Description

Set the priority for evicting the resource from memory.

## Parameters

### `EvictionPriority`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The priority is one of the following values:

| Value | Meaning |
| --- | --- |
| **DXGI_RESOURCE_PRIORITY_MINIMUM (0x28000000)** | The resource is unused and can be evicted as soon as another resource requires the memory that the resource occupies. |
| **DXGI_RESOURCE_PRIORITY_LOW (0x50000000)** | The eviction priority of the resource is low. The placement of the resource is not critical, and minimal work is performed to find a location for the resource. For example, if a GPU can render with a vertex buffer from either local or non-local memory with little difference in performance, that vertex buffer is low priority. Other more critical resources (for example, a render target or texture) can then occupy the faster memory. |
| **DXGI_RESOURCE_PRIORITY_NORMAL (0x78000000)** | The eviction priority of the resource is normal. The placement of the resource is important, but not critical, for performance. The resource is placed in its preferred location instead of a low-priority resource. |
| **DXGI_RESOURCE_PRIORITY_HIGH (0xa0000000)** | The eviction priority of the resource is high. The resource is placed in its preferred location instead of a low-priority or normal-priority resource. |
| **DXGI_RESOURCE_PRIORITY_MAXIMUM (0xc8000000)** | The resource is evicted from memory only if there is no other way of resolving the memory requirement. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## Remarks

The eviction priority is a memory-management variable that is used by DXGI for determining how to populate overcommitted memory.

You can set priority levels other than the defined values when appropriate. For example, you can set a resource with a priority level of 0x78000001 to indicate that the resource is slightly above normal.

## See also

[IDXGIResource](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiresource)