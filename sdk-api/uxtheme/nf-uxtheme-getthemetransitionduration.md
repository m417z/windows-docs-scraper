# GetThemeTransitionDuration function

## Description

Gets the duration for the specified transition.

## Parameters

### `hTheme`

Type: **HTHEME**

Handle of the theme data.

### `iPartId`

Type: **int**

ID of the part.

### `iStateIdFrom`

Type: **int**

State ID of the part before the transition.

### `iStateIdTo`

Type: **int**

State ID of the part after the transition.

### `iPropId`

Type: **int**

Property ID.

### `pdwDuration` [out]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Address of a variable that receives the transition duration, in milliseconds.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.