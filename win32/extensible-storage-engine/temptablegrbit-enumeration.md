# TempTableGrbit enumeration

Options for temporary table creation.

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum TempTableGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | Indexed | This option requests that the temporary table be flexible enough to permit the use of JetSeek to lookup records by index key. If this functionality it not required then it is best to not request it. If this functionality is not requested then the temporary table manager may be able to choose a strategy for managing the temporary table that will result in improved performance. |
|  | Unique | This option requests that records with duplicate index keys be removed from the final set of records in the temporary table. Prior to Windows Server 2003, the database engine always assumed this option to be in effect due to the fact that all clustered indexes must also be a primary key and thus must be unique. As of Windows Server 2003, it is now possible to create a temporary table that does NOT remove duplicates when the [ForwardOnly](https://learn.microsoft.com/windows/win32/extensible-storage-engine/dn351284(v=exchg.10).md) option is also specified. It is not possible to know which duplicate will win and which duplicates will be discarded in general. However, when the ErrorOnDuplicateInsertion option is requested then the first record with a given index key to be inserted into the temporary table will always win. |
|  | Updatable | This option requests that the temporary table be flexible enough to allow records that have previously been inserted to be subsequently changed. If this functionality it not required then it is best to not request it. If this functionality is not requested then the temporary table manager may be able to choose a strategy for managing the temporary table that will result in improved performance. |
|  | Scrollable | This option requests that the temporary table be flexible enough to allow records to be scanned in arbitrary order and direction using [JetMove(JET_SESID, JET_TABLEID, Int32, MoveGrbit)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/dn292217(v=exchg.10).md). If this functionality it not required then it is best to not request it. If this functionality is not requested then the temporary table manager may be able to choose a strategy for managing the temporary table that will result in improved performance. |
|  | SortNullsHigh | This option requests that NULL key column values sort closer to the end of the index than non-NULL key column values. |
|  | ForceMaterialization | This option forces the temporary table manager to abandon any attempt to choose a clever strategy for managing the temporary table that will result in enhanced performance. |
|  | ErrorOnDuplicateInsertion | This option requests that any attempt to insert a record with the same index key as a previously inserted record will immediately fail with [KeyDuplicate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/hh564840(v=exchg.10).md). If this option is not requested then a duplicate may be detected immediately and fail or may be silently removed later depending on the strategy chosen by the database engine to implement the temporary table based on the requested functionality. If this functionality it not required then it is best to not request it. If this functionality is not requested then the temporary table manager may be able to choose a strategy for managing the temporary table that will result in improved performance. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)

[ForwardOnly](https://learn.microsoft.com/windows/win32/extensible-storage-engine/server2003grbits.forwardonly-field)

[IntrinsicLVsOnly](https://learn.microsoft.com/windows/win32/extensible-storage-engine/windows7grbits.intrinsiclvsonly-field)