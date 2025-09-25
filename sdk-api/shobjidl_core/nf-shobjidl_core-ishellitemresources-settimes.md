# IShellItemResources::SetTimes

## Description

Sets file times.

## Parameters

### `pftCreation` [in]

Type: **const FILETIME***

A pointer to a creation date and time as a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

### `pftWrite` [in]

Type: **const FILETIME***

A pointer to a write date and time as a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

### `pftAccess` [in]

Type: **const FILETIME***

A pointer to an access date and time as a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.