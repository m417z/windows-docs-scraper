# GetShortField function

## Description

The **GetShortField** function reads the value of a member in a structure if its size is less than or equal to 8 bytes, or initializes a structure so it can be read later. This function is not intended to be used directly; [InitTypeRead](https://learn.microsoft.com/previous-versions/ff550953(v=vs.85)) or [InitTypeReadPhysical](https://learn.microsoft.com/previous-versions/ff550957(v=vs.85)) and [ReadField](https://learn.microsoft.com/previous-versions/ff553539(v=vs.85)) should be used instead.

## Parameters

### `TypeAddress` [in]

The meaning of this parameter depends on the value of *StoreAddress*.

#### If StoreAddress is non-zero:

Specifies the address of the structure in the target's memory. This address is used for subsequent calls when *StoreAddress* is zero.

#### If StoreAddress is zero:

*TypeAddress* is ignored. The value of *TypeAddress* from the last call when *StoreAddress* was non-zero is used to specify the address of the structure in the target's memory.

### `Name` [in]

The meaning of this parameter depends on the value of *StoreAddress*.

#### If StoreAddress is non-zero:

Specifies the name of the type of the structure at *TypeAddress*.

#### If StoreAddress is zero:

Specifies the name of the member in the structure to read. The address and type of the structure are remembered from a previous call to this function with *StoreAddress* not equal to zero. Submembers can be specified by using a period-separated path, for example, "myfield.mysubfield".

### `StoreAddress` [in]

Specifies the mode of this function.

#### If StoreAddress is non-zero:

Causes this function to initialize a structure for reading its members. The address and type name for the structure is remembered.

If the bit value 0x2 is set in *StoreAddress*, the address *TypeAddress* is considered a physical address; otherwise, it is considered a virtual address.

#### If StoreAddress is zero:

Causes this function to read a member from a previously initialized structure.

## Return value

| Return code | Description |
| --- | --- |
| **If *StoreAddress* is non-zero:** | If the function succeeds, it returns the value zero. If the function fails because the caller passed a zero value as *TypeAddress*, it returns the value MEMORY_READ_ERROR (defined in Wdbgexts.h). If the function fails for any other reason, it returns an [IG_DUMP_SYMBOL_INFO error code](https://learn.microsoft.com/previous-versions/ff550910(v=vs.85)). |
| **If *StoreAddress* is zero:** | If the function succeeds, it returns the value of the specified field in the previously initialized structure. The structure is the one initialized in a previous call to **GetShortField**. The field is the one specified by the *Name* parameter of the current call to **GetShortField**. The return value is cast to ULONG64. If the function fails, it returns the value zero. |

## Remarks

When **GetShortField** is called with a nonzero *StoreAddress* value, it initializes the structure located at the address specified by *TypeAddress*. Only one structure can be initialized at a time. If **GetShortField** is called more than once with a nonzero *StoreAddress* value, only the structure specified in the most recent call is initialized. When **GetShortField** is called with *StoreAddress* equal to zero, it accesses the most recently initialized structure, reads in that structure the field specified by *Name*, and returns the value of that field.

This function does not need to be called directly. The macros [InitTypeRead](https://learn.microsoft.com/previous-versions/ff550953(v=vs.85)) and [InitTypeReadPhysical](https://learn.microsoft.com/previous-versions/ff550957(v=vs.85)) call this function with *StoreAddress* non-zero to prepare a structure for reading its members. The macro [ReadField](https://learn.microsoft.com/previous-versions/ff553539(v=vs.85)) calls this function with *StoreAddress* (and *TypeAddress*) equal to zero, to read members from the structure.

**Note** because this function stores the *TypeAddress* and *Name* by using static local variables, and because this function is defined in WdbgExts.h, the C pre-processor will create a new instance of this function for each DLL, and *TypeAddress* and *Name* will only be available within a single source file. In other words, the structure must be initialized in the same source file from which the members are read.

The **ReadField** and **ReadFieldStr** macros read a field whose size is less than 8 bytes from a structure initialized with [InitTypeRead](https://learn.microsoft.com/previous-versions/ff550953(v=vs.85)) or [InitTypeReadPhysical](https://learn.microsoft.com/previous-versions/ff550957(v=vs.85)).

```
#define ReadField(Field) \
    GetShortField(0, #Field, 0)

#define ReadFieldStr(FieldStr) \
    GetShortField(0, FieldStr, 0)
```

### Parameters

*Field*
*FieldStr*

###

### Return Value

If this macro succeeds, it returns the value of the specified field in the previously initialized structure. The structure is the one initialized in a previous call to [InitTypeRead](https://learn.microsoft.com/previous-versions/ff550953(v=vs.85)), **InitTypeStrRead**, [InitTypeReadPhysical](https://learn.microsoft.com/previous-versions/ff550957(v=vs.85)), **InitTypeStrReadPhysical**, or **GetShortField**. The field is the one specified by the *Field* or *FieldStr* parameter of **ReadField**. The return value is cast to ULONG64. If the function fails, it returns the value zero.

The parameter *Field* is the name of the member. For **ReadField**, the C pre-processor will turn the parameter into a string. For **ReadFieldStr**, *Field* is expected to already be an ASCII string. For example, the following two commands are identical and read the same member from a previously initialized structure:

* ReadField( myField );
* ReadFieldStr( "myField" );

Submembers can be read by using a period-separated path, for example, "myField.mySubfield".

**Note** Because these macros use the **GetShortField** function, they must be called from the same source code file as the macros that initialize the structure for reading. For more details, see **GetShortField**.

If you are writing a WdbgExts extension, include **wdbgexts.h**. If you are writing a DbgEng extension that calls this function, include **wdbgexts.h** before **dbgeng.h** (see [Writing DbgEng Extension Code](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-dbgeng-extension-code) for details).

The [InitTypeRead](https://learn.microsoft.com/previous-versions/ff550953(v=vs.85)) macro initializes a structure so that its members can be read using [ReadField](https://learn.microsoft.com/previous-versions/ff553539(v=vs.85)).

```
#define InitTypeRead(
    Addr,
    Type
);
```

Parameters

*Addr*

Specifies the address of the structure in the target's virtual memory.

*Type*

Specifies the name of the type of the structure. The C pre-processor will turn *Type* into a string.

**Returns value**

If this macro succeeds, it returns the value zero. If it fails because the caller passed a zero value as *Addr*, it returns the value MEMORY_READ_ERROR (defined in Wdbgexts.h). If it fails for any other reason, it returns an [IG_DUMP_SYMBOL_INFO error code](https://learn.microsoft.com/previous-versions/ff550910(v=vs.85)).

The **InitTypeReadPhysical** and **InitTypeStrReadPhysical** macros initialize a structure in physical memory so that its members can be read using [ReadField](https://learn.microsoft.com/previous-versions/ff553539(v=vs.85)).

```
#define InitTypeReadPhysical(
    Addr,
    Type,
    TypeStr
);
```

Parameters

*Addr*

Specifies the address of the structure in the target's physical memory.

*Type*

Specifies the name of the type of the structure. The C pre-processor will turn *Type* into a string.

*TypeStr*

Specifies the name of the type of the structure. *TypeStr* is expected to be an ASCII string.

**Returns value**

If this macro succeeds, it returns the value zero. If it fails because the caller passed a zero value as *Addr*, it returns the value MEMORY_READ_ERROR (defined in Wdbgexts.h). If it fails for any other reason, it returns an [IG_DUMP_SYMBOL_INFO error code](https://learn.microsoft.com/previous-versions/ff550910(v=vs.85)).

The [InitTypeRead](https://learn.microsoft.com/previous-versions/ff550953(v=vs.85)) macro initializes a structure so that its members can be read using [ReadField](https://learn.microsoft.com/previous-versions/ff553539(v=vs.85)).

```
#define InitTypeRead(
    Addr,
    TypeStr
);
```

Parameters

*Addr*

Specifies the address of the structure in the target's virtual memory.

*Type*

Specifies the name of the type of the structure. *TypeStr* is expected to be an ASCII string.

**Returns value**

If this macro succeeds, it returns the value zero. If it fails because the caller passed a zero value as *Addr*, it returns the value MEMORY_READ_ERROR (defined in Wdbgexts.h). If it fails for any other reason, it returns an [IG_DUMP_SYMBOL_INFO error code](https://learn.microsoft.com/previous-versions/ff550910(v=vs.85)).

## See also

[InitTypeRead](https://learn.microsoft.com/previous-versions/ff550953(v=vs.85))

[InitTypeReadPhysical](https://learn.microsoft.com/previous-versions/ff550957(v=vs.85))

[ReadField](https://learn.microsoft.com/previous-versions/ff553539(v=vs.85))