# OpenPersonalTrustDBDialogEx function

## Description

The **OpenPersonalTrustDBDialogEx** function displays the **Certificates** dialog box.

**Note** This function has no associated header file or import library. You must define the function yourself and use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

## Parameters

### `hwndParent` [in, optional]

The handle of the parent window for the dialog box. If this parameter is **NULL**, the dialog box has no parent.

### `dwFlags` [in]

A set of flags that modify the behavior of this function. This can be zero or the following value.

| Value | Meaning |
| --- | --- |
| **WT_TRUSTDBDIALOG_ONLY_PUB_TAB_FLAG**<br><br>2 (0x2) | Only display the **Trusted Publisher** tab. By default, all of the user interface tabs are displayed and the **Trusted Publisher** tab is initially selected. |

### `pvReserved` [in, out, optional]

Not used. Must be **NULL**.

## Return value

Returns nonzero if the dialog box was opened successfully or zero otherwise.

## See also

[OpenPersonalTrustDBDialog](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-openpersonaltrustdbdialog)