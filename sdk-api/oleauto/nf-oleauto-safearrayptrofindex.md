# SafeArrayPtrOfIndex function

## Description

Gets a pointer to an array element.

## Parameters

### `psa` [in]

An array descriptor created by [SafeArrayCreate](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearraycreate).

### `rgIndices` [in]

An array of index values that identify an element of the array. All indexes for the element must be specified.

### `ppvData` [out]

The array element.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **DISP_E_BADINDEX** | The specified index is not valid. |
| **E_INVALIDARG** | One of the arguments is not valid. |

## Remarks

The array should be locked before **SafeArrayPtrOfIndex** is called. Failing to lock the array can cause unpredictable results.