# ICreateErrorInfo::SetGUID

## Description

Sets the globally unique identifier (GUID) of the interface that defined the error.

## Parameters

### `rguid` [in]

The GUID of the interface that defined the error, or GUID_NULL if the error was defined by the operating system.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

This method sets the GUID of the interface that defined the error. If the error was defined by the system, set **ICreateErrorInfo::SetGUID** to GUID_NULL.

This GUID does not necessarily represent the source of the error; however, the source is the class or application that raised the error. Using the GUID, applications can handle errors in an interface, independent of the class that implements the interface.

Use of this function is demonstrated in the file Main.cpp of the COM Fundamentals Hello sample.

## See also

[ICreateErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreateerrorinfo)