# SpaceHintsGrbit enumeration

Options for [JET_SPACEHINTS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-spacehints-class).

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum SpaceHintsGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | SpaceHintUtilizeParentSpace | This changes the internal allocation policy to get space hierarchically from a B-Tree's immediate parent. |
|  | CreateHintAppendSequential | This bit will enable Append split behavior to grow according to the growth dynamics of the table (set by cbMinExtent, ulGrowth, cbMaxExtent). |
|  | CreateHintHotpointSequential | This bit will enable Hotpoint split behavior to grow according to the growth dynamics of the table (set by cbMinExtent, ulGrowth, cbMaxExtent). |
|  | RetrieveHintReserve1 | Reserved and ignored. |
|  | RetrieveHintTableScanForward | By setting this the client indicates that forward sequential scan is the predominant usage pattern of this table. |
|  | RetrieveHintTableScanBackward | By setting this the client indicates that backwards sequential scan is the predominant usage pattern of this table. |
|  | RetrieveHintReserve2 | Reserved and ignored. |
|  | RetrieveHintReserve3 | Reserved and ignored. |
|  | DeleteHintTableSequential | The application expects this table to be cleaned up in-order sequentially (from lowest key to highest key). |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)