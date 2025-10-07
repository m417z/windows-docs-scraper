# JET_DbInfo enumeration

Info levels for retrieving database info.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
public enum JET_DbInfo
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | Filename | Returns the path to the database file (string). |
|  | LCID | Returns the locale identifier (LCID) associated with this database (Int32). |
|  | Options | Returns a [OpenDatabaseGrbit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/hh579532(v=exchg.10).md). This indicates whether the database is opened in exclusive mode. If the database is in exclusive mode then [Exclusive](https://learn.microsoft.com/windows/win32/extensible-storage-engine/hh579532(v=exchg.10).md) will be returned, otherwise zero is returned. Other database grbit options for JetAttachDatabase and JetOpenDatabase are not returned. |
|  | Transactions | Returns a number one greater than the maximum level to which transactions can be nested. If [JetBeginTransaction(JET_SESID)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/dn292105(v=exchg.10).md) is called (in a nesting fashion, that is, on the same session, without a commit or rollback) as many times as this value, on the last call [TransTooDeep](https://learn.microsoft.com/windows/win32/extensible-storage-engine/hh564840(v=exchg.10).md) will be returned (Int32). |
|  | Version | Returns the major version of the database engine (Int32). |
|  | Filesize | Returns the filesize of the database, in pages (Int32). |
|  | SpaceOwned | Returns the owned space of the database, in pages (Int32). |
|  | SpaceAvailable | Returns the available space in the database, in pages (Int32). |
|  | Misc | Returns a [JET_DBINFOMISC](https://learn.microsoft.com/windows/win32/extensible-storage-engine/hh538867(v=exchg.10).md) object. |
|  | DBInUse | Returns a boolean indicating whether the database is attached (boolean). |
|  | PageSize | Returns the page size of the database (Int32). |
|  | FileType | Returns the type of the database ([JET_filetype](https://learn.microsoft.com/windows/win32/extensible-storage-engine/hh566739(v=exchg.10).md)). |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)