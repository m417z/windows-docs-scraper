# IEnumWbemClassObject::Skip

## Description

You can use the
**IEnumWbemClassObject::Skip** method to move the current position in an enumeration ahead by a specified number of objects. Also, this affects subsequent calls to
[NextAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-ienumwbemclassobject-nextasync), but it does not affect pending deliveries begun with
**NextAsync**.

## Parameters

### `lTimeout` [in]

Maximum amount of time in milliseconds that the call to
**Skip** blocks before returning. If you use the constant **WBEM_INFINITE** (0xFFFFFFFF), the call blocks until the operation succeeds. If
**Skip** cannot complete the operation before the *lTimeout* value expires, the call returns **WBEM_S_TIMEDOUT**.

### `nCount` [in]

Number of objects to skip. If this parameter is greater than the number of objects left to enumerate, then this call skips to the end of the enumeration and **WBEM_S_FALSE** is returned.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## Remarks

COM-specific error codes may also be returned if network problems cause you to lose the remote connection to Windows Management.