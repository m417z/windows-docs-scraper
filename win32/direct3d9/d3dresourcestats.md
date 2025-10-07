# D3DRESOURCESTATS structure

Resource statistics gathered by the [**D3DDEVINFO\_ResourceManager**](https://learn.microsoft.com/windows/win32/direct3d9/d3ddevinfo-resourcemanager) when using the asynchronous query mechanism.

## Members

**bThrashing**

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Indicates if thrashing is occurring.

**ApproxBytesDownloaded**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Approximate number of bytes downloaded by the resource manager.

**NumEvicts**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of objects evicted.

**NumVidCreates**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of objects created in video memory.

**LastPri**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Priority of last object evicted.

**NumUsed**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of objects set to the device.

**NumUsedInVidMem**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of objects set to the device, which are already in video memory.

**WorkingSet**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of objects in video memory.

**WorkingSetBytes**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of bytes in video memory.

**TotalManaged**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Total number of managed objects.

**TotalBytes**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Total number of bytes of managed objects.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

[Asynchronous Notification (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/asynchronous-notification)

