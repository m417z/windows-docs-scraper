# IDebugRegisters2::SetPseudoValues

## Description

The **SetPseudoValues** method sets the value of several pseudo-registers.

## Parameters

### `Source` [in]

Specifies the register source to query.

The possible values are listed in the following table.

| Value | Register source |
| --- | --- |
| DEBUG_REGSRC_DEBUGGEE | Fetch register information from the target. |
| DEBUG_REGSRC_EXPLICIT | Fetch register information from the current explicit [register context](https://learn.microsoft.com/windows-hardware/drivers/debugger/changing-contexts). |
| DEBUG_REGSRC_FRAME | Fetch register information from the current scope's register context.<br><br>**Note** Stack unwinding does not guarantee accurate updating of the register context, so the scope frame's register context might not be accurate in all cases. |

### `Count` [in]

Specifies the number of pseudo-registers whose values are being set.

### `Indices` [in, optional]

Specifies an array of indices of pseudo-registers. These are the pseudo-registers whose values will be set. The size of *Indices* is *Count*. If *Indices* is **NULL**, *Start* is used to specify the indices instead.

### `Start` [in]

Specifies the index of the first pseudo-register whose value will be set. The pseudo-registers with indices between *Start* and *Start* plus *Count* minus one, will be set. *Start* is only used if *Indices* is **NULL**.

### `Values` [in]

Specifies the new values of the pseudo-registers. The number of elements this array holds is *Count*. See [DEBUG_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_value) for a description of this parameter type.

## Return value

This list does not contain all the errors that might occur. For a list of possible errors, see [HRESULT Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For an overview of the [IDebugRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters) interface and other register-related methods, see [Registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers).

## See also

[GetPseudoValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-getpseudovalues)

[IDebugRegisters2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters2)