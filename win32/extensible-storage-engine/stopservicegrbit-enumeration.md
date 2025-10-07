# StopServiceGrbit enumeration

Options for [JetStopServiceInstance2(JET_INSTANCE, StopServiceGrbit)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/windows8api.jetstopserviceinstance2-method).

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop.Windows8](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop.windows8-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum StopServiceGrbit
```

## Members

| Member name | Description |
|-------------|-------------|
| All | Stops all ESE services for the specified instance. |
| BackgroundUserTasks | Stops restartable client specificed background maintenance tasks (B+ Tree Defrag). |
| QuiesceCaches | Quiesces all dirty caches to disk. Asynchronous. Quiescing is cancelled if the Resume bit is called subsequently. |
| Resume | Resumes previously issued StopService operations, i.e. "restarts service". Can be combined with above grbits to Resume specific services, or with 0x0 Resumes all previous stopped services.|

> [!WARNING]
> This bit can only be used to resume JET_bitStopServiceBackground and JET_bitStopServiceQuiesceCaches, if you did a JET_bitStopServiceAll or JET_bitStopServiceAPI, attempting to use JET_bitStopServiceResume will fail.

## See also

#### Reference

[Microsoft.Isam.Esent.Interop.Windows8 namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop.windows8-namespace)