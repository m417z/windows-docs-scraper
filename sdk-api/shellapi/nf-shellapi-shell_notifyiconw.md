# Shell_NotifyIconW function

## Description

Sends a message to the taskbar's status area.

## Parameters

### `dwMessage` [in]

Type: **DWORD**

A value that specifies the action to be taken by this function. It can have one of the following values:

#### NIM_ADD (0x00000000)

0x00000000. Adds an icon to the status area. The icon is given an identifier in the [NOTIFYICONDATA](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-notifyicondataa) structure pointed to by *lpdata*—either through its **uID** or **guidItem** member. This identifier is used in subsequent calls to **Shell_NotifyIcon** to perform later actions on the icon.

#### NIM_MODIFY (0x00000001)

0x00000001. Modifies an icon in the status area. [NOTIFYICONDATA](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-notifyicondataa) structure pointed to by *lpdata* uses the ID originally assigned to the icon when it was added to the notification area (NIM_ADD) to identify the icon to be modified.

#### NIM_DELETE (0x00000002)

0x00000002. Deletes an icon from the status area. [NOTIFYICONDATA](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-notifyicondataa) structure pointed to by *lpdata* uses the ID originally assigned to the icon when it was added to the notification area (NIM_ADD) to identify the icon to be deleted.

#### NIM_SETFOCUS (0x00000003)

0x00000003. [Shell32.dll version 5.0 and later only](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)). Returns focus to the taskbar notification area. Notification area icons should use this message when they have completed their UI operation. For example, if the icon displays a shortcut menu, but the user presses ESC to cancel it, use **NIM_SETFOCUS** to return focus to the notification area.

#### NIM_SETVERSION (0x00000004)

0x00000004. [Shell32.dll version 5.0 and later only](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)). Instructs the notification area to behave according to the version number specified in the **uVersion** member of the structure pointed to by *lpdata*. The version number specifies which members are recognized.

NIM_SETVERSION must be called every time a notification area icon is added (NIM_ADD). It does not need to be called with NIM_MODIFY. The version setting is not persisted once a user logs off.

For details, see the Remarks section.

### `lpData` [in]

Type: **PNOTIFYICONDATA**

A pointer to a [NOTIFYICONDATA](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-notifyicondataa) structure. The content of the structure depends on the value of *dwMessage*. It can define an icon to add to the notification area, cause that icon to display a notification, or identify an icon to modify or delete.

##### - dwMessage.NIM_ADD (0x00000000)

0x00000000. Adds an icon to the status area. The icon is given an identifier in the [NOTIFYICONDATA](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-notifyicondataa) structure pointed to by *lpdata*—either through its **uID** or **guidItem** member. This identifier is used in subsequent calls to **Shell_NotifyIcon** to perform later actions on the icon.

##### - dwMessage.NIM_DELETE (0x00000002)

0x00000002. Deletes an icon from the status area. [NOTIFYICONDATA](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-notifyicondataa) structure pointed to by *lpdata* uses the ID originally assigned to the icon when it was added to the notification area (NIM_ADD) to identify the icon to be deleted.

##### - dwMessage.NIM_MODIFY (0x00000001)

0x00000001. Modifies an icon in the status area. [NOTIFYICONDATA](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-notifyicondataa) structure pointed to by *lpdata* uses the ID originally assigned to the icon when it was added to the notification area (NIM_ADD) to identify the icon to be modified.

##### - dwMessage.NIM_SETFOCUS (0x00000003)

0x00000003. [Shell32.dll version 5.0 and later only](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)). Returns focus to the taskbar notification area. Notification area icons should use this message when they have completed their UI operation. For example, if the icon displays a shortcut menu, but the user presses ESC to cancel it, use **NIM_SETFOCUS** to return focus to the notification area.

##### - dwMessage.NIM_SETVERSION (0x00000004)

0x00000004. [Shell32.dll version 5.0 and later only](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)). Instructs the notification area to behave according to the version number specified in the **uVersion** member of the structure pointed to by *lpdata*. The version number specifies which members are recognized.

NIM_SETVERSION must be called every time a notification area icon is added (NIM_ADD)>. It does not need to be called with NIM_MODIFY. The version setting is not persisted once a user logs off.

For details, see the Remarks section.

## Return value

Type: **BOOL**

