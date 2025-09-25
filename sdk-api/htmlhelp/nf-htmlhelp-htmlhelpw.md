# HtmlHelpW function

## Description

Displays a help window.

Using the API commands, you can specify which topic to display in the help window, whether the help window is a three-pane Help Viewer or a pop-up window, and whether the HTML topic file should be accessed via a context ID, an [HTML Help URL](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/about-html-help-urls), or a Keyword link (KLink) lookup.

## Parameters

### `hwndCaller` [in, optional]

Specifies the handle (*hwnd*) of the window calling **HtmlHelp**. The help window is owned by this window.

When the help window is closed, **HtmlHelp** will return focus to the owner unless the owner is the desktop. If *hwndCaller* is the desktop, then the operating system determines where focus is returned.

In addition, if **HtmlHelp** sends any notification messages from the help window, they are sent to *hwndCaller* as long as you have enabled [notification message](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/about-notification-messages) tracking in the help window definition.

### `pszFile` [in]

Depending on the *uCommand* value, specifies the [file path](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/about-html-help-urls) to either a compiled help (.chm) file, or a topic file within a specified help file.

A [window type](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms644703(v=vs.85)) name can also be specified, preceded with a greater-than (>) character.

If the specified command does not require a file, this value may be NULL.

### `uCommand` [in]

Specifies the [command](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/about-commands) to complete.

### `dwData` [in]

Specifies any data that may be required, based on the value of the *uCommand* parameter.

## Return value

Depending on the specified *uCommand* and the result, **HtmlHelp** returns one or both of the following:

- The handle (hwnd) of the help window.
- `NULL`. In some cases, NULL indicates failure; in other cases, NULL indicates that the help window has not yet been created.

## Remarks

The syntax applies to ANSI character sets. When using a Unicode character set, the type of the *pszFile* parameter should be "LPCTSTR ".

When using the HTML Help API, set the stack size of the hosting executable to at least 100k. If the defined stack size is too small, then the thread created to run HTML Help will also be created with this stack size, and failure could result. Optionally, you can remove /STACK from the link command line, and remove any STACK setting in the executable's DEF file (default stack size is 1MB in this case). You can also you can set the stack size using the /Fnumber compiler command (the compiler will pass this to the linker as /STACK).

#### Examples

The following example calls the [HH_DISPLAY_TOPIC](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/hh-display-topic-command) command to open the help file named Help.chm and display its default topic in the help window named Mainwin. Generally, the help window specified in this command is a standard [HTML Help Viewer](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/about-the-html-help-viewer).

```cpp
HWND hwnd =
   HtmlHelp(
            GetDesktopWindow(),
            "c:\\Help.chm::/Intro.htm>Mainwin",
            HH_DISPLAY_TOPIC,
            NULL) ;
```

> [!NOTE]
> The htmlhelp.h header defines HtmlHelp as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[About the HTML Help API](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/html-help-api-overview)