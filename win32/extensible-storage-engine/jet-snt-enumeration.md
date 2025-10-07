# JET_SNT enumeration

Type of progress being reported.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
public enum JET_SNT
```

## Members

| Member name | Description |
|-------------|-------------|
| Begin | Callback for the beginning of an operation. |
| Progress | Callback for operation progress. |
| Complete | Callback for the completion of an operation. |
| Fail | Callback for failure during the operation. |
| RecoveryStep | Callback for recovery control.

Used for internal processing in versions of the Windows operating system earlier than Windows 8. This value is not applicable to versions of Windows starting with Windows 8.

|

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)