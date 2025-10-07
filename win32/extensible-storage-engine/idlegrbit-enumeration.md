# IdleGrbit enumeration

Options for [JetIdle(JET_SESID, IdleGrbit)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/api.jetidle-method).

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum IdleGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | FlushBuffers | Triggers cleanup of the version store. |
|  | Compact | Reserved for future use. If this flag is specified, the API will return [InvalidGrbit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/hh564840(v=exchg.10).md). |
|  | GetStatus | Returns [IdleFull](https://learn.microsoft.com/windows/win32/extensible-storage-engine/hh557250(v=exchg.10).md) if version store is more than half full. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)