# GetLatticePtr function

## Description

Retrieves a pointer to the lattice for the current results.

## Parameters

### `hrc`

The handle to the recognizer context.

### `ppLattice`

The recognition results.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Unable to allocate memory to complete the operation. |
| **E_NOTIMPL** | The recognizer does not support this function. |
| **TPC_E_NOT_RELEVANT** | The recognizer context does not contain results. |
| **E_POINTER** | One of the parameters is an invalid pointer. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | An invalid argument was received. |

## See also

[Recognizer Lattice Structure](https://learn.microsoft.com/windows/desktop/tablet/recognizer-lattice-structure)