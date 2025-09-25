# IRichEditOleCallback::QueryInsertObject

## Description

Queries the application as to whether an object should be inserted. The member is called when pasting and when reading Rich Text Format (RTF).

## Parameters

### `lpclsid`

Type: **LPCLSID**

Class identifier of the object to be inserted.

### `lpstg`

Type: **LPSTORAGE**

Storage containing the object.

### `cp`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Character position, at which the object will be inserted.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK on success. If the return value is not S_OK, the object was not inserted. If the method fails, it can return the following value.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | There was an invalid argument. |

## See also

[IRichEditOleCallback](https://learn.microsoft.com/windows/desktop/api/richole/nn-richole-iricheditolecallback)