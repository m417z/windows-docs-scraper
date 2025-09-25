# ILoadChangeContext::SetRecoverableErrorOnChangeUnit

## Description

Indicates that a recoverable error occurred when data for the specified change unit was loaded from the item store.

## Parameters

### `hrError` [in]

The error code that is associated with the error that prevented the change unit data from being loaded.

### `pChangeUnit` [in]

The change unit change that caused the error.

### `pErrorData` [in]

Additional information about the error.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *hrError* does not specify an error. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_ON_CREATE_MUST_FAIL_ENTIRE_ITEM** | The change that contains this change unit refers to an item creation. In this case, the error must be reported on the item change by using [ILoadChangeContext::SetRecoverableErrorOnChange](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-iloadchangecontext-setrecoverableerroronchange). |
| **SYNC_E_INTERNAL_ERROR** | An internal error has occurred. |

## Remarks

When this method is called, an **IChangeUnitException** object is added to the learned knowledge; and the change unit change will not be enumerated again for the duration of the synchronization session.

## See also

[IChangeUnitException Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ichangeunitexception)

[ILoadChangeContext Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-iloadchangecontext)