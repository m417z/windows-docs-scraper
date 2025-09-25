# EnableTheming function

## Description

**Windows Vista through Windows 7**: Enables or disables visual styles for the current user in the current and later sessions.

**Windows 8 and later**: This function does nothing. Visual styles are always enabled in Windows 8 and later.

## Parameters

### `fEnable` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Receives one of the following values.

| Value | Meaning |
| --- | --- |
| TRUE | Enables visual styles. If the user previously had an active visual style, it becomes active again.<br><br>**Note** Only clients with trusted computing base (TCB) privileges, where the client acts as part of the operating system, can load or change a global theme. |
| FALSE | Disables visual styles and turns visual styles off. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.