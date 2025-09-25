# IShellItemResources::GetTimes

## Description

Gets file times.

## Parameters

### `pftCreation` [out]

Type: **FILETIME***

A pointer to the creation date and time as a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

### `pftWrite` [out]

Type: **FILETIME***

A pointer to write date and time as a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

### `pftAccess` [out]

Type: **FILETIME***

A pointer to access date and time as a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.