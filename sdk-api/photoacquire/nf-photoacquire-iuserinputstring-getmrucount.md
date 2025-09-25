# IUserInputString::GetMruCount

## Description

The `GetMruCount` method retrieves the number of items in the list of most recently used items.

## Parameters

### `pnMruCount` [out]

Pointer to an integer value containing the number of items in the list of most recently used items.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A **NULL** pointer was passed where a non-**NULL** pointer is expected. |

## Remarks

If an error occurs, *pnMruCount* will be set to 0.

## See also

[IUserInputString Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iuserinputstring)