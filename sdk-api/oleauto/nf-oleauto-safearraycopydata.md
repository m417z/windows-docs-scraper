# SafeArrayCopyData function

## Description

Copies the source array to the specified target array after releasing any resources in the target array. This is similar to [SafeArrayCopy](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearraycopy), except that the target array has to be set up by the caller. The target is not allocated or reallocated.

## Parameters

### `psaSource` [in]

The safe array to copy.

### `psaTarget` [in]

The target safe array.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The argument *psa* was not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |