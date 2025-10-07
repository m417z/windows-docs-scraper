# GetLockGrbit enumeration

Options for JetGetLock.

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum GetLockGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | Read | Acquire a read lock on the current record. Read locks are incompatible with write locks already held by other sessions but are compatible with read locks held by other sessions. |
|  | Write | Acquire a write lock on the current record. Write locks are not compatible with write or read locks held by other sessions but are compatible with read locks held by the same session. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)