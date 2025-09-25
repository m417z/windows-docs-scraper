# IShellLinkA::GetIDList

## Description

Gets the list of item identifiers for the target of a Shell link object.

## Parameters

### `ppidl` [out]

Type: **PIDLIST_ABSOLUTE***

When this method returns, contains the address of a PIDL.

## Return value

Type: **HRESULT**

Returns S_OK if the operation is successful and one or more valid PIDLs is retrieved. If the operation is successful but no PIDLs are retrieved, it returns S_FALSE with *ppidl* set to **NULL**. Otherwise, it returns a standard error value.