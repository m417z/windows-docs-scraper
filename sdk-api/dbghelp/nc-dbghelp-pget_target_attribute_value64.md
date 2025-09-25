# PGET_TARGET_ATTRIBUTE_VALUE64 callback function

## Description

An application-defined callback function used with the [StackWalk2 function](https://learn.microsoft.com/windows/win32/api/dbghelp/nf-dbghelp-stackwalk2). It provides target attribute values which are required for the stack walk.

The **PGET_TARGET_ATTRIBUTE_VALUE64** type defines a pointer to this callback function. **GetTargetAttributeValueProc64** is a placeholder for the application-defined function name.

## Parameters

### `hProcess` [in]

A handle to the process for which the stack trace is generated.

### `Attribute` [in]

A numeric value indicating what atttribute is being requested. Currently defined values are:

| Name | Value |
| ---- | ----- |
| TARGET_ATTRIBUTE_PACMASK (0x01) | Indicates that the stack walker is requesting the ARM64 pointer authentication mask for the process whose stack is being walked. |

If this attribute is being requested, the *AttributeData* parameter will indicate the address for which the PAC mask is being fetched. This allows a differentiation between PAC masks for EL0/1/2 (user mode versus kernel mode, etc...).

If PAC is disabled (or the stack walk is not for an ARM64 platform), the implementation should return FALSE indicating that this attribute cannot be provided.

The special value **TARGET_ATTIBUTE_PACMASK_LIVETARGET** (0xffffffff`ffffffff) may be returned as an indication that the PAC mask is the same as the process calling StackWalk2.

### `AttributeData` [in]

A data value associated with the *Attribute* parameter. The meaning of this parameter varies depending on the attribute being requested.

### `AttributeValue` [out]

The implementation of the callback must place the value of the requested attribute here before returning success.

## Return value

The function returns whether or not the attribute value was successfully stored in the *AttributeValue* output parameter. If the given attribute is not recognized or is irrelevant for the platform in question, the function should return FALSE.

## Remarks

```cpp
typedef
BOOL
(__stdcall *PGET_TARGET_ATTRIBUTE_VALUE64)(
    _In_ HANDLE hProcess,
    _In_ DWORD Attribute,
    _In_ DWORD64 AttributeData,
    _Out_ DWORD64 *AttributeValue
    );
```

## See also

- [DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)
- [StackWalk2 function](https://learn.microsoft.com/windows/win32/api/dbghelp/nf-dbghelp-stackwalk2)