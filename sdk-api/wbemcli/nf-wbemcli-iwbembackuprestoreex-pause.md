# IWbemBackupRestoreEx::Pause

## Description

The **IWbemBackupRestoreEx::Pause** method locks out write operations from the Windows Management Instrumentation (WMI) repository, and may cause read operations to be blocked.

## Return value

This method returns an **HRESULT** that indicates the status of a method call. The following list lists the values contained within an **HRESULT**.

## Remarks

When implementing the **Pause** method, the [Resume](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbembackuprestoreex-resume) method should be called as soon as possible. If **Resume** is not called within fifteen (15) minutes, it is called automatically for you. Calling **Pause** two times on the same object without calling **Resume** first will fail. Calling **Pause** on two objects at the same time may cause the second object to lock up until **Resume** is called on the first object.

**Note** To implement the **Pause** method, the client user must have **SE_BACKUP_NAME** prior to calling the method.

#### Examples

The following C++ example shows how to correctly call the **IWbemBackupRestoreEx::Pause** method.

```cpp
// The pInt variable is of type IWbemBackupRestoreEx*
pInt->Pause();
```

## See also

[IWbemBackupRestoreEx](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbembackuprestoreex)