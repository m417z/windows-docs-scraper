# SetColumnGrbit enumeration

Options for JetSetColumn.

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum SetColumnGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | AppendLV | This option is used to append data to a column of type JET_coltypLongText or JET_coltypLongBinary. The same behavior can be achieved by determining the size of the existing long value and specifying ibLongValue in psetinfo. However, its simpler to use this grbit since knowing the size of the existing column value is not necessary. |
|  | OverwriteLV | This option is used replace the existing long value with the newly provided data. When this option is used, it is as though the existing long value has been set to 0 (zero) length prior to setting the new data. |
|  | RevertToDefaultValue | This option is only applicable for tagged, sparse or multi-valued columns. It causes the column to return the default column value on subsequent retrieve column operations. All existing column values are removed. |
|  | SeparateLV | This option is used to force a long value, columns of type JET_coltyp.LongText or JET_coltyp.LongBinary, to be stored separately from the remainder of record data. This occurs normally when the size of the long value prevents it from being stored with remaining record data. However, this option can be used to force the long value to be stored separately. Note that long values four bytes in size of smaller cannot be forced to be separate. In such cases, the option is ignored. |
|  | SizeLV | This option is used to interpret the input buffer as an integer number of bytes to set as the length of the long value described by the given columnid and if provided, the sequence number in psetinfo->itagSequence. If the size given is larger than the existing column value, the column will be extended with 0s. If the size is smaller than the existing column value then the value will be truncated. |
|  | UniqueMultiValues | This option is used to enforce that all values in a multi-valued column are distinct. This option compares the source column data, without any transformations, to other existing column values and an error is returned if a duplicate is found. If this option is given, then AppendLV, OverwriteLV and SizeLV cannot also be given. |
|  | UniqueNormalizedMultiValues | This option is used to enforce that all values in a multi-valued column are distinct. This option compares the key normalized transformation of column data, to other similarly transformed existing column values and an error is returned if a duplicate is found. If this option is given, then AppendLV, OverwriteLV and SizeLV cannot also be given. |
|  | ZeroLength | This option is used to set a value to zero length. Normally, a column value is set to NULL by passing a cbMax of 0 (zero). However, for some types, like JET_coltyp.Text, a column value can be 0 (zero) length instead of NULL, and this option is used to differentiate between NULL and 0 (zero) length. |
|  | IntrinsicLV | Try to store long-value columns in the record, even if they exceed the default separation size. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)

[Compressed](https://learn.microsoft.com/windows/win32/extensible-storage-engine/windows7grbits.compressed-field)

[Uncompressed](https://learn.microsoft.com/windows/win32/extensible-storage-engine/windows7grbits.uncompressed-field)