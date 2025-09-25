# IDebugDataSpaces::ReadMsr

## Description

The **ReadMsr** method reads a specified Model-Specific Register (MSR).

## Parameters

### `Msr` [in]

Specifies the MSR address.

### `Value` [out]

Receives the value of the MSR.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

This method is only available in kernel-mode debugging.

For details on the addresses and values of MSRs, see the processor documentation.