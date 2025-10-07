# OpenTableGrbit enumeration

Options for JetOpenTable.

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum OpenTableGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | DenyWrite | This table cannot be opened for write access by another session. |
|  | DenyRead | This table cannot be opened for read access by another session. |
|  | ReadOnly | Request read-only access to the table. |
|  | Updatable | Request write access to the table. |
|  | PermitDDL | Allow DDL modifications to a table flagged as FixedDDL. This option must be used with DenyRead. |
|  | NoCache | Do not cache pages for this table. |
|  | Preread | Provides a hint that the table is probably not in the buffer cache, and that pre-reading may be beneficial to performance. |
|  | Sequential | Assume a sequential access pattern and prefetch database pages. |
|  | TableClass1 | Table belongs to stats class 1. |
|  | TableClass2 | Table belongs to stats class 2. |
|  | TableClass3 | Table belongs to stats class 3. |
|  | TableClass4 | Table belongs to stats class 4. |
|  | TableClass5 | Table belongs to stats class 5. |
|  | TableClass6 | Table belongs to stats class 6. |
|  | TableClass7 | Table belongs to stats class 7. |
|  | TableClass8 | Table belongs to stats class 8. |
|  | TableClass9 | Table belongs to stats class 9. |
|  | TableClass10 | Table belongs to stats class 10. |
|  | TableClass11 | Table belongs to stats class 11. |
|  | TableClass12 | Table belongs to stats class 12. |
|  | TableClass13 | Table belongs to stats class 13. |
|  | TableClass14 | Table belongs to stats class 14. |
|  | TableClass15 | Table belongs to stats class 15. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)