# IDirect3DResource9::SetPriority

## Description

Assigns the priority of a resource for scheduling purposes.

## Parameters

### `PriorityNew` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Priority to assign to a resource.

|  |
| --- |
| Differences between Direct3D 9 and Direct3D 9 for Windows Vista<br><br>The priority can be any DWORD value; Direct3D 9 for Windows Vista also supports any of these pre-defined values [D3D9_RESOURCE_PRIORITY](https://learn.microsoft.com/windows/desktop/direct3d9/d3d9-resource-priority). |

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns the previous priority value for the resource.

## Remarks

This method is used to change the priority of managed resources (resources created with the [D3DPOOL_MANAGED](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpool) flag). This method returns 0 on non-managed resources.

Priorities are used to determine when managed resources are to be removed from memory. A resource assigned a low priority is removed before a resource with a high priority. If two resources have the same priority, the resource that was used more recently is kept in memory; the other resource is removed. Managed resources have a default priority of 0.

Windows Vista only - When this method is called using an [IDirect3D9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3d9ex) interface, only resources created with the [D3DPOOL_DEFAULT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpool) flag will be affected.

## See also

[IDirect3DResource9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dresource9)