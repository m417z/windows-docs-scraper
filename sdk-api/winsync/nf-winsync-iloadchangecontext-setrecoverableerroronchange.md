# ILoadChangeContext::SetRecoverableErrorOnChange

## Description

Indicates a recoverable error on this change has occurred.

## Parameters

### `hrError` [in]

The error code that is associated with the error that prevented the item data from being loaded.

### `pErrorData` [in]

Additional information about the error.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *hrError* does not specify an error. |
| **SYNC_E_INTERNAL_ERROR** | An internal error has occurred. |

## Remarks

When this method is called, an **ISingleItemException** object is added to the learned knowledge; and the item change will not be enumerated again for the duration of the synchronization session.

## See also

[ILoadChangeContext Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-iloadchangecontext)

[ISingleItemException Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isingleitemexception)