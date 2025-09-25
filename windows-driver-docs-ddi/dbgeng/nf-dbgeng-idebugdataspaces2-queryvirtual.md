# IDebugDataSpaces2::QueryVirtual

## Description

The **QueryVirtual** method provides information about the specified pages in the target's virtual address space.

## Parameters

### `Offset` [in]

Specifies the location in the target's virtual address space of the pages whose information is requested.

### `Info` [out]

Receives the information about the memory page.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method may not work in all sessions.

This method returns attributes for a range of pages. This range is determined by Windows; it begins at the specified page, and includes all subsequent pages with the same attributes. The size of the range is given by the **RegionSize** field of the structure returned in *Info*.

MEMORY_BASIC_INFORMATION64 appears in the Microsoft Windows SDK header file winnt.h. It is the 64-bit equivalent of MEMORY_BASIC_INFORMATION, which is described in the Windows SDK documentation.

This method behaves in a similar way to the Windows SDK function **VirtualQuery**. See Windows SDK documentation for details.