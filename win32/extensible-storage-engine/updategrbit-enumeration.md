# UpdateGrbit enumeration

Options for [JetUpdate2(JET_SESID, JET_TABLEID, \[\], Int32, Int32, UpdateGrbit)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/server2003api.jetupdate2-method).

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop.Server2003](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop.server2003-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum UpdateGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | CheckESE97Compatibility | **Obsolete.** This flag causes the update to return an error if the update would not have been possible in the Windows 2000 version of ESE, which enforced a smaller maximum number of multi-valued column instances in each record than later versions of ESE. This is important only for applications that wish to replicate data between applications hosted on Windows 2000 and applications hosted on Windows 2003, or later versions of ESE. It should not be necessary for most applications. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop.Server2003 namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop.server2003-namespace)