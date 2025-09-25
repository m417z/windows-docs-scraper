# IContextState::GetDeactivateOnReturn

## Description

Retrieves the value of the done flag.

## Parameters

### `pbDeactivate` [out]

The done flag.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **CONTEXT_E_NOJIT** | [Just-in-Time Activation](https://learn.microsoft.com/windows/desktop/cossdk/com--just-in-time-activation) is not available to this context. |

## Remarks

When *pbDeactivate* is **FALSE** for the root object of a transaction, the object does not deactivate and the transaction does not terminate unless the client releases its reference to the object or until the done flag is set to **TRUE**.

## See also

[Consistent and Done Flags](https://learn.microsoft.com/windows/desktop/cossdk/consistent-and-done-flags)

[IContextState](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icontextstate)