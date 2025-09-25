## Description

An application-defined callback function used with the [EnumResourceNames](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcenamesa) and [EnumResourceNamesEx](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcenamesexa) functions. It receives the type and name of a resource. The **ENUMRESNAMEPROC** type defines a pointer to this callback function. *EnumResNameProc* is a placeholder for the application-defined function name.

## Parameters

### `hModule` [in, optional]

Type: **HMODULE**

A handle to the module whose executable file contains the resources that are being enumerated. If this parameter is **NULL**, the function enumerates the resource names in the module used to create the current process.

### `lpType`

Type: **LPCTSTR**

The type of resource for which the name is being enumerated. Alternately, rather than a pointer, this parameter can be `MAKEINTRESOURCE(ID)`, where ID is an integer value representing a predefined resource type. For standard resource types, see [Resource Types](https://learn.microsoft.com/windows/desktop/menurc/resource-types). For more information, see the Remarks section below.

### `lpName`

Type: **LPTSTR**

The name of a resource of the type being enumerated. Alternately, rather than a pointer, this parameter can be `MAKEINTRESOURCE(ID)`, where ID is the integer identifier of the resource. For more information, see the Remarks section below.

### `lParam` [in]

Type: **LONG_PTR**

An application-defined parameter passed to the [EnumResourceNames](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcenamesa) or [EnumResourceNamesEx](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcenamesexa) function. This parameter can be used in error checking.

## Return value

Type: **BOOL**

Returns **TRUE** to continue enumeration or **FALSE** to stop enumeration.

## Remarks

If [IS_INTRESOURCE](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-is_intresource)(*lpszType*) is **TRUE**, then *lpszType* specifies the integer identifier of the given resource type. Otherwise, it is a pointer to a null-terminated string. If the first character of the string is a pound sign (#), then the remaining characters represent a decimal number that specifies the integer identifier of the resource type. For example, the string "#258" represents the identifier 258.

Similarly, if [IS_INTRESOURCE](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-is_intresource)(*lpszName*) is **TRUE**, then *lpszName* specifies the integer identifier of the given resource. Otherwise, it is a pointer to a null-terminated string. If the first character of the string is a pound sign (#), then the remaining characters represent a decimal number that specifies the integer identifier of the resource.

An application must register this function by passing its address to the [EnumResourceNames](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcenamesa) or [EnumResourceNamesEx](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcenamesexa) function.

If the callback function returns **FALSE**, then [EnumResourceNames](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcenamesa) or [EnumResourceNamesEx](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcenamesexa) will stop enumeration and return **FALSE**. On Windows XP and earlier the value obtained from [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will be **ERROR_SUCCESS**; starting with Windows Vista, the last error value will be **ERROR_RESOURCE_ENUM_USER_STOP**.

> [!NOTE]
> The libloaderapi.h header defines ENUMRESNAMEPROC as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[EnumResourceNames](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcenamesa)

[EnumResourceNamesEx](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcenamesexa)

[IS_INTRESOURCE](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-is_intresource)

**Reference**

[Resources](https://msdn.microsoft.com/ff321356-c999-4021-a537-fbe863996e24)