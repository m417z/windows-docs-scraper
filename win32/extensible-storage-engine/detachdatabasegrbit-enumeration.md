# DetachDatabaseGrbit enumeration

Options for [JetDetachDatabase2(JET_SESID, String, DetachDatabaseGrbit)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/api.jetdetachdatabase2-method).

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum DetachDatabaseGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | ForceDetach | **Obsolete.** If ForceDetach is used, [EsentForceDetachNotAllowedException](https://learn.microsoft.com/windows/win32/extensible-storage-engine/dn350463(v=exchg.10).md) will be returned. |
|  | ForceClose | **Obsolete.** ForceClose is no longer used. |
|  | ForceCloseAndDetach | **Obsolete.** If ForceCloseAndDetach is used, [EsentForceDetachNotAllowedException](https://learn.microsoft.com/windows/win32/extensible-storage-engine/dn350463(v=exchg.10).md) will be returned. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)