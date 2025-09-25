# IDebugSymbols3::GetTypeIdWide

## Description

The **GetTypeIdWide** method looks up the specified type and return its type ID.

## Parameters

### `Module` [in]

Specifies the base address of the module to which the type belongs. For more information, see [Modules](https://learn.microsoft.com/windows-hardware/drivers/debugger/modules). If *Name* contains a module name, *Module* is ignored.

### `Name` [in]

Specifies the name of the type whose type ID is desired. If *Name* is a module-qualified name (for example **mymodule!main**), the *Module* parameter is ignored.

### `TypeId` [out]

Receives the type ID of the symbol.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

If the specified symbol is a type, these methods return the type ID for that type; otherwise, they return the type ID for the type of the symbol.

A variable whose type was defined using **typedef** has a type ID that identifies the original type, not the type created by **typedef**. In the following example, the type ID of **MyInstance** corresponds to the name **MyStruct** (this correspondence can be seen by passing the type ID to [GetTypeName](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-gettypename)):

```
struct MyStruct { int a; };
typedef struct MyStruct MyType;
MyType MyInstance;
```

Moreover, calling these methods for **MyStruct** and **MyType** yields type IDs corresponding to **MyStruct** and **MyType**, respectively.

For more information about symbols and symbol names, see [Symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4).

## See also

[GetOffsetTypeId](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getoffsettypeid)

[GetSymbolTypeId](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getsymboltypeid)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)