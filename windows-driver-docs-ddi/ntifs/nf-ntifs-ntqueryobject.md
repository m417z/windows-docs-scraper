# NtQueryObject function

## Description

The **NtQueryObject** routine provides information about a supplied object.

## Parameters

### `Handle` [in, optional]

A handle to the object to obtain information about.

### `ObjectInformationClass` [in]

Specifies an [**OBJECT_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_object_information_class) value that determines the type of information returned in the **ObjectInformation** buffer.

### `ObjectInformation` [out, optional]

A pointer to a caller-allocated buffer that receives the requested information.

### `ObjectInformationLength` [in]

Specifies the size, in bytes, of the **ObjectInformation** buffer.

### `ReturnLength` [out, optional]

A pointer to a variable that receives the size, in bytes, of the requested key information. If **NtQueryObject** returns STATUS_SUCCESS, the variable contains the amount of data returned. If **NtQueryObject** returns STATUS_BUFFER_OVERFLOW or STATUS_BUFFER_TOO_SMALL, you can use the value of the variable to determine the required buffer size.

## Return value

**NtQueryObject** returns STATUS_SUCCESS or an appropriate error status. Possible error status codes include the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_ACCESS_DENIED | There were insufficient permissions to perform this query. |
| STATUS_INVALID_HANDLE | The supplied object handle is invalid. |
| STATUS_INFO_LENGTH_MISMATCH | The info length is not sufficient to hold the data. |

## Remarks

If the call to the **NtQueryObject** function occurs in user mode, you should use the name "**NtQueryObject**" instead of "**ZwQueryObject**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[**OBJECT_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_object_information_class)

[**PUBLIC_OBJECT_BASIC_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_public_object_basic_information)

[**PUBLIC_OBJECT_TYPE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-__public_object_type_information)