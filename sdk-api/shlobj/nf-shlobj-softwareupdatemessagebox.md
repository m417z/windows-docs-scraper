# SoftwareUpdateMessageBox function

## Description

Displays a standard message box that can be used to notify a user that an application has been updated.

## Parameters

### `hWnd` [in, optional]

Type: **HWND**

A handle to the parent window.

### `pszDistUnit` [in]

Type: **PCWSTR**

The string value containing the identifier for the code distribution unit. For ActiveX controls, *pszDistUnit* is typically a GUID.

### `dwFlags`

Type: **DWORD**

Reserved. Must be set to zero.

### `psdi` [out, optional]

Type: **LPSOFTDISTINFO**

A pointer to a [SOFTDISTINFO](https://learn.microsoft.com/windows/desktop/api/urlmon/ns-urlmon-softdistinfo) structure that, when this method returns successfully, receives the update information. The **cbSize** member must be initialized to the `sizeof(SOFTDISTINFO)`.

## Return value

Type: **DWORD**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **IDNO** | The user clicked the **Do Not Update** button on the dialog box. |
| **IDYES** | The user clicked the **Update Now** or **About Update** button. The application should navigate to the HTML page referred to by the **szHREF** member of the structure pointed to by *psdi*. |
| **IDIGNORE** | There is no pending software update. |
| **IDABORT** | An error occurred. |

## Remarks

The preferred way to handle updates is to author a Channel Definition Format (CDF) with an Open Software Description (OSD) vocabulary and make the shortcut OSD-aware. Refer to the [Channel Definition Format](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768023(v=vs.85)) documentation for details.

The **SoftwareUpdateMessageBox** function is intended to be used in the case where Shell shortcut hooks do not work. One example is an application that was not installed on the start menu. If that application needs to do its own software update check, it should use this function.