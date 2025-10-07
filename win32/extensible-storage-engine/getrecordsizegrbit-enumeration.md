# GetRecordSizeGrbit enumeration

Options for [JetGetRecordSize(JET_SESID, JET_TABLEID, JET_RECSIZE, GetRecordSizeGrbit)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/vistaapi.jetgetrecordsize-method).

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum GetRecordSizeGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | InCopyBuffer | Retrieve the size of the record that is in the copy buffer prepared or update. Otherwise, the tableid must be positioned on a record, and that record will be used. |
|  | RunningTotal | The JET_RECSIZE is not zeroed before filling the contents, effectively acting as an accumulation of the statistics for multiple records visited or updated. |
|  | Local | Ignore non-intrinsic Long Values. Only the local record on the page will be used. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)