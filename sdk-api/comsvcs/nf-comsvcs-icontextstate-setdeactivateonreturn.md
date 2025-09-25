# IContextState::SetDeactivateOnReturn

## Description

Sets the done flag, which controls whether the object deactivates on method return.

## Parameters

### `bDeactivate` [in]

The done flag.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **CONTEXT_E_NOJIT** | [Just-in-Time Activation](https://learn.microsoft.com/windows/desktop/cossdk/com--just-in-time-activation) is not available to this context. |

## Remarks

When set to true, the done flag causes the object to deactivate when the method call returns. When set to false, the object remains active after the method call returns.
The default value of the done flag is false.

## See also

[Consistent and Done Flags](https://learn.microsoft.com/windows/desktop/cossdk/consistent-and-done-flags)

[IContextState](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icontextstate)