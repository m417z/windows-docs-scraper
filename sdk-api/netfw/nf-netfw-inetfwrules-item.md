# INetFwRules::Item

## Description

The **Item** method returns the specified rule if it is in the collection.

## Parameters

### `name` [in]

Name of the rule to retrieve.

### `rule` [out]

Reference to the returned [INetFwRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwrule) object.

## Return value

### C++

If the method succeeds the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was aborted due to permissions issues. |
| **E_INVALIDARG** | The method failed due to an invalid parameter. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |
| **E_POINTER** | The method failed due to an invalid pointer. |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)** | The requested item does not exist. |

### VB

If the method succeeds the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was aborted due to permissions issues. |
| **E_INVALIDARG** | The method failed due to an invalid parameter. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |
| **E_POINTER** | The method failed due to an invalid pointer. |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)** | The requested item does not exist. |

## See also

[INetFwRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwrule)

[INetFwRules](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwrules)