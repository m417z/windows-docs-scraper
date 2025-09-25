# IUserNotification::SetBalloonInfo

## Description

Sets the information to be displayed in a balloon notification.

## Parameters

### `pszTitle` [in]

Type: **LPCWSTR**

A pointer to a Unicode string that specifies the title of the notification.

### `pszText` [in]

Type: **LPCWSTR**

A pointer to a Unicode string that specifies the text to be displayed in the body of the balloon.

### `dwInfoFlags` [in]

Type: **DWORD**

One or more of the following values that indicate an icon to display in the notification balloon.

#### NIIF_NONE (0x00000000)

0x00000000. Do not display an icon.

#### NIIF_INFO (0x00000001)

0x00000001. Display an information icon.

#### NIIF_WARNING (0x00000002)

0x00000002. Display a warning icon.

#### NIIF_ERROR (0x00000003)

0x00000003. Display an error icon.

#### NIIF_USER (0x00000004)

0x00000004. **Windows XP SP2 and later**. Use the icon identified in **hIcon** in the notification balloon.

#### NIIF_NOSOUND (0x00000010)

0x00000010. **Windows XP and later**. Do not play the associated sound. This value applies only to balloon notifications and not to standard user notifications.

#### NIIF_LARGE_ICON (0x00000010)

0x00000010. **Windows Vista and later**. The large version of the icon should be used as the icon in the notification balloon. This corresponds to the icon with dimensions SM_CXICON x SM_CYICON. If this flag is not set, the icon with dimensions XM_CXSMICON x SM_CYSMICON is used.

* This flag can be used with all [stock icons](https://learn.microsoft.com/windows/desktop/api/shellapi/ne-shellapi-shstockiconid).
* Applications that use older customized icons (NIIF_USER with **hIcon**) must provide a new SM_CXICON x SM_CYICON version in the tray icon specified in the **hIcon** member of the [NOTIFYICONDATA](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-notifyicondataa) structure. These icons are scaled down when they are displayed in the notification area.
* New customized icons (NIIF_USER with **hBalloonIcon**) must supply an SM_CXICON x SM_CYICON version in the supplied icon (**hBalloonIcon**).

#### NIIF_RESPECT_QUIET_TIME (0x00000080)

0x00000080. **Windows 7 and later**. Do not display the notification balloon if the current user is in "quiet time", which is the first hour after a new user logs into his or her account for the first time. During this time, most notifications should not be sent or shown. This lets a user become accustomed to a new computer system without those distractions. Quiet time also occurs for each user after an operating system upgrade or clean installation. A notification sent with this flag during quiet time is not queued; it is simply dismissed unshown. The application can resend the notification later if it is still valid at that time.

Because an application cannot predict when it might encounter quiet time, we recommended that this flag always be set on all appropriate notifications by any application that means to honor quiet time.

If the current user is not in quiet time, this flag has no effect.

#### NIIF_ICON_MASK (0x0000000F)

0x0000000F. **Windows XP** ([Shell32.dll version 6.0](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85))**) and later**. Reserved.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.