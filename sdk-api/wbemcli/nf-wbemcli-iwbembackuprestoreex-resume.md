# IWbemBackupRestoreEx::Resume

## Description

The **IWbemBackUpRestoreEx::Resume** method releases a lock on the Windows Management Instrumentation (WMI) repository so operations can continue.

## Return value

This method returns an **HRESULT** that indicates the status of a method call. The following list lists the values contained within an **HRESULT**.

## Remarks

The **Resume** method should always be called when the [Pause](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbembackuprestoreex-pause) method is called. **Resume** must be called on the same instance of [IWbemBackUpRestoreEx](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbembackuprestoreex) that the **Pause** method is implemented. Releasing the object without calling **Resume** automatically causes the **Resume** method to be implemented.

**Note** To implement the **Resume** method, the client user must have **SE_BACKUP_NAME** prior to calling the method.

#### Examples

The following C++ example shows how to call the **IWbemBackUpRestoreEx::Resume** method.

```cpp
// The pInt variable is of type IWbemBackupRestoreEx*
pInt->Resume();
```

## See also

[IWbemBackupRestoreEx](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbembackuprestoreex)