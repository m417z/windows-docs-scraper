# TermGrbit enumeration

Options for [JetTerm2(JET_INSTANCE, TermGrbit)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/api.jetterm2-method).

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum TermGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | Complete | Requests that the instance be shut down cleanly. Any optional cleanup work that would ordinarily be done in the background at run time is completed immediately. |
|  | Abrupt | Requests that the instance be shut down as quickly as possible. Any optional work that would ordinarily be done in the background at run time is abandoned. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)

[Dirty](https://learn.microsoft.com/windows/win32/extensible-storage-engine/windows7grbits.dirty-field)