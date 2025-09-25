# OLEUIBUSYA structure

## Description

Contains information that the OLE User Interface Library uses to initialize the **Busy** dialog box, and space for the library to return information when the dialog box is dismissed.

## Members

### `cbStruct`

The size of the structure, in bytes. This field must be filled on input.

### `dwFlags`

On input, specifies the initialization and creation flags. On exit, it specifies the user's choices. It may be a combination of the following flags.

| Value | Meaning |
| --- | --- |
| **BZ_DISABLECANCELBUTTON** | This flag disables the **Cancel** button. |
| **BZ_DISABLESWITCHTOBUTTON** | Input only. This flag disables the **Switch To...** button. |
| **BZ_DISABLERETRYBUTTON** | Input only. This flag disables the **Retry** button. |
| **BZ_NOTRESPONDINGDIALOG** | Input only. This flag generates a **Not Responding** dialog box instead of a **Busy** dialog box. The text is slightly different, and the **Cancel** button is disabled. |

### `hWndOwner`

The window that owns the dialog box. This member should not be **NULL**.

### `lpszCaption`

A pointer to a string to be used as the title of the dialog box. If **NULL**, then the library uses **Busy**.

### `lpfnHook`

Pointer to a hook function that processes messages intended for the dialog box. The hook function must return zero to pass a message that it didn't process back to the dialog box procedure in the library. The hook function must return a nonzero value to prevent the library's dialog box procedure from processing a message it has already processed.

### `lCustData`

Application-defined data that the library passes to the hook function pointed to by the **lpfnHook** member. The library passes a pointer to the **OLEUIBUSY** structure in the *lParam* parameter of the WM_INITDIALOG message; this pointer can be used to retrieve the **lCustData** member.

### `hInstance`

Instance that contains a dialog box template specified by the **lpTemplateName** member.

### `lpszTemplate`

Pointer to a null-terminated string that specifies the name of the resource file for the dialog box template that is to be substituted for the library's **Busy** dialog box template.

### `hResource`

Customized template handle.

### `hTask`

Input only. Handle to the task that is blocking.

### `lphWndDialog`

Pointer to the dialog box's **HWND**.

## See also

[OleUIBusy](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuibusya)

## Remarks

> [!NOTE]
> The oledlg.h header defines OLEUIBUSY as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).