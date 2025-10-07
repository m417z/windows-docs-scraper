# EnumerateColumnsGrbit enumeration

Options for JetEnumerateColumns.

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum EnumerateColumnsGrbit
```

## Members

| Member name | Description |
|-------------|-------------|
| None | Default options. |
| EnumerateCompressOutput | When enumerating column values, all columns for which we are retrieving all values and that have only one non-NULL column value may be returned in a compressed format. The status for such columns will be set to [ColumnSingleValue](https://learn.microsoft.com/windows/win32/extensible-storage-engine/hh557250(v=exchg.10).md) and the size of the column value and the memory containing the column value will be returned directly in the [JET_ENUMCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/dn335081(v=exchg.10).md) structure. It is not guaranteed that all eligible columns are compressed in this manner. See [JET_ENUMCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/dn335081(v=exchg.10).md) for more information. |
| EnumerateCopy | This option indicates that the modified column values of the record should be enumerated rather than the original column values. If a column value has not been modified, the original column value is enumerated. In this way, a column value that has not yet been inserted or updated may be enumerated when inserting or updating a record.

This option is identical to [RetrieveCopy](https://learn.microsoft.com/windows/win32/extensible-storage-engine/hh578120(v=exchg.10).md).

|
| EnumerateIgnoreDefault | If a given column is not present in the record then no column value will be returned. Ordinarily, the default value for the column, if any, would be returned in this case. It is guaranteed that if the column is set to a value different than the default value then that different value will be returned (that is, if a column with a default value is explicitly set to NULL then a NULL will be returned as the value for that column). Even if this option is requested, it is still possible to see a column value that happens to be equal to the default value. No effort is made to remove column values that match their default values. It is important to remember that this option affects the output of [JetEnumerateColumns(JET_SESID, JET_TABLEID, Int32, [], Int32, [], JET_PFNREALLOC, IntPtr, Int32, EnumerateColumnsGrbit)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/dn292148(v=exchg.10).md) when used with EnumeratePresenceOnly or EnumerateTaggedOnly. |
| EnumeratePresenceOnly | If a non-NULL value exists for the requested column or column value then the associated data is not returned. Instead, the associated status for that column or column value will be set to [ColumnPresent](https://learn.microsoft.com/windows/win32/extensible-storage-engine/hh557250(v=exchg.10).md). If the column or column value is NULL then [ColumnNull](https://learn.microsoft.com/windows/win32/extensible-storage-engine/hh557250(v=exchg.10).md) will be returned as usual. |
| EnumerateTaggedOnly | When enumerating all column values in the record (for example,that is when numColumnids is zero), only tagged column values will be returned. This option is not allowed when enumerating a specific array of column IDs. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)

[EnumerateIgnoreUserDefinedDefault](https://learn.microsoft.com/windows/win32/extensible-storage-engine/server2003grbits.enumerateignoreuserdefineddefault-field)

[EnumerateInRecordOnly](https://learn.microsoft.com/windows/win32/extensible-storage-engine/windows7grbits.enumerateinrecordonly-field)