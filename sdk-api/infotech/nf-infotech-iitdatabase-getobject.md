# IITDatabase::GetObject

## Description

Retrieves a specified [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)-based interface on the object identified by the *dwObjInstance* parameter.

## Parameters

### `dwObjInstance` [in]

Identifier for object.

### `riid` [in]

### `ppvObj` [out]

Interface ID requested.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation completed successfully. |
| **E_INVALIDARG** | The argument was not valid. |
| **E_NOTINIT** | The database has not been opened. |
| **E_OUTOFMEMORY** | The memory required for internal structures could not be allocated. |

## See also

[IITDatabase](https://learn.microsoft.com/previous-versions/windows/desktop/api/infotech/nn-infotech-iitdatabase)