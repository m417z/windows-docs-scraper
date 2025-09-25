## Description

An application-defined callback function used with the [**EnumResourceLanguagesA**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-enumresourcelanguagesa) and the [**EnumResourceLanguagesExA**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcelanguagesexa) functions. It receives the type, name, and language of a resource item. The **ENUMRESLANGPROC** type defines a pointer to this callback function. *EnumResLangProc* is a placeholder for the application-defined function name.

## Syntax

``` c++
BOOL CALLBACK EnumResLangProc(
  _In_opt_ HMODULE  hModule,
  _In_     LPCSTR  lpszType,
  _In_     LPCSTR  lpszName,
  _In_     WORD     wIDLanguage,
  _In_     LONG_PTR lParam
);
```

## Parameters

### `hModule` [in, optional]

Type: **HMODULE**

A handle to the module whose executable file contains the resources for which the languages are being enumerated. If this parameter is **NULL**, the function enumerates the resource languages in the module used to create the current process.

### `lpType` [in]

Type: **LPCSTR**

The type of resource for which the language is being enumerated. Alternately, rather than a pointer, this parameter can be [**MAKEINTRESOURCE**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-makeintresourcea)(ID), where ID is an integer value representing a predefined resource type. For standard resource types, see [Resource Types](https://learn.microsoft.com/windows/win32/menurc/resource-types). For more information, see the Remarks section below.

### `lpName` [in]

Type: **LPCSTR**

The name of the resource for which the language is being enumerated. Alternately, rather than a pointer, this parameter can be [**MAKEINTRESOURCE**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-makeintresourcea)(ID), where ID is the integer identifier of the resource. For more information, see the Remarks section below.

### `wLanguage` [in]

Type: **WORD**

The language identifier for the resource for which the language is being enumerated. The [**EnumResourceLanguagesA**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-enumresourcelanguagesa) or [**EnumResourceLanguagesExA**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcelanguagesexa) function provides this value. For a list of the primary language identifiers and sublanguage identifiers that constitute a language identifier, see [**MAKELANGID**](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-makelangid).

### `lParam` [in]

Type: **LONG\_PTR**

The application-defined parameter passed to the [**EnumResourceLanguagesA**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-enumresourcelanguagesa) or [**EnumResourceLanguagesExA**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcelanguagesexa) function. This parameter can be used in error checking.

## Return value

Type: **BOOL**

Returns **TRUE** to continue enumeration or **FALSE** to stop enumeration.

## Remarks

If [**IS_INTRESOURCE**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-is_intresource)(*lpszType*) is **TRUE**, then *lpszType* specifies the integer identifier of the given resource type. Otherwise, it is a pointer to a null-terminated string. If the first character of the string is a pound sign (\#), then the remaining characters represent a decimal number that specifies the integer identifier of the resource type. For example, the string "\#258" represents the identifier 258.

Similarly, if [**IS_INTRESOURCE**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-is_intresource)(*lpszName*) is **TRUE**, then *lpszName* specifies the integer identifier of the given resource. Otherwise, it is a pointer to a null-terminated string. If the first character of the string is a pound sign (\#), then the remaining characters represent a decimal number that specifies the integer identifier of the resource.

An application must register this function by passing its address to the [**EnumResourceLanguagesA**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-enumresourcelanguagesa) or [**EnumResourceLanguagesExA**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcelanguagesexa) function.

If the callback function returns **FALSE**, then [**EnumResourceLanguagesA**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-enumresourcelanguagesa) or [**EnumResourceLanguagesExA**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcelanguagesexa) will stop enumeration and return **FALSE**. The value obtained from [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) will be **ERROR\_RESOURCE\_ENUM\_USER\_STOP**.

## See also

[**EnumResourceLanguagesA**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-enumresourcelanguagesa)

[**EnumResourceLanguagesExA**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcelanguagesexa)

[**IS_INTRESOURCE**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-is_intresource)

[**MAKELANGID**](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-makelangid)

[Resources](https://learn.microsoft.com/windows/win32/menurc/resources)