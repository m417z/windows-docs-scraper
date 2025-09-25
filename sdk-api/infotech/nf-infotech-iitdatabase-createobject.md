# IITDatabase::CreateObject

## Description

Creates an unnamed object you can reference in the future through the **pdwObjInstance* parameter.

## Parameters

### `rclsid` [in]

Class ID for object.

### `pdwObjInstance` [out]

Identifier for object.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The object was successfully created. |
| **E_INVALIDARG** | The argument was not valid. |
| **E_NOTINIT** | The database has not been opened. |
| **E_OUTOFMEMORY** | The memory required for internal structures could not be allocated. |

## See also

[IITDatabase](https://learn.microsoft.com/previous-versions/windows/desktop/api/infotech/nn-infotech-iitdatabase)