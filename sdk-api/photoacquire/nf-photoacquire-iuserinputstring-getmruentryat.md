# IUserInputString::GetMruEntryAt

## Description

The `GetMruEntryAt` method retrieves the entry at the given index in the most recently used list.

## Parameters

### `nIndex` [in]

Integer containing the index at which to retrieve the entry.

### `pbstrMruEntry` [out]

Pointer to a string containing the most recently used entry.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A **NULL** pointer was passed where a non-**NULL** pointer is expected. |

## See also

[IUserInputString Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iuserinputstring)