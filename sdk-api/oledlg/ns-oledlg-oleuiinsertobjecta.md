# OLEUIINSERTOBJECTA structure

## Description

Contains information that the OLE User Interface Library uses to initialize the **Insert Object** dialog box, and space for the library to return information when the dialog box is dismissed.

## Members

### `cbStruct`

The size of the structure, in bytes. This field must be filled on input.

### `dwFlags`

On input, specifies the initialization and creation flags. On exit, specifies the user's choices. It can be a combination of the following flags.

| Value | Meaning |
| --- | --- |
| **IOF_SHOWHELP** | The dialog box will display a **Help** button. |
| **IOF_SELECTCREATENEW** | The **Create New** radio button will initially be checked. This cannot be used with IOF_SELECTCREATEFROMFILE. |
| **IOF_SELECTCREATEFROMFILE** | The **Create From File** radio button will initially be checked. This cannot be used with IOF_SELECTCREATENEW. |
| **IOF_CHECKLINK** | The **Link** check box will initially be checked. |
| **IOF_CHECKDISPLAYASICON** | The **Display As Icon** check box will initially be checked, the current icon will be displayed, and the **Change Icon** button will be enabled. |
| **IOF_CREATENEWOBJECT** | A new object should be created when the user selects **OK** to dismiss the dialog box and the **Create New** radio button was selected. |
| **IOF_CREATEFILEOBJECT** | A new object should be created from the specified file when the user selects **OK** to dismiss the dialog box and the **Create From File** radio button was selected. |
| **IOF_CREATELINKOBJECT** | A new linked object should be created when the user selects **OK** to dismiss the dialog box and the user checked the **Link** check box. |
| **IOF_DISABLELINK** | The **Link** check box will be disabled on initialization. |
| **IOF_VERIFYSERVERSEXIST** | The dialog box should validate the classes it adds to the listbox by ensuring that the server specified in the registration database exists. This is a significant performance factor. |
| **IOF_DISABLEDISPLAYASICON** | The **Display As Icon** check box will be disabled on initialization. |
| **IOF_HIDECHANGEICON** | The **Change Icon** button will be hidden in the **Insert Object** dialog box. |
| **IOF_SHOWINSERTCONTROL** | Displays the **Insert Control** radio button. |
| **IOF_SELECTCREATECONTROL** | Displays the **Create Control** radio button. |

### `hWndOwner`

The window that owns the dialog box. This member should not be **NULL**.

### `lpszCaption`

Pointer to a string to be used as the title of the dialog box. If **NULL**, then the library uses **Insert Object**.

### `lpfnHook`

Pointer to a hook function that processes messages intended for the dialog box. The hook function must return zero to pass a message that it didn't process back to the dialog box procedure in the library. The hook function must return a nonzero value to prevent the library's dialog box procedure from processing a message it has already processed.

### `lCustData`

Application-defined data that the library passes to the hook function pointed to by the **lpfnHook** member. The library passes a pointer to the **OLEUIINSERTOBJECT** structure in the *lParam* parameter of the WM_INITDIALOG message; this pointer can be used to retrieve the **lCustData** member.

### `hInstance`

Instance that contains a dialog box template specified by the **lpTemplateName** member.

### `lpszTemplate`

Pointer to a null-terminated string that specifies the name of the resource file for the dialog box template that is to be substituted for the library's **Insert Object** dialog box template.

### `hResource`

Customized template handle.

### `clsid`

CLSID for class of the object to be inserted. Filled on output.

### `lpszFile`

Pointer to the name of the file to be linked or embedded. Filled on output.

### `cchFile`

Size of **lpszFile** buffer; will not exceed MAX_PATH.

### `cClsidExclude`

Number of CLSIDs included in the **lpClsidExclude** list. Filled on input.

### `lpClsidExclude`

Pointer to a list of CLSIDs to exclude from listing.

### `iid`

Identifier of the requested interface. If [OleUIInsertObject](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuiinsertobjecta) creates the object, then it will return a pointer to this interface. This parameter is ignored if **OleUIInsertObject** does not create the object.

### `oleRender`

Rendering option. If [OleUIInsertObject](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuiinsertobjecta) creates the object, then it selects the rendering option when it creates the object. This parameter is ignored if **OleUIInsertObject** does not create the object.

### `lpFormatEtc`

Desired format. If [OleUIInsertObject](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuiinsertobjecta) creates the object, then it selects the format when it creates the object. This parameter is ignored if **OleUIInsertObject** does not create the object.

### `lpIOleClientSite`

Pointer to the client site to be used for the object. This parameter is ignored if [OleUIInsertObject](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuiinsertobjecta) does not create the object.

### `lpIStorage`

Pointer to the storage to be used for the object. This parameter is ignored if [OleUIInsertObject](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuiinsertobjecta) does not create the object.

### `ppvObj`

Address of output pointer variable that contains the interface pointer for the object being inserted. This parameter is ignored if [OleUIInsertObject](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuiinsertobjecta) does not create the object.

### `sc`

Result of creation calls. This parameter is ignored if [OleUIInsertObject](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuiinsertobjecta) does not create the object.

### `hMetaPict`

MetafilePict structure containing the iconic aspect, if it wasn't placed in the object's cache.

## See also

[OleUIInsertObject](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuiinsertobjecta)

## Remarks

> [!NOTE]
> The oledlg.h header defines OLEUIINSERTOBJECT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).