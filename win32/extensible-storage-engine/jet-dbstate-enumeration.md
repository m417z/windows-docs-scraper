# JET_dbstate enumeration

Database states (used in [JET_DBINFOMISC](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-dbinfomisc-class)).

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
public enum JET_dbstate
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | JustCreated | The database was just created. |
|  | DirtyShutdown | Dirty shutdown (inconsistent) database. |
|  | CleanShutdown | Clean shutdown (consistent) database. |
|  | BeingConverted | Database is being converted. |
|  | ForceDetach | Database was force-detached. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)