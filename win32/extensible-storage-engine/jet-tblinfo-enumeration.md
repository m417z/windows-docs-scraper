# JET_TblInfo enumeration

Info levels for retrieving table info with JetGetTableInfo.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
public enum JET_TblInfo
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | Default | Default option. Retrieves a [JET_OBJECTINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/dn335219(v=exchg.10).md) containing information about the table. Use this option with [JetGetTableInfo(JET_SESID, JET_TABLEID, JET_OBJECTINFO, JET_TblInfo)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/dn292198(v=exchg.10).md). |
|  | Name | Retrieves the name of the table. Use this option with [JetGetTableInfo(JET_SESID, JET_TABLEID, String, JET_TblInfo)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/dn292204(v=exchg.10).md). |
|  | Dbid | Retrieves the [JET_DBID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/hh596176(v=exchg.10).md) of the database containing the table. Use this option with [JetGetTableInfo(JET_SESID, JET_TABLEID, JET_DBID, JET_TblInfo)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/dn292197(v=exchg.10).md). |
|  | SpaceUsage | The behavior of the method depends on how large the array that is passed to the method is. The array must have at least two entries. The first entry will contain the number of Owned Extents in the table. The second entry will contain the number of Available Extents in the table. If the array has more than two entries then the remaining bytes of the buffer will consist of an array of structures that represent a list of extents. This structure contains two members: the last page number in the extent and the number of pages in the extent. Use this option with [JetGetTableInfo(JET_SESID, JET_TABLEID, [], JET_TblInfo)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/dn292202(v=exchg.10).md). |
|  | SpaceAlloc | The array passed to JetGetTableInfo must have two entries. The first entry will be set to the number of pages in the table. The second entry will be set to the target density of pages for the table. Use this option with [JetGetTableInfo(JET_SESID, JET_TABLEID, [], JET_TblInfo)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/dn292202(v=exchg.10).md). |
|  | SpaceOwned | Gets the number of owned pages in the table. Use this option with [JetGetTableInfo(JET_SESID, JET_TABLEID, Int32, JET_TblInfo)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/dn292201(v=exchg.10).md). |
|  | SpaceAvailable | Gets the number of available pages in the table. Use this option with [JetGetTableInfo(JET_SESID, JET_TABLEID, Int32, JET_TblInfo)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/dn292201(v=exchg.10).md). |
|  | TemplateTableName | If the table is a derived table, the result will be filled in with the name of the table from which the derived table inherited its DDL. If the table is not a derived table, the buffer will an empty string. Use this option with [JetGetTableInfo(JET_SESID, JET_TABLEID, String, JET_TblInfo)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/dn292204(v=exchg.10).md). |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)