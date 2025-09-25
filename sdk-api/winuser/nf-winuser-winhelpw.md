# WinHelpW function

## Description

Launches Windows Help (Winhelp.exe) and passes additional data that indicates the nature of the help requested by the application.

## Parameters

### `hWndMain`

Type: **HWND**

A handle to the window requesting help. The **WinHelp** function uses this handle to keep track of which applications have requested help. If the *uCommand* parameter specifies **HELP_CONTEXTMENU** or **HELP_WM_HELP**, *hWndMain* identifies the control requesting help.

### `lpszHelp`

Type: **LPCTSTR**

The address of a null-terminated string containing the path, if necessary, and the name of the Help file that **WinHelp** is to display.

The file name can be followed by an angle bracket (>) and the name of a secondary window if the topic is to be displayed in a secondary window rather than in the primary window. You must define the name of the secondary window in the [WINDOWS] section of the Help project (.hpj) file.

### `uCommand`

Type: **UINT**

The type of help requested. For a list of possible values and how they affect the value to place in the *dwData* parameter, see the Remarks section.

### `dwData`

Type: **ULONG_PTR**

Additional data. The value used depends on the value of the *uCommand* parameter. For a list of possible *dwData* values, see the Remarks section.

## Return value

Type: **BOOL**

Returns nonzero if successful, or zero otherwise. To retrieve extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Before closing the window that requested help, the application must call **WinHelp** with the *uCommand* parameter set to HELP_QUIT. Until all applications have done this, Windows Help will not terminate. Note that calling Windows Help with the HELP_QUIT command is not necessary if you used the HELP_CONTEXTPOPUP command to start Windows Help.

This function fails if called from any context but the current user.

The following table shows the possible values for the *uCommand* parameter and the corresponding formats of the *dwData* parameter.

| *uCommand* | Action | *dwData* |
| --- | --- | --- |
| HELP_COMMAND | Executes a Help macro or macro string. | Address of a string that specifies the name of the Help macro(s) to run. If the string specifies multiple macro names, the names must be separated by semicolons. You must use the short form of the macro name for some macros because Windows Help does not support the long name. |
| HELP_CONTENTS | Displays the topic specified by the Contents option in the [OPTIONS] section of the .hpj file. This command is for backward compatibility. New applications should provide a .cnt file and use the HELP_FINDER command. | Ignored; set to 0. |
| HELP_CONTEXT | Displays the topic identified by the specified context identifier defined in the [MAP] section of the .hpj file. | Contains the context identifier for the topic. |
| HELP_CONTEXTMENU | Displays the **Help** menu for the selected window, then displays the topic for the selected control in a pop-up window. | Address of an array of **DWORD** pairs. The first **DWORD** in each pair is the control identifier, and the second is the context identifier for the topic. The array must be terminated by a pair of zeros {0,0}. If you do not want to add Help to a particular control, set its context identifier to -1. |
| HELP_CONTEXTPOPUP | Displays the topic identified by the specified context identifier defined in the [MAP] section of the .hpj file in a pop-up window. | Contains the context identifier for a topic. |
| HELP_FINDER | Displays the Help Topics dialog box. | Ignored; set to 0. |
| HELP_FORCEFILE | Ensures that Windows Help is displaying the correct Help file. If the incorrect Help file is being displayed, Windows Help opens the correct one; otherwise, there is no action. | Ignored; set to 0. |
| HELP_HELPONHELP | Displays help on how to use Windows Help, if the Winhlp32.hlp file is available. | Ignored; set to 0. |
| HELP_INDEX | Displays the topic specified by the Contents option in the [OPTIONS] section of the .hpj file. This command is for backward compatibility. New applications should use the HELP_FINDER command. | Ignored; set to 0. |
| HELP_KEY | Displays the topic in the keyword table that matches the specified keyword, if there is an exact match. If there is more than one match, displays the Index with the topics listed in the **Topics Found** list box. | Address of a keyword string. Multiple keywords must be separated by semicolons. |
| HELP_MULTIKEY | Displays the topic specified by a keyword in an alternative keyword table. | Address of a [MULTIKEYHELP](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-multikeyhelpa) structure that specifies a table footnote character and a keyword. |
| HELP_PARTIALKEY | Displays the topic in the keyword table that matches the specified keyword, if there is an exact match. If there is more than one match, displays the **Topics Found** dialog box. To display the index without passing a keyword, use a pointer to an empty string. | Address of a keyword string. Multiple keywords must be separated by semicolons. |
| HELP_QUIT | Informs Windows Help that it is no longer needed. If no other applications have asked for help, Windows closes Windows Help. | Ignored; set to 0. |
| HELP_SETCONTENTS | Specifies the Contents topic. Windows Help displays this topic when the user clicks the **Contents** button if the Help file does not have an associated .cnt file. | Contains the context identifier for the Contents topic. |
| HELP_SETPOPUP_POS | Sets the position of the subsequent pop-up window. | Contains the position data. Use [MAKELONG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632660(v=vs.85)) to concatenate the horizontal and vertical coordinates into a single value. The pop-up window is positioned as if the mouse cursor were at the specified point when the pop-up window was invoked. |
| HELP_SETWINPOS | Displays the Windows Help window, if it is minimized or in memory, and sets its size and position as specified. | Address of a [HELPWININFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-helpwininfoa) structure that specifies the size and position of either a primary or secondary Help window. |
| HELP_TCARD | Indicates that a command is for a training card instance of Windows Help. Combine this command with other commands using the bitwise OR operator. | Depends on the command with which this command is combined. |
| HELP_WM_HELP | Displays the topic for the control identified by the *hWndMain* parameter in a pop-up window. | Address of an array of **DWORD** pairs. The first **DWORD** in each pair is a control identifier, and the second is a context identifier for a topic. The array must be terminated by a pair of zeros {0,0}. If you do not want to add Help to a particular control, set its context identifier to -1. |

> [!NOTE]
> The winuser.h header defines WinHelp as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[HELPWININFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-helpwininfoa)

[MULTIKEYHELP](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-multikeyhelpa)