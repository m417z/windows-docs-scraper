## Description

The *QueryRoutine* routine provides information about a registry value that was requested in a preceding call to the [RtlQueryRegistryValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlqueryregistryvalues) routine.

## Parameters

### `ValueName` [in]

Specifies the registry key that is associated with the requested registry value. This parameter is a pointer to a null-terminated, Unicode string that contains the key.

### `ValueType` [in]

Specifies the type of registry value that is stored with the specified registry key. For more information registry value types, see the definition of the *Type* parameter in [KEY_VALUE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_basic_information).

### `ValueData` [in]

A pointer to the data value that is associated with the specified registry key. The driver must treat this value as read-only. For more information about the type of value data that *ValueData* points to, see the definition of the *Type* parameter in [**KEY_VALUE_BASIC_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_basic_information).

### `ValueLength` [in]

Specifies the length, in bytes, of the value that *ValueData* points to.

### `Context` [in, optional]

Specifies the *Context* parameter value that the driver specified in the preceding call to **RtlQueryRegistryValues**.

### `EntryContext` [in, optional]

Specifies an **EntryContext** value in a *QueryTable* array element that the driver specified in the preceding call to **RtlQueryRegistryValues**.

## Return value

*QueryRoutine* returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error status code. Use only status codes that are defined in the Ntstatus.h header file.

## Remarks

A kernel-mode driver implements a *QueryRoutine* routine. This routine is called by the [RtlQueryRegistryValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlqueryregistryvalues) routine.

To obtain information about one or more registry values, the driver calls **RtlQueryRegistryValues** and passes a pointer, as an input parameter, to an array of **RTL_QUERY_REGISTRY_TABLE** structures. Each structure in this array contains a pointer to a driver-implemented *QueryRoutine* routine and a request for information about a particular registry value. For each structure in the array, **RtlQueryRegistryValues** calls the specified *QueryRoutine* routine and passes to this routine a set of parameters that contain the requested information about the specified registry value.

For more information about the **RTL_QUERY_REGISTRY_TABLE** structure, see [RtlQueryRegistryValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlqueryregistryvalues).

### Examples

To define a *QueryRoutine* callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *QueryRoutine* callback routine that is named `MyQueryRoutine`, use the RTL_QUERY_REGISTRY_ROUTINE type as shown in this code example:

```cpp
RTL_QUERY_REGISTRY_ROUTINE MyQueryRoutine;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
NTSTATUS
  MyQueryRoutine(
    PWSTR ValueName,
    ULONG ValueType,
    PVOID ValueData,
    ULONG ValueLength,
    PVOID Context,
    PVOID EntryContext
    )
  {
      // Function body
  }
```

The RTL_QUERY_REGISTRY_ROUTINE function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the RTL_QUERY_REGISTRY_ROUTINE function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[**KEY_VALUE_BASIC_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_basic_information)

[RtlQueryRegistryValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlqueryregistryvalues)