# RegQueryValueExA function

## Description

Retrieves the type and data for the specified value name associated with an open registry key.

> [!WARNING]
> If the value being queried is a string (REG_SZ, REG_MULTI_SZ, and REG_EXPAND_SZ) the value returned is NOT guaranteed to be null-terminated. Use the [RegGetValue](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-reggetvaluea) function if you want to ensure returned string values are null-terminated. More information is in the remarks below.

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

**HKEY_PERFORMANCE_NLSTEXT**

**HKEY_PERFORMANCE_TEXT**

**HKEY_USERS**

### `lpValueName` [in, optional]

The name of the registry value.

If *lpValueName* is **NULL** or an empty string, "", the function retrieves the type and data for the key's unnamed or default value, if any.

If *lpValueName* specifies a value that is not in the registry, the function returns ERROR_FILE_NOT_FOUND.

Keys do not automatically have an unnamed or default value. Unnamed values can be of any type. For more information, see
[Registry Element Size Limits](https://learn.microsoft.com/windows/desktop/SysInfo/registry-element-size-limits).

### `lpReserved`

This parameter is reserved and must be **NULL**.

### `lpType` [out, optional]

A pointer to a variable that receives a code indicating the type of data stored in the specified value. For a list of the possible type codes, see
[Registry Value Types](https://learn.microsoft.com/windows/desktop/SysInfo/registry-value-types). The *lpType* parameter can be **NULL** if the type code is not required.

### `lpData` [out, optional]

A pointer to a buffer that receives the value's data. This parameter can be **NULL** if the data is not required.

### `lpcbData` [in, out, optional]

A pointer to a variable that specifies the size of the buffer pointed to by the *lpData* parameter, in bytes. When the function returns, this variable contains the size of the data copied to *lpData*.

The *lpcbData* parameter can be **NULL** only if *lpData* is **NULL**.

If the data has the REG_SZ, REG_MULTI_SZ or REG_EXPAND_SZ type, this size includes any terminating **null** character or characters unless the data was stored without them. For more information, see Remarks.

If the buffer specified by *lpData* parameter is not large enough to hold the data, the function returns ERROR_MORE_DATA and stores the required buffer size in the variable pointed to by *lpcbData*. In this case, the contents of the *lpData* buffer are undefined.

If *lpData* is **NULL**, and *lpcbData* is non-**NULL**, the function returns ERROR_SUCCESS and stores the size of the data, in bytes, in the variable pointed to by *lpcbData*. This enables an application to determine the best way to allocate a buffer for the value's data.

If *hKey* specifies **HKEY_PERFORMANCE_DATA** and the *lpData* buffer is not large enough to contain all of the returned data,
**RegQueryValueEx** returns ERROR_MORE_DATA and the value returned through the *lpcbData* parameter is undefined. This is because the size of the performance data can change from one call to the next. In this case, you must increase the buffer size and call
**RegQueryValueEx** again passing the updated buffer size in the *lpcbData* parameter. Repeat this until the function succeeds. You need to maintain a separate variable to keep track of the buffer size, because the value returned by *lpcbData* is unpredictable.

If the *lpValueName* registry value does not exist, **RegQueryValueEx** returns ERROR_FILE_NOT_FOUND and the value returned through the *lpcbData* parameter is undefined.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

If the *lpData* buffer is too small to receive the data, the function returns ERROR_MORE_DATA.

If the *lpValueName* registry value does not exist, the function returns ERROR_FILE_NOT_FOUND.

## Remarks

An application typically calls [RegEnumValue](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regenumvaluea) to determine the value names and then **RegQueryValueEx** to retrieve the data for the names.

If the data has the REG_SZ, REG_MULTI_SZ or REG_EXPAND_SZ type, the string may not have been stored with the proper terminating **null** characters. Therefore, even if the function returns ERROR_SUCCESS, the application should ensure that the string is properly terminated before using it; otherwise, it may overwrite a buffer. (Note that REG_MULTI_SZ strings should have two terminating **null** characters.) One way an application can ensure that the string is properly terminated is to use [RegGetValue](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-reggetvaluea), which adds terminating **null** characters if needed.

If the data has the REG_SZ, REG_MULTI_SZ or REG_EXPAND_SZ type, and the ANSI version of this function is used (either by explicitly calling **RegQueryValueExA** or by not defining UNICODE before including the Windows.h file), this function converts the stored Unicode string to an ANSI string before copying it to the buffer pointed to by *lpData*.

When calling the
**RegQueryValueEx** function with *hKey* set to the **HKEY_PERFORMANCE_DATA** handle and a value string of a specified object, the returned data structure sometimes has unrequested objects. Do not be surprised; this is normal behavior. When calling the
**RegQueryValueEx** function, you should always expect to walk the returned data structure to look for the requested object.

Note that operations that access certain registry keys are redirected. For more information, see [Registry Virtualization](https://learn.microsoft.com/windows/desktop/SysInfo/registry-virtualization) and [32-bit and 64-bit Application Data in the Registry](https://learn.microsoft.com/windows/desktop/SysInfo/32-bit-and-64-bit-application-data-in-the-registry).

#### Examples

Ensure that you reinitialize the value pointed to by the *lpcbData* parameter each time you call this function. This is very important when you call this function in a loop, as in the following code example.

```cpp
#include <windows.h>
#include <malloc.h>
#include <stdio.h>

#define TOTALBYTES    8192
#define BYTEINCREMENT 4096

void main()
{
    DWORD BufferSize = TOTALBYTES;
    DWORD cbData;
    DWORD dwRet;

    PPERF_DATA_BLOCK PerfData = (PPERF_DATA_BLOCK) malloc( BufferSize );
    cbData = BufferSize;

    printf("\nRetrieving the data...");

    dwRet = RegQueryValueEx( HKEY_PERFORMANCE_DATA,
                             TEXT("Global"),
                             NULL,
                             NULL,
                             (LPBYTE) PerfData,
                             &cbData );
    while( dwRet == ERROR_MORE_DATA )
    {
        // Get a buffer that is big enough.

        BufferSize += BYTEINCREMENT;
        PerfData = (PPERF_DATA_BLOCK) realloc( PerfData, BufferSize );
        cbData = BufferSize;

        printf(".");
        dwRet = RegQueryValueEx( HKEY_PERFORMANCE_DATA,
                         TEXT("Global"),
                         NULL,
                         NULL,
                         (LPBYTE) PerfData,
                         &cbData );
    }
    if( dwRet == ERROR_SUCCESS )
        printf("\n\nFinal buffer size is %d\n", BufferSize);
    else printf("\nRegQueryValueEx failed (%d)\n", dwRet);
}

```

> [!NOTE]
> The winreg.h header defines RegQueryValueEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ExpandEnvironmentStrings](https://learn.microsoft.com/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig)

[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa)

[RegEnumKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regenumkeyexa)

[RegEnumValue](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regenumvaluea)

[RegGetValue](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-reggetvaluea)

[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa)

[RegQueryInfoKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryinfokeya)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)