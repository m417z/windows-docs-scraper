# JET_cbtyp enumeration

Type of progress being reported.

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum JET_cbtyp
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | Null | This callback is reserved and always considered invalid. |
|  | Finalize | A finalizable column has gone to zero. |
|  | BeforeInsert | This callback will occur just before a new record is inserted into a table by a call to JetUpdate. |
|  | AfterInsert | This callback will occur just after a new record has been inserted into a table by a call to JetUpdate but before JetUpdate returns. |
|  | BeforeReplace | This callback will occur just prior to an existing record in a table being changed by a call to JetUpdate. |
|  | AfterReplace | This callback will occur just after an existing record in a table has been changed by a call to JetUpdate but prior to JetUpdate returning. |
|  | BeforeDelete | This callback will occur just before an existing record in a table is deleted by a call to JetDelete. |
|  | AfterDelete | This callback will occur just after an existing record in a table is deleted by a call to JetDelete. |
|  | UserDefinedDefaultValue | This callback will occur when the engine needs to retrieve the user defined default value of a column from the application. This callback is essentially a limited implementation of JetRetrieveColumn that is evaluated by the application. A maximum of one column value can be returned for a user defined default value. |
|  | OnlineDefragCompleted | This callback will occur when the online defragmentation of a database as initiated by JetDefragment has stopped due to either the process being completed or the time limit being reached. |
|  | FreeCursorLS | This callback will occur when the application needs to clean up the context handle for the Local Storage associated with a cursor that is being released by the database engine. For more information, see JetSetLS. The delegate for this callback reason is configured by means of JetSetSystemParameter with JET_paramRuntimeCallback. |
|  | FreeTableLS | This callback will occur as the result of the need for the application to cleanup the context handle for the Local Storage associated with a table that is being released by the database engine. For more information, see JetSetLS. The delegate for this callback reason is configured by means of JetSetSystemParameter with JET_paramRuntimeCallback. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)