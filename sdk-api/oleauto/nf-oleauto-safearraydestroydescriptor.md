# SafeArrayDestroyDescriptor function

## Description

Destroys the descriptor of the specified safe array.

## Parameters

### `psa` [in]

A safe array descriptor.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The argument *psa* was not valid. |
| **DISP_E_ARRAYISLOCKED** | The array is locked. |

## Remarks

This function is typically used to destroy the descriptor of a safe array that contains elements with data types other than variants. Destroying the array descriptor does not destroy the elements in the array. Before destroying the array descriptor, call [SafeArrayDestroyData](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearraydestroydata) to free the elements.