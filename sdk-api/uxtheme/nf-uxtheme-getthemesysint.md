# GetThemeSysInt function

## Description

Retrieves the value of a system **int**.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to theme data.

### `iIntId` [in]

Type: **int**

Value of type **int** that specifies the desired system **int**. May be the following value.

| Value | Meaning |
| --- | --- |
| **TMT_MINCOLORDEPTH** | The minimum color depth, in bits, required to properly view this style. |

### `piValue` [in]

Type: **int***

Pointer to an **int** that receives the system integer value.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.