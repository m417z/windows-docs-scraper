# IDebugControl3::SetSpecificFilterArgument

## Description

The **SetSpecificFilterArgument** method sets the value of filter argument for the specific filters that can have an argument.

## Parameters

### `Index` [in]

Specifies the index of the specific filter whose argument will be set. *Index* must be the index of a specific filter that has an argument.

### `Argument` [in]

Specifies the argument for the specific filter. The interpretation of this argument depends on the specific filter.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *Index* does not refer to a specific filter that has an argument. |

## Remarks

For a list of specific filters that have argument and the interpretation of those arguments, see [Event Filters](https://learn.microsoft.com/windows-hardware/drivers/debugger/event-filters).

## See also

[GetSpecificFilterArgument](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getspecificfilterargument)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[sx, sxd, sxe, sxi, sxn (Set Exceptions)](https://learn.microsoft.com/windows-hardware/drivers/debugger/sx--sxd--sxe--sxi--sxn--sxr--sx---set-exceptions-)