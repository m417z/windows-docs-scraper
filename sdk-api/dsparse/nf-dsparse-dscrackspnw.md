# DsCrackSpnW function

## Description

The **DsCrackSpn** function parses a service principal name (SPN) into its component strings.

## Parameters

### `pszSpn` [in]

Pointer to a constant null-terminated string that contains the SPN to parse. The SPN has the following format, in which the <service class> and <instance name> components must be present and the <port number> and <service name> components are optional. The <port number> component must be a numeric string value.

```cpp
<service class>/<instance name>:<port number>/<service name>
```

### `pcServiceClass` [in, out, optional]

Pointer to a **DWORD** value that, on entry, contains the size, in **TCHARs**, of the *ServiceClass* buffer, including the terminating null character. On exit, this parameter contains the number of **TCHARs** in the *ServiceClass* string, including the terminating null character.

If this parameter is **NULL**, contains zero, or *ServiceClass* is **NULL**, this parameter and *ServiceClass* are ignored.

To obtain the number of characters required for the *ServiceClass* string, including the null terminator, call this function with a valid SPN, a non-**NULL** *ServiceClass* and this parameter set to 1.

### `ServiceClass` [out, optional]

Pointer to a **TCHAR** buffer that receives a null-terminated string containing the <service class> component of the SPN. This buffer must be at least **pcServiceClass* **TCHARs** in size. This parameter may be **NULL** if the service class is not required.

### `pcServiceName` [in, out, optional]

Pointer to a **DWORD** value that, on entry, contains the size, in **TCHARs**, of the *ServiceName* buffer, including the terminating null character. On exit, this parameter contains the number of **TCHARs** in the *ServiceName* string, including the terminating null character.

If this parameter is **NULL**, contains zero, or *ServiceName* is **NULL**, this parameter and *ServiceName* are ignored.

To obtain the number of characters required for the *ServiceName* string, including the null terminator, call this function with a valid SPN, a non-**NULL** *ServiceName* and this parameter set to 1.

### `ServiceName` [out, optional]

Pointer to a **TCHAR** buffer that receives a null-terminated string containing the <service name> component of the SPN. This buffer must be at least **pcServiceName* **TCHARs** in size. If the <service name> component is not present in the SPN, this buffer receives the <instance name> component. This parameter may be **NULL** if the service name is not required.

### `pcInstanceName` [in, out, optional]

Pointer to a **DWORD** value that, on entry, contains the size, in **TCHARs**, of the *InstanceName* buffer, including the terminating null character. On exit, this parameter contains the number of **TCHARs** in the *InstanceName* string, including the terminating null character.

If this parameter is **NULL**, contains zero, or *InstanceName* is **NULL**, this parameter and *InstanceName* are ignored.

To obtain the number of characters required for the *InstanceName* string, including the null terminator, call this function with a valid SPN, a non-**NULL** *InstanceName* and this parameter set to 1.

### `InstanceName` [out, optional]

Pointer to a **TCHAR** buffer that receives a null-terminated string containing the <instance name> component of the SPN. This buffer must be at least **pcInstanceName*  **TCHARs** in size. This parameter may be **NULL** if the instance name is not required.

### `pInstancePort` [out, optional]

Pointer to a **DWORD** value that receives the integer value of the <port number> component of the SPN. If the SPN does not contain a <port number> component, this parameter receives zero. This parameter may be **NULL** if the port number is not required.

## Return value

Returns a Win32 error code, including the following.

## See also

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

## Remarks

> [!NOTE]
> The dsparse.h header defines DsCrackSpn as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).