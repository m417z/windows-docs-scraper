# MAPIFreeBuffer function

## Description

[The use of this function is discouraged. It may be altered or unavailable in subsequent versions of Windows.]

The **MAPIFreeBuffer** function frees memory allocated by the messaging system.

## Parameters

### `pv` [in]

Pointer to memory allocated by the messaging system. This pointer is returned by the [MAPIReadMail](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapireadmail), [MAPIAddress](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapiaddress), and [MAPIResolveName](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapiresolvename) functions.

## Return value

This function returns one of the following values.

| Return code | Description |
| --- | --- |
| **MAPI_E_FAILURE** | One or more unspecified errors occurred. The memory could not be freed. |
| **SUCCESS_SUCCESS** | The call succeeded and the memory was freed. |

## See also

[MAPILogoff](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapilogoff)

[Simple MAPI](https://learn.microsoft.com/previous-versions/dd296734(v=vs.85))