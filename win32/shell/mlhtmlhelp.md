# MLHtmlHelp function

\[This function is available through Windows XP and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows.\]

Displays a help window that corresponds to the current UI language setting.

## Parameters

*hwndCaller* \[in\]

Type: **HWND**

A handle to the parent window that calls this function.

*pszFile* \[in\]

Type: **LPCTSTR**

A pointer to a buffer that contains the fully qualified path of a compiled help (.chm) file, or a topic file within a specified help file.

*uCommand* \[in\]

Type: **UINT**

The command to complete. This function directly supports only [HH\_DISPLAY\_TOPIC](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/hh-display-topic-command) and [HH\_DISPLAY\_TEXT\_POPUP](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/hh-display-text-popup-command). In the case of any other command, the call is forwarded without the *dwCrossCodePage* value to [HtmlHelp](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/accessing-the-html-help-api).

*dwData* \[in\]

Type: **DWORD\_PTR**

Any data that may be required, based on the value of the *uCommand* parameter.

*dwCrossCodePage* \[in\]

Type: **DWORD**

The **DWORD** value indicating the code page of the current UI language setting, such as CP\_ACP.

## Return value

Type: **HWND**

Depending on the specified *uCommand* and the result, **MLHtmlHelp** returns one or both of the following:

- The handle (hwnd) of the help window.
- **NULL**. In some cases, **NULL** indicates failure; in other cases, **NULL** indicates that the help window has not yet been created.

## Remarks

If a problem arises with the path of the help file for the current language, the call is forwarded to [HtmlHelp](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/accessing-the-html-help-api) for standard handling.

When the help window is closed, focus returns to the owner unless the owner is the desktop. If *hwndCaller* is the desktop, then the operating system determines where focus is returned.

In addition, if **MLHtmlHelp** sends any notification messages from the help window, the messages are sent to *hwndCaller* as long as you have enabled [notification message](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/about-notification-messages) tracking in the help window definition.

## Examples

The following example calls the [HH\_DISPLAY\_TOPIC](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/hh-display-topic-command) command to open the help file named Help.chm and display its default topic in the help window named `Mainwin`. Generally, the help window specified in this command is a standard [HTML Help Viewer](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/html-help-viewer-topics).

``` syntax
HWND hwnd = HtmlHelp(GetDesktopWindow(),
                     "c:\\Help.chm::/Intro.htm>Mainwin",
                     HH_DISPLAY_TOPIC,
                     NULL,
                     CP_ACP);
```

> [!Note]
> When using this function, set the stack size of the hosting executable to at least 100k. If the defined stack size is too small, then the thread created to run HTML Help will also be created with this stack size, and the operation could fail. Optionally, you can remove /STACK from the link command line, and also remove any STACK setting in the executable's DEF file (default stack size is 1MB in this case). You can also set the stack size using the /Fnumber compiler command (the compiler will pass this to the linker as /STACK).

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional, Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | None |
| DLL<br> | Shlwapi.dll (version 5.0 or later) |
| Unicode and ANSI names<br> | **MLHtmlHelpW** (Unicode) and **MLHtmlHelpA** (ANSI)<br> |

