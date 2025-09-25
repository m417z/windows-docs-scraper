## Description

Contains information that the OLE User Interface Library uses to initialize the **Change Icon** dialog box, and it contains space for the library to return information when the dialog box is dismissed.

## Members

### `cbStruct`

The size of the structure, in bytes. This field must be filled on input.

### `dwFlags`

On input, specifies the initialization and creation flags. On exit, it specifies the user's choices. It can be a combination of the following flags.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **CIF\_SHOWHELP** | Dialog box will display a **Help** button. |
| **CIF\_SELECTCURRENT** | On input, selects the **Current** radio button on initialization. On exit, specifies that the user selected **Current**. |
| **CIF\_SELECTDEFAULT** | On input, selects the **Default** radio button on initialization. On exit, specifies that the user selected **Default**. |
| **CIF\_SELECTFROMFILE** | On input, selects the **From File** radio button on initialization. On exit, specifies that the user selected **From File**. |
| **CIF\_USEICONEXE** | Input only. Extracts the icon from the executable specified in the **szIconExe** member, instead of retrieving it from the class. This is useful for OLE embedding or linking to non-OLE files. |

### `hWndOwner`

The window that owns the dialog box. This member should not be **NULL**.

### `lpszCaption`

Pointer to a string to be used as the title of the dialog box. If **NULL**, then the library uses **Change Icon**.

### `lpfnHook`

Pointer to a hook function that processes messages intended for the dialog box. The hook function must return zero to pass a message that it didn't process back to the dialog box procedure in the library. The hook function must return a nonzero value to prevent the library's dialog box procedure from processing a message it has already processed.

### `lCustData`

Application-defined data that the library passes to the hook function pointed to by the **lpfnHook** member. The library passes a pointer to the **OLEUICHANGEICON** structure in the lParam parameter of the WM\_INITDIALOG message; this pointer can be used to retrieve the **lCustData** member.

### `hInstance`

Instance that contains a dialog box template specified by the **lpTemplateName** member.

### `lpszTemplate`

Pointer to a null-terminated string that specifies the name of the resource file for the dialog box template that is to be substituted for the library's **Change Icon** dialog box template.

### `hResource`

Customized template handle.

### `hMetaPict`

Current and final image. The source of the icon is embedded in the metafile itself.

### `clsid`

Input only. The class to use to get the **Default** icon.

### `szIconExe`

Input only. Pointer to the executable to extract the default icon from. This member is ignored unless CIF\_USEICONEXE is included in the **dwFlags** member and an attempt to retrieve the class icon from the specified CLSID fails.

### `cchIconExe`

Input only. The number of characters in **szIconExe**. This member is ignored unless CIF\_USEICONEXE is included in the **dwFlags** member.

## Remarks

> [!NOTE]
> The oledlg.h header defines OLEUICHANGEICON as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also