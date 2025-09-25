# ISynchronizeContainer::AddSynchronize

## Description

Adds a synchronization object to the container.

## Parameters

### `pSync` [in]

A pointer to the synchronization object to be added to the container. See [ISynchronize](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-isynchronize).

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **RPC_E_OUT_OF_RESOURCES** | The synchronization object container is full. |

## Remarks

A synchronization container can hold pointers to as many as 63 synchronization objects.

## See also

[ISynchronize](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-isynchronize)

[ISynchronizeContainer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-isynchronizecontainer)