# SafeArrayGetLBound function

## Description

Gets the lower bound for any dimension of the specified safe array.

## Parameters

### `psa` [in]

An array descriptor created by [SafeArrayCreate](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearraycreate).

### `nDim` [in]

The array dimension for which to get the lower bound.

### `plLbound` [out]

The lower bound.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One of the arguments is not valid. |
| **DISP_E_BADINDEX** | The specified index is out of bounds. |