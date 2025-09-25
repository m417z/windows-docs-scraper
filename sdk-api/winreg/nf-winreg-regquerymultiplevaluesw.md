# RegQueryMultipleValuesW function

## Description

Retrieves the type and data for a list of value names associated with an open registry key.

## Parameters

### `hKey` [in]

A handle to an open registry key. The key must have been opened with the KEY_QUERY_VALUE access right. For more information, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

This handle is returned by the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa), [RegCreateKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeytransacteda), [RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa), or
[RegOpenKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeytransacteda) function. It can also be one of the following
[predefined keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys):

**HKEY_CLASSES_ROOT**

**HKEY_CURRENT_CONFIG**

**HKEY_CURRENT_USER**

**HKEY_LOCAL_MACHINE**

**HKEY_PERFORMANCE_DATA**

**HKEY_USERS**

### `val_list` [out]

A pointer to an array of
[VALENT](https://learn.microsoft.com/windows/win32/api/winreg/ns-winreg-valentw) structures that describe one or more value entries. On input, the **ve_valuename** member of each structure must contain a pointer to the name of a value to retrieve. The function fails if any of the specified values do not exist in the specified key.

If the function succeeds, each element of the array contains the information for the specified value.

### `num_vals` [in]

The number of elements in the *val_list* array.

### `lpValueBuf` [out, optional]

A pointer to a buffer. If the function succeeds, the buffer receives the data for each value.

If *lpValueBuf* is **NULL**, the value pointed to by the *ldwTotsize* parameter must be zero, in which case the function returns ERROR_MORE_DATA and *ldwTotsize* receives the required size of the buffer, in bytes.

### `ldwTotsize` [in, out, optional]

A pointer to a variable that specifies the size of the buffer pointed to by the *lpValueBuf* parameter, in bytes. If the function succeeds, *ldwTotsize* receives the number of bytes copied to the buffer. If the function fails because the buffer is too small, *ldwTotsize* receives the required size, in bytes.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_CANTREAD** | [RegQueryMultipleValues](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regquerymultiplevaluesa) cannot instantiate or access the provider of the dynamic key. |
| **ERROR_MORE_DATA** | The buffer pointed to by *lpValueBuf* was too small. In this case, *ldwTotsize* receives the required buffer size. |
| **ERROR_TRANSFER_TOO_LONG** | The total size of the requested data (size of the *val_list* array + *ldwTotSize*) is more than the system limit of one megabyte. |

## Remarks

The
**RegQueryMultipleValues** function allows an application to query one or more values of a static or dynamic key. If the target key is a static key, the system provides all of the values in an atomic fashion. To prevent excessive serialization, the aggregate data returned by the function cannot exceed one megabyte.

If the target key is a dynamic key, its provider must provide all the values in an atomic fashion. This means the provider should fill the results buffer synchronously, providing a consistent view of all the values in the buffer while avoiding excessive serialization. The provider can provide at most one megabyte of total output data during an atomic call to this function.

**RegQueryMultipleValues** is supported remotely; that is, the *hKey* parameter passed to the function can refer to a remote computer.

> [!NOTE]
> The winreg.h header defines RegQueryMultipleValues as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)

[VALENT](https://learn.microsoft.com/windows/win32/api/winreg/ns-winreg-valentw)