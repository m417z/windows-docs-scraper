# IErrorInfo::GetGUID

## Description

Returns the globally unique identifier (GUID) of the interface that defined the error.

## Parameters

### `pGUID` [out]

A pointer to a GUID, or GUID_NULL, if the error was defined by the operating system.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**IErrorInfo::GetGUID** returns the GUID of the interface that defined the error. If the error was defined by the system, **IErrorInfo::GetGUID** returns GUID_NULL.

This GUID does not necessarily represent the source of the error. The source is the class or application that raised the error. Using the GUID, an application can handle errors in an interface, independent of the class that implements the interface.

## See also

[IErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ierrorinfo)