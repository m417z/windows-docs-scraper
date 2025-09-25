# IDebugDataSpaces3::VirtualToPhysical

## Description

The **VirtualToPhysical** method translates a location in the target's virtual address space into a physical memory address.

## Parameters

### `Virtual` [in]

Specifies the location in the target's virtual address space to translate.

### `Physical` [out]

Receives the physical memory address.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **HRESULT_FROM_NT(STATUS_NO_PAGEFILE)** | No physical page containing the specified address could be found. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

This method is only available in kernel-mode debugging.