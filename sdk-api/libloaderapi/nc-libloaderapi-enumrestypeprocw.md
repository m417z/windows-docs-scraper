## Description

An application-defined callback function used with the [EnumResourceTypes](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-enumresourcetypesa) and [EnumResourceTypesEx](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcetypesexa) functions. It receives resource types. The **ENUMRESTYPEPROC** type defines a pointer to this callback function. *EnumResTypeProc* is a placeholder for the application-defined function name.

## Parameters

### `hModule` [in, optional]

Type: **HMODULE**

A handle to the module whose executable file contains the resources for which the types are to be enumerated. If this parameter is **NULL**, the function enumerates the resource types in the module used to create the current process.

### `lpType`

Type: **LPTSTR**

The type of resource for which the type is being enumerated.

Alternately, rather than a pointer, this parameter can be [MAKEINTRESOURCE](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-makeintresourcea)(ID), where ID is the integer identifier of the given resource type. For standard resource types, see [Resource Types](https://learn.microsoft.com/windows/desktop/menurc/resource-types). For more information, see the Remarks section below.

### `lParam` [in]

Type: **LONG_PTR**

An application-defined parameter passed to the [EnumResourceTypes](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-enumresourcetypesa) or [EnumResourceTypesEx](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcetypesexa) function. This parameter can be used in error checking.

## Return value

Type: **BOOL**

Returns **TRUE** to continue enumeration or **FALSE** to stop enumeration.

## Remarks

If [IS_INTRESOURCE](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-is_intresource)(*lpszType*) is **TRUE**, then *lpszType* specifies the integer identifier of the given resource type. Otherwise, it is a pointer to a null-terminated string. If the first character of the string is a pound sign (#), then the remaining characters represent a decimal number that specifies the integer identifier of the resource type. For example, the string "#258" represents the identifier 258.

An application must register this function by passing its address to the [EnumResourceTypes](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-enumresourcetypesa) or [EnumResourceTypesEx](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcetypesexa) function.

If the callback function returns **FALSE**, then [EnumResourceTypes](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-enumresourcetypesa) or [EnumResourceTypesEx](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcetypesexa) will stop enumeration and return **FALSE**. On Windows XP and earlier the value obtained from [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will be **ERROR_SUCCESS**; starting with Windows Vista, the last error value will be **ERROR_RESOURCE_ENUM_USER_STOP**.

> [!NOTE]
> The libloaderapi.h header defines ENUMRESTYPEPROC as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[EnumResourceTypes](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-enumresourcetypesa)

[EnumResourceTypesEx](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcetypesexa)

[IS_INTRESOURCE](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-is_intresource)

**Reference**

[Resources](https://msdn.microsoft.com/ff321356-c999-4021-a537-fbe863996e24)