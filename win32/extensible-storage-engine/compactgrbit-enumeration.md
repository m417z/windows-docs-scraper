# CompactGrbit enumeration

Options for [JetCompact(JET_SESID, String, String, JET_PFNSTATUS, JET_CONVERT, CompactGrbit)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/api.jetcompact-method).

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum CompactGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | Stats | Causes JetCompact to dump statistics on the source database to a file named DFRGINFO.TXT. Statistics include the name of each table in source database, number of rows in each table, total size in bytes of all rows in each table, total size in bytes of all columns of type [LongText](https://learn.microsoft.com/windows/win32/extensible-storage-engine/hh577895(v=exchg.10).md) or [LongBinary](https://learn.microsoft.com/windows/win32/extensible-storage-engine/hh577895(v=exchg.10).md) that were large enough to be stored separate from the record, number of clustered index leaf pages, and the number of long value leaf pages. In addition, summary statistics including the size of the source database, destination database, time required for database compaction, temporary database space are all dumped as well. |
|  | Repair | **Obsolete.** Used when the source database is known to be corrupt. It enables a whole set of new behaviors intended to salvage as much data as possible from the source database. JetCompact with this option set may return [Success](https://learn.microsoft.com/windows/win32/extensible-storage-engine/hh564840(v=exchg.10).md) but not copy all of the data created in the source database. Data that was in damaged portions of the source database will be skipped. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)