# ZwDeleteFile function

## Description

The **ZwDeleteFile** routine deletes the specified file.

## Parameters

### `ObjectAttributes` [in]

A pointer to an [**OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that contains the attributes supplied by the caller to be used for the file object. These attributes would include the **ObjectName** and the [**SECURITY_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor), for example. This parameter is initialized by calling the [**InitializeObjectAttributes**](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) macro.

## Return value

**ZwDeleteFile** returns STATUS_SUCCESS or an appropriate error status representing the final completion status of the operation. Possible error status codes include the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_INSUFFICIENT_RESOURCES | A temporary buffer required by this function could not be allocated. |
| STATUS_INVALID_PARAMETER | The specified **ObjectAttributes** parameter was a NULL pointer, not a valid pointer to an **OBJECT_ATTRIBUTES** structure, or some of the specified **ObjectAttributes** structure members were invalid. |
| STATUS_OBJECT_NAME_INVALID | The **ObjectAttributes** parameter contained an **ObjectName** in the **OBJECT_ATTRIBUTES** structure that was invalid because an empty string was found after the OBJECT_NAME_PATH_SEPARATOR character. |
| STATUS_OBJECT_NAME_NOT_FOUND | The **ObjectAttributes** parameter contained an **ObjectName** member in the **OBJECT_ATTRIBUTES** structure that could not be found. |
| STATUS_OBJECT_PATH_NOT_FOUND | The **ObjectAttributes** parameter contained an **ObjectName** member in the **OBJECT_ATTRIBUTES** structure with an object path that could not be found. |
| STATUS_OBJECT_PATH_SYNTAX_BAD | The **ObjectAttributes** parameter did not contain a **RootDirectory** member, but the **ObjectName** member in the **OBJECT_ATTRIBUTES** structure was an empty string or did not contain an OBJECT_NAME_PATH_SEPARATOR character. This indicates incorrect syntax for the object path. |

## Remarks

**ZwDeleteFile** deletes the specified file object.

The **ZwDeleteFile** function is called after the **InitializeAttributes** macro is used to set attributes in the [**OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure for the file object to be deleted.

There are two alternate ways to specify the name of the file to be deleted with **ZwDeleteFile**:

* As a fully qualified pathname, supplied in the **ObjectName** member of the input **ObjectAttributes**
* As pathname relative to the directory file represented by the handle in the **RootDirectory** member of the input **ObjectAttributes**

Callers of **ZwDeleteFile** must be running at IRQL = PASSIVE_LEVEL and [with special kernel APCs enabled](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

If the call to the **ZwDeleteFile** function occurs in user mode, you should use the name "**NtDeleteFile** " instead of "**ZwDeleteFile**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[**InitializeObjectAttributes**](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[**OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes)