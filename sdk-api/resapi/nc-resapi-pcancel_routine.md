# PCANCEL_ROUTINE callback function

## Description

Cancels an operation on a resource.

## Parameters

### `Resource` [in]

The resource ID of the resource.

### `CancelFlags_RESERVED` [in]

Reserved.

## Return value

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The quorum resource was successfully released and is no longer being defended. |
| **[Error code](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/error-codes)** | The operation was not successfully canceled. |

## See also

[Resource DLL Entry-Point Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-entry-point-functions)