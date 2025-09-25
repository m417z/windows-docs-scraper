## Description

Creates a special-purpose diagnostic heap in system memory from a file mapping object. The created heap can persist even in the event of a GPU-fault or device-removed scenario.

## Parameters

### `hFileMapping`

Type: **[HANDLE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The handle to the file mapping object to use to create the heap.

### `riid`

Type: **REFIID**

The globally unique identifier (**GUID**) for the heap interface ([ID3D12Heap](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12heap)).

The **REFIID**, or **GUID**, of the interface to the heap can be obtained by using the **__uuidof()** macro. For example, **__uuidof(ID3D12Heap)** will retrieve the **GUID** of the interface to a heap.

### `ppvHeap` [out]

Type: **void\*\***

[SAL](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-parameters-and-return-values?view=vs-2015&preserve-view=true): `_COM_Outptr_`

A pointer to a memory block. On success, the D3D12 runtime will write a pointer to the newly-opened heap into the memory block. The type of the pointer depends on the provided **riid** parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns **E_OUTOFMEMORY** if there is insufficient memory to open the existing heap. See [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues) for other possible return values.

## Remarks

The heap is created in system memory, and it permits CPU access. It wraps the entire VirtualAlloc region.

Heaps can be used for placed and reserved resources, as orthogonally as other heaps. Restrictions may still exist based on the flags that cannot be app-chosen.

## See also

[ID3D12Device3 interface](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device3)