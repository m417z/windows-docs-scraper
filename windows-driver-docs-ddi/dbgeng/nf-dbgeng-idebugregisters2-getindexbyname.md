# IDebugRegisters2::GetIndexByName

## Description

The **GetIndexByName** method returns the index of the named register.

## Parameters

### `Name` [in]

Specifies the name of the register whose index is requested.

### `Index` [out]

Receives the index of the register.

## Return value

This list does not contain all the errors that might occur. For a list of possible errors, see [HRESULT Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOINTERFACE** | The register was not found. |

## Remarks

For an overview of the [IDebugRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters) interface and other register-related methods, see [Registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers).