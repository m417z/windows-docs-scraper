# ColumndefGrbit enumeration

Options for the JET_COLUMNDEF structure.

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum ColumndefGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | ColumnFixed | The column will be fixed. It will always use the same amount of space in a row, regardless of how much data is being stored in the column. ColumnFixed cannot be used with ColumnTagged. This bit cannot be used with long values (that is JET_coltyp.LongText and JET_coltyp.LongBinary). |
|  | ColumnTagged | The column will be tagged. Tagged columns do not take up any space in the database if they do not contain data. This bit cannot be used with ColumnFixed. |
|  | ColumnNotNULL | The column must never be set to a NULL value. On Windows XP this can only be applied to fixed columns (bit, byte, integer, etc). |
|  | ColumnVersion | The column is a version column that specifies the version of the row. The value of this column starts at zero and will be automatically incremented for each update on the row. This option can only be applied to JET_coltyp.Long columns. This option cannot be used with ColumnAutoincrement, ColumnEscrowUpdate, or ColumnTagged. |
|  | ColumnAutoincrement | The column will automatically be incremented. The number is an increasing number, and is guaranteed to be unique within a table. The numbers, however, might not be continuous. For example, if five rows are inserted into a table, the "autoincrement" column could contain the values { 1, 2, 6, 7, 8 }. This bit can only be used on columns of type JET_coltyp.Long or JET_coltyp.Currency. |
|  | ColumnMultiValued | The column can be multi-valued. A multi-valued column can have zero, one, or more values associated with it. The various values in a multi-valued column are identified by a number called the itagSequence member, which belongs to various structures, including: JET_RETINFO, JET_SETINFO, JET_SETCOLUMN, JET_RETRIEVECOLUMN, and JET_ENUMCOLUMNVALUE. Multi-valued columns must be tagged columns; that is, they cannot be fixed-length or variable-length columns. |
|  | ColumnEscrowUpdate | Specifies that a column is an escrow update column. An escrow update column can be updated concurrently by different sessions with JetEscrowUpdate and will maintain transactional consistency. An escrow update column must also meet the following conditions: An escrow update column can be created only when the table is empty. An escrow update column must be of type JET_coltypLong. An escrow update column must have a default value. JET_bitColumnEscrowUpdate cannot be used in conjunction with ColumnTagged, ColumnVersion, or ColumnAutoincrement. |
|  | ColumnUnversioned | The column will be created in an without version information. This means that other transactions that attempt to add a column with the same name will fail. This bit is only useful with JetAddColumn. It cannot be used within a transaction. |
|  | ColumnMaybeNull | In doing an outer join, the retrieve column operation might not have a match from the inner table. |
|  | ColumnUserDefinedDefault | The default value for a column will be provided by a callback function. A column that has a user-defined default must be a tagged column. Specifying JET_bitColumnUserDefinedDefault means that pvDefault must point to a JET_USERDEFINEDDEFAULT structure, and cbDefault must be set to sizeof( JET_USERDEFINEDDEFAULT ). |
|  | TTKey | The column will be a key column for the temporary table. The order of the column definitions with this option specified in the input array will determine the precedence of each key column for the temporary table. The first column definition in the array that has this option set will be the most significant key column and so on. If more key columns are requested than can be supported by the database engine then this option is ignored for the unsupportable key columns. |
|  | TTDescending | The sort order of the key column for the temporary table should be descending rather than ascending. If this option is specified without TTKey then this option is ignored. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)

[ColumnCompressed](https://learn.microsoft.com/windows/win32/extensible-storage-engine/windows7grbits.columncompressed-field)