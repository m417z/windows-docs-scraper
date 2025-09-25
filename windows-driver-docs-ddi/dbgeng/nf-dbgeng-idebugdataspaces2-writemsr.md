# IDebugDataSpaces2::WriteMsr

## Description

The **WriteMsr** method writes a value to the specified Model-Specific Register (MSR).

## Parameters

### `Msr`

Specifies the MSR address.

### `Value`

Specifies the value to write to the MSR.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

This method is only available in kernel-mode debugging.

For details on the addresses and values of MSRs, see the processor documentation.