Returns **TRUE** if successful, or **FALSE** otherwise. If *dwMessage* is set to NIM_SETVERSION, the function returns **TRUE** if the version was successfully changed, or **FALSE** if the requested version is not supported.

## Remarks

As of Windows 2000 ([Shell32.dll version 5.0](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85))), if you set the **uVersion** member of the [NOTIFYICONDATA](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-notifyicondataa) structure pointed to by *lpdata* to NOTIFYICON_VERSION_4 or higher, **Shell_NotifyIcon** mouse and keyboard events are handled differently than in earlier versions of Windows. The differences include the following:

* If a user selects a notify icon's shortcut menu with the keyboard, the Shell now sends the associated application a [WM_CONTEXTMENU](https://learn.microsoft.com/windows/desktop/menurc/wm-contextmenu) message. Earlier versions send [WM_RBUTTONDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-rbuttondown) and [WM_RBUTTONUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-rbuttonup) messages.
* If a user selects a notify icon with the keyboard and activates it with the SPACEBAR or ENTER key, the version 5.0 Shell sends the associated application an NIN_KEYSELECT notification. Earlier versions send [WM_RBUTTONDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-rbuttondown) and [WM_RBUTTONUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-rbuttonup) messages.
* If a user selects a notify icon with the mouse and activates it with the ENTER key, the Shell now sends the associated application an NIN_SELECT notification. Earlier versions send [WM_RBUTTONDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-rbuttondown) and [WM_RBUTTONUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-rbuttonup) messages.

As of Windows XP ([Shell32.dll version 6.0](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85))), if a user passes the mouse pointer over an icon with which a balloon notification is associated, the Shell sends the following messages:

* NIN_BALLOONSHOW. Sent when the balloon is shown (balloons are queued).
* NIN_BALLOONHIDE. Sent when the balloon disappears. For example, when the icon is deleted. This message is not sent if the balloon is dismissed because of a timeout or if the user clicks the mouse.

  As of Windows 7, NIN_BALLOONHIDE is also sent when a notification with the [NIIF_RESPECT_QUIET_TIME](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-notifyicondataa) flag set attempts to display during quiet time (a user's first hour on a new computer). In that case, the balloon is never displayed at all.
* NIN_BALLOONTIMEOUT. Sent when the balloon is dismissed because of a timeout.
* NIN_BALLOONUSERCLICK. Sent when the balloon is dismissed because the user clicked the mouse.

In addition to those messages, as of Windows Vista (Shell32.dll version 6.0.6), if a user passes the mouse pointer over an icon with which a balloon notification is associated, the Windows Vista Shell also adds the following messages:

* NIN_POPUPOPEN. Sent when the user hovers the cursor over an icon to indicate that the richer pop-up UI should be used in place of a standard textual tooltip.
* NIN_POPUPCLOSE. Sent when a cursor no longer hovers over an icon to indicate that the rich pop-up UI should be closed.

Regardless of the operating system version, you can select which way the Shell should behave by calling **Shell_NotifyIcon** with *dwMessage* set to **NIM_SETVERSION**. Set the **uVersion** member of the [NOTIFYICONDATA](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-notifyicondataa) structure pointed to by *lpdata* to indicate whether you want Windows 2000, Windows Vista, or pre-version 5.0 (Windows 95) behavior.

**Note** The messages discussed above are not conventional Windows messages. They are sent as the *lParam* value of the application-defined message that is specified in the **uCallbackMessage** member of the [NOTIFYICONDATA](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-notifyicondataa) structure pointed to by *lpdata*, when **Shell_NotifyIcon** is called with the **NIM_ADD** flag set in *dwMessage*.

As of Windows XP Service Pack 2 (SP2), a custom icon can be displayed in the notification balloon. This allows the calling process to customize the notification beyond the previously available options of info, warning, and error, and distinguish it from other types of notification for the user.

On Windows 10, the balloon messages are shown as banner notifications, which then stay in the Notification Center until dismissed. On Windows 11, the behavior of banner notifications more closely follows the legacy behavior in making them transient. When a bannner notification times out or is otherwise dismissed, it will not be displayed in the Notification Center.

> [!NOTE]
> The shellapi.h header defines Shell_NotifyIcon as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Notifications and the Notification Area](https://learn.microsoft.com/windows/desktop/shell/notification-area)