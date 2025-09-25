# LoadIconMetric function

## Description

Loads a specified icon resource with a client-specified system metric.

## Parameters

### `hinst` [in]

Type: **[HINSTANCE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the module of either a DLL or executable (.exe) file that contains the icon to be loaded. For more information, see [GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlew).

To load a predefined system icon or a standalone icon file, set this parameter to **NULL**.

### `pszName` [in]

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a null-terminated, Unicode buffer that contains location information about the icon to load.

If *hinst* is non-**NULL**, *pszName* specifies the icon resource either by name or ordinal. This ordinal must be packaged by using the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcew) macro.

If *hinst* is **NULL**, *pszName* specifies the [identifier (beginning with the IDI\_ prefix)](https://learn.microsoft.com/windows/win32/menurc/about-icons) of a predefined system icon to load.

### `lims` [in]

Type: **int**

The desired metric. One of the following values:

| Value | Meaning |
| --- | --- |
| **LIM_SMALL** | Corresponds to [SM_CXSMICON](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics), the recommended pixel width of a small icon. |
| **LIM_LARGE** | Corresponds to [SM_CXICON](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics), the default pixel width of an icon. |

### `phico` [out]

Type: **[HICON](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

When this function returns, contains a pointer to the handle of the loaded icon.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful, otherwise an error, including the following value.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The contents of the buffer pointed to by *pszName* do not fit any of the expected interpretations. |

## Remarks

**LoadIconMetric** is similar to [LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadicona), but with the capability to specify the icon metric. It is used in place of **LoadIcon** when the calling application wants to ensure a high quality icon. This is particularly useful in high dots per inch (dpi) situations.

Icons are extracted or created as follows.

1. If an exact size match is found in the resource, that icon is used.
2. If an exact size match cannot be found and a larger icon is available, a new icon is created by scaling the larger version down to the desired size.
3. If an exact size match cannot be found and no larger icon is available, a new icon is created by scaling a smaller icon up to the desired size.

Comparative calls are shown here for **LoadIconMetric** and [LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadicona).

```cpp
NOTIFYICONDATA  nidIconData  = {0};
nidIconData.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));

// Or...

HRESULT hr = LoadIconMetric(hInstance, MAKEINTRESOURCE(IDI_ICON), LIM_SMALL, &nidIconData.hIcon);
```

The application is responsible for calling [DestroyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyicon) on the retrieved icon.