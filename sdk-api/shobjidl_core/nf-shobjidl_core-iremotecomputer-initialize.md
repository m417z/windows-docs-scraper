# IRemoteComputer::Initialize

## Description

Used by Windows Explorer or Windows Internet Explorer when it is initializing or enumerating a namespace extension invoked on a remote computer.

## Parameters

### `pszMachine`

Type: **LPCWSTR**

A pointer to a buffer containing the machine name of the remote computer.

### `bEnumerating`

Type: **BOOL**

A value that is set to **TRUE** if Windows Explorer is enumerating the namespace extension, or **FALSE** if it is initializing it.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or standard OLE error values otherwise.

## Remarks

If failure is returned, the extension won't appear for the specified computer. Otherwise, the extension will appear and target the remote computer.