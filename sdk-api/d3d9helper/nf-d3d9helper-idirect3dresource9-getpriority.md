# IDirect3DResource9::GetPriority

## Description

Retrieves the priority for this resource.

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns a DWORD value, indicating the priority of the resource.

## Remarks

**IDirect3DResource9::GetPriority** is used for priority control of managed resources. This method returns 0 on nonmanaged resources.

Priorities are used to determine when managed resources are to be removed from memory. A resource assigned a low priority is removed before a resource with a high priority. If two resources have the same priority, the resource that was used more recently is kept in memory; the other resource is removed. Managed resources have a default priority of 0.

## See also

[IDirect3DResource9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dresource9)