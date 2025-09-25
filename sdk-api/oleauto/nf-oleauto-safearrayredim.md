# SafeArrayRedim function

## Description

Changes the right-most (least significant) bound of the specified safe array.

## Parameters

### `psa` [in, out]

A safe array descriptor.

### `psaboundNew` [in]

A new safe array bound structure that contains the new array boundary. You can change only the least significant dimension of an array.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The argument *psa* is not valid. |
| **DISP_E_ARRAYISLOCKED** | The array is locked. |

## Remarks

If you reduce the bound of an array, **SafeArrayRedim** deallocates the array elements outside the new array boundary. If the bound of an array is increased, **SafeArrayRedim** allocates and initializes the new array elements. The data is preserved for elements that exist in both the old and new array.