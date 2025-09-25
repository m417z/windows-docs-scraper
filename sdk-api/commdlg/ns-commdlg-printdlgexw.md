# PRINTDLGEXW structure

## Description

Contains information that the [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) function uses to initialize the [Print property sheet](https://learn.microsoft.com/windows/desktop/dlgbox/print-property-sheet). After the user closes the property sheet, the system uses this structure to return information about the user's selections.

## Members

### `lStructSize`

Type: **DWORD**

The structure size, in bytes.

### `hwndOwner`

Type: **HWND**

A handle to the window that owns the property sheet. This member must be a valid window handle; it cannot be **NULL**.

### `hDevMode`

Type: **HGLOBAL**

A handle to a movable global memory object that contains a [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure. If **hDevMode** is not **NULL** on input, you must allocate a movable block of memory for the **DEVMODE** structure and initialize its members. The [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) function uses the input data to initialize the controls in the property sheet. When **PrintDlgEx** returns, the **DEVMODE** members indicate the user's input.

If **hDevMode** is **NULL** on input, [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) allocates memory for the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure, initializes its members to indicate the user's input, and returns a handle that identifies it.

For more information about the **hDevMode** and **hDevNames** members, see the Remarks section at the end of this topic.

### `hDevNames`

Type: **HGLOBAL**

A handle to a movable global memory object that contains a [DEVNAMES](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-devnames) structure. If **hDevNames** is not **NULL** on input, you must allocate a movable block of memory for the **DEVNAMES** structure and initialize its members. The [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) function uses the input data to initialize the controls in the property sheet. When **PrintDlgEx** returns, the **DEVNAMES** members contain information for the printer chosen by the user. You can use this information to create a device context or an information context.

The **hDevNames** member can be **NULL**, in which case, [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) allocates memory for the [DEVNAMES](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-devnames) structure, initializes its members to indicate the user's input, and returns a handle that identifies it.

For more information about the **hDevMode** and **hDevNames** members, see the Remarks section at the end of this topic.

### `hDC`

Type: **HDC**

A handle to a device context or an information context, depending on whether the **Flags** member specifies the **PD_RETURNDC** or **PC_RETURNIC** flag. If neither flag is specified, the value of this member is undefined. If both flags are specified, **PD_RETURNDC** has priority.

### `Flags`

Type: **DWORD**

A set of bit flags that you can use to initialize the **Print** property sheet. When the [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) function returns, it sets these flags to indicate the user's input. This member can be one or more of the following values.

To ensure that [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) or [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) returns the correct values in the **dmCopies** and **dmCollate** members of the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure, set **PD_RETURNDC** = **TRUE** and **PD_USEDEVMODECOPIESANDCOLLATE** = **TRUE**. In so doing, the **nCopies** member of the [PRINTDLG](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-printdlga) structure is always 1 and **PD_COLLATE** is always **FALSE**.

To ensure that [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) or [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) returns the correct values in **nCopies** and **PD_COLLATE**, set **PD_RETURNDC** = **TRUE** and **PD_USEDEVMODECOPIESANDCOLLATE** = **FALSE**. In so doing, **dmCopies** is always 1 and **dmCollate** is always **FALSE**.

Starting with Windows Vista, when you call [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) or [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) with **PD_RETURNDC** set to **TRUE** and **PD_USEDEVMODECOPIESANDCOLLATE** set to **FALSE**, the **PrintDlg** or **PrintDlgEx** function sets the number of copies in the **nCopies** member of the [PRINTDLG](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-printdlga) structure, and it sets the number of copies in the structure represented by the **hDC** member of the **PRINTDLG** structure.

When making calls to GDI, you must ignore the value of **nCopies**, consider the value as 1, and use the returned **hDC** to avoid printing duplicate copies.

| Value | Meaning |
| --- | --- |
| **PD_ALLPAGES**<br><br>0x00000000 | The default flag that indicates that the **All** radio button is initially selected. This flag is used as a placeholder to indicate that the **PD_PAGENUMS**, **PD_SELECTION**, and **PD_CURRENTPAGE** flags are not specified. |
| **PD_COLLATE**<br><br>0x00000010 | If this flag is set, the **Collate** check box is selected.<br><br>If this flag is set when the [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) function returns, the application must simulate collation of multiple copies. For more information, see the description of the **PD_USEDEVMODECOPIESANDCOLLATE** flag.<br><br>See **PD_NOPAGENUMS**. |
| **PD_CURRENTPAGE**<br><br>0x00400000 | If this flag is set, the **Current Page** radio button is selected. If none of the **PD_PAGENUMS**, **PD_SELECTION**, or **PD_CURRENTPAGE** flags is set, the **All** radio button is selected. |
| **PD_DISABLEPRINTTOFILE**<br><br>0x00080000 | Disables the **Print to File** check box. |
| **PD_ENABLEPRINTTEMPLATE**<br><br>0x00004000 | Indicates that the **hInstance** and **lpPrintTemplateName** members specify a replacement for the default dialog box template in the lower portion of the **General** page. The default template contains controls similar to those of the **Print** dialog box. The system uses the specified template to create a window that is a child of the **General** page. |
| **PD_ENABLEPRINTTEMPLATEHANDLE**<br><br>0x00010000 | Indicates that the **hInstance** member identifies a data block that contains a preloaded dialog box template. This template replaces the default dialog box template in the lower portion of the **General** page. The system uses the specified template to create a window that is a child of the **General** page. The system ignores the **lpPrintTemplateName** member if this flag is specified. |
| **PD_EXCLUSIONFLAGS**<br><br>0x01000000 | Indicates that the **ExclusionFlags** member identifies items to be excluded from the printer driver property pages. If this flag is not set, items will be excluded by default from the printer driver property pages. The exclusions prevent the duplication of items among the **General** page, any application-specified pages, and the printer driver pages. |
| **PD_HIDEPRINTTOFILE**<br><br>0x00100000 | Hides the **Print to File** check box. |
| **PD_NOCURRENTPAGE**<br><br>0x00800000 | Disables the **Current Page** radio button. |
| **PD_NOPAGENUMS**<br><br>0x00000008 | Disables the **Pages** radio button and the associated edit controls. Also, it causes the **Collate** check box to appear in the dialog. |
| **PD_NOSELECTION**<br><br>0x00000004 | Disables the **Selection** radio button. |
| **PD_NOWARNING**<br><br>0x00000080 | Prevents the warning message from being displayed when an error occurs. |
| **PD_PAGENUMS**<br><br>0x00000002 | If this flag is set, the **Pages** radio button is selected. If none of the **PD_PAGENUMS**, **PD_SELECTION**, or **PD_CURRENTPAGE** flags is set, the **All** radio button is selected. If this flag is set when the [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) function returns, the **lpPageRanges** member indicates the page ranges specified by the user. |
| **PD_PRINTTOFILE**<br><br>0x00000020 | If this flag is set, the **Print to File** check box is selected. If this flag is set when [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) returns, the offset indicated by the **wOutputOffset** member of the [DEVNAMES](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-devnames) structure contains the string "FILE:". When you call the [StartDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-startdoca) function to start the printing operation, specify this "FILE:" string in the **lpszOutput** member of the [DOCINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-docinfoa) structure. Specifying this string causes the print subsystem to query the user for the name of the output file. |
| **PD_RETURNDC**<br><br>0x00000100 | Causes [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) to return a device context matching the selections the user made in the property sheet. The device context is returned in **hDC**. |
| **PD_RETURNDEFAULT**<br><br>0x00000400 | If this flag is set, the [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) function does not display the property sheet. Instead, it sets the **hDevNames** and **hDevMode** members to handles to [DEVNAMES](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-devnames) and [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structures that are initialized for the system default printer. Both **hDevNames** and **hDevMode** must be **NULL**, or **PrintDlgEx** returns an error. |
| **PD_RETURNIC**<br><br>0x00000200 | Similar to the **PD_RETURNDC** flag, except this flag returns an information context rather than a device context. If neither **PD_RETURNDC** nor **PD_RETURNIC** is specified, **hDC** is undefined on output. |
| **PD_SELECTION**<br><br>0x00000001 | If this flag is set, the **Selection** radio button is selected. If none of the **PD_PAGENUMS**, **PD_SELECTION**, or **PD_CURRENTPAGE** flags is set, the **All** radio button is selected. |
| **PD_USEDEVMODECOPIES**<br><br>0x00040000 | Same as **PD_USEDEVMODECOPIESANDCOLLATE**. |
| **PD_USEDEVMODECOPIESANDCOLLATE**<br><br>0x00040000 | This flag indicates whether your application supports multiple copies and collation. Set this flag on input to indicate that your application does not support multiple copies and collation. In this case, the **nCopies** member of the **PRINTDLGEX** structure always returns 1, and **PD_COLLATE** is never set in the **Flags** member.<br><br>If this flag is not set, the application is responsible for printing and collating multiple copies. In this case, the **nCopies** member of the **PRINTDLGEX** structure indicates the number of copies the user wants to print, and the **PD_COLLATE** flag in the **Flags** member indicates whether the user wants collation. <br><br>Regardless of whether this flag is set, an application can determine from **nCopies** and **PD_COLLATE** how many copies to render and whether to print them collated.<br><br>If this flag is set and the printer driver does not support multiple copies, the **Copies** edit control is disabled. Similarly, if this flag is set and the printer driver does not support collation, the **Collate** check box is disabled.<br><br>The **dmCopies** and **dmCollate** members of the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure contain the copies and collate information used by the printer driver. If this flag is set and the printer driver supports multiple copies, the **dmCopies** member indicates the number of copies requested by the user. If this flag is set and the printer driver supports collation, the **dmCollate** member of the **DEVMODE** structure indicates whether the user wants collation. If this flag is not set, the **dmCopies** member always returns 1, and the **dmCollate** member is always zero.<br><br>In Windows versions prior to Windows Vista, if this flag is not set by the calling application and the **dmCopies** member of the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure is greater than 1, use that value for the number of copies; otherwise, use the value of the **nCopies** member of the **PRINTDLGEX** structure. |
| **PD_USELARGETEMPLATE**<br><br>0x10000000 | Forces the property sheet to use a large template for the **General** page. The larger template provides more space for applications that specify a custom template for the lower portion of the **General** page. |

### `Flags2`

Type: **DWORD**

### `ExclusionFlags`

Type: **DWORD**

A set of bit flags that can exclude items from the printer driver property pages in the **Print** property sheet. This value is used only if the **PD_EXCLUSIONFLAGS** flag is set in the **Flags** member. Exclusion flags should be used only if the item to be excluded will be included on either the **General** page or on an application-defined page in the **Print** property sheet. This member can specify the following flag.

#### PD_EXCL_COPIESANDCOLLATE

Excludes the **Copies** and **Collate** controls from the printer driver property pages in a **Print** property sheet. This flag should always be set when the application uses the default **Copies** and **Collate** controls provided by the lower portion of the **General** page of the **Print** property sheet.

### `nPageRanges`

Type: **DWORD**

On input, set this member to the initial number of page ranges specified in the **lpPageRanges** array. When the [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) function returns, **nPageRanges** indicates the number of user-specified page ranges stored in the **lpPageRanges** array. If the **PD_NOPAGENUMS** flag is specified, this value is not valid.

### `nMaxPageRanges`

Type: **DWORD**

The size, in array elements, of the **lpPageRanges** buffer. This value indicates the maximum number of page ranges that can be stored in the array. If the **PD_NOPAGENUMS** flag is specified, this value is not valid. If the **PD_NOPAGENUMS** flag is not specified, this value must be greater than zero.

### `lpPageRanges`

Type: **LPPRINTPAGERANGE**

Pointer to a buffer containing an array of [PRINTPAGERANGE](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-printpagerange) structures. On input, the array contains the initial page ranges to display in the **Pages** edit control. When the [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) function returns, the array contains the page ranges specified by the user. If the **PD_NOPAGENUMS** flag is specified, this value is not valid. If the **PD_NOPAGENUMS** flag is not specified, **lpPageRanges** must be non-**NULL**.

### `nMinPage`

Type: **DWORD**

The minimum value for the page ranges specified in the **Pages** edit control. If the **PD_NOPAGENUMS** flag is specified, this value is not valid.

### `nMaxPage`

Type: **DWORD**

The maximum value for the page ranges specified in the **Pages** edit control. If the **PD_NOPAGENUMS** flag is specified, this value is not valid.

### `nCopies`

Type: **DWORD**

Contains the initial number of copies for the **Copies** edit control if **hDevMode** is **NULL**; otherwise, the **dmCopies** member of the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure contains the initial value. When [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) returns, **nCopies** contains the actual number of copies the application must print. This value depends on whether the application or the printer driver is responsible for printing multiple copies. If the **PD_USEDEVMODECOPIESANDCOLLATE** flag is set in the **Flags** member, **nCopies** is always 1 on return, and the printer driver is responsible for printing multiple copies. If the flag is not set, the application is responsible for printing the number of copies specified by **nCopies**. For more information, see the description of the **PD_USEDEVMODECOPIESANDCOLLATE** flag.

### `hInstance`

Type: **HINSTANCE**

If the **PD_ENABLEPRINTTEMPLATE** flag is set in the **Flags** member, **hInstance** is a handle to the application or module instance that contains the dialog box template named by the **lpPrintTemplateName** member. If the **PD_ENABLEPRINTTEMPLATEHANDLE** flag is set in the **Flags** member, **hInstance** is a handle to a memory object containing a dialog box template. If neither of the template flags is set in the **Flags** member, **hInstance** should be **NULL**.

### `lpPrintTemplateName`

Type: **LPCTSTR**

The name of the dialog box template resource in the module identified by the **hInstance** member. This template replaces the default dialog box template in the lower portion of the **General** page. The default template contains controls similar to those of the **Print** dialog box. This member is ignored unless the PD_ENABLEPRINTTEMPLATE flag is set in the **Flags** member.

### `lpCallback`

Type: **LPUNKNOWN**

A pointer to an application-defined callback object.

The object should contain the [IPrintDialogCallback](https://learn.microsoft.com/windows/desktop/api/commdlg/nn-commdlg-iprintdialogcallback) class to receive messages for the child dialog box in the lower portion of the **General** page.

The callback object should also contain the [IObjectWithSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iobjectwithsite) class to receive a pointer to the [IPrintDialogServices](https://learn.microsoft.com/windows/desktop/api/commdlg/nn-commdlg-iprintdialogservices) interface. The [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) function calls [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) on the callback object for both **IID_IPrintDialogCallback** and **IID_IObjectWithSite** to determine which interfaces are supported.

If you do not want to retrieve any of the callback information, set **lpCallback** to **NULL**.

### `nPropertyPages`

Type: **DWORD**

The number of property page handles in the
**lphPropertyPages** array.

### `lphPropertyPages`

Type: **HPROPSHEETPAGE***

Contains an array of property page handles to add to the **Print** property sheet. The additional property pages follow the **General** page. Use the [CreatePropertySheetPage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-createpropertysheetpagea) function to create these additional pages. When the [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) function returns, all the **HPROPSHEETPAGE** handles in the **lphPropertyPages** array have been destroyed. If **nPropertyPages** is zero, **lphPropertyPages** should be **NULL**.

### `nStartPage`

Type: **DWORD**

The property page that is initially displayed. To display the **General** page, specify **START_PAGE_GENERAL**. Otherwise, specify the zero-based index of a property page in the array specified in the **lphPropertyPages** member. For consistency, it is recommended that the property sheet always be started on the **General** page.

### `dwResultAction`

Type: **DWORD**

On input, set this member to zero. If the [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) function returns S_OK, **dwResultAction** contains the outcome of the dialog. If **PrintDlgEx** returns an error, this member should be ignored. The **dwResultAction** member can be one of the following values.

#### PD_RESULT_APPLY

The user clicked the **Apply** button and later clicked the **Cancel** button. This indicates that the user wants to apply the changes made in the property sheet, but does not want to print yet. The **PRINTDLGEX** structure contains the information specified by the user at the time the **Apply** button was clicked.

#### PD_RESULT_CANCEL

The user clicked the **Cancel** button. The information in the **PRINTDLGEX** structure is unchanged.

#### PD_RESULT_PRINT

The user clicked the **Print** button. The **PRINTDLGEX** structure contains the information specified by the user.

##### - ExclusionFlags.PD_EXCL_COPIESANDCOLLATE

Excludes the **Copies** and **Collate** controls from the printer driver property pages in a **Print** property sheet. This flag should always be set when the application uses the default **Copies** and **Collate** controls provided by the lower portion of the **General** page of the **Print** property sheet.

##### - dwResultAction.PD_RESULT_APPLY

The user clicked the **Apply** button and later clicked the **Cancel** button. This indicates that the user wants to apply the changes made in the property sheet, but does not want to print yet. The **PRINTDLGEX** structure contains the information specified by the user at the time the **Apply** button was clicked.

##### - dwResultAction.PD_RESULT_CANCEL

The user clicked the **Cancel** button. The information in the **PRINTDLGEX** structure is unchanged.

##### - dwResultAction.PD_RESULT_PRINT

The user clicked the **Print** button. The **PRINTDLGEX** structure contains the information specified by the user.

## Remarks

If both **hDevMode** and **hDevNames** are **NULL**, [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) initializes the property sheet using the current default printer. To initialize the property sheet for a different printer, use the **wDeviceOffset** member of the [DEVNAMES](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-devnames) structure to specify the name of the printer.

Note that the **dmDeviceName** member of the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure also specifies a printer name. However, **dmDeviceName** is limited to 32 characters, and the **wDeviceOffset** name is not. If the **wDeviceOffset** and **dmDeviceName** names are not the same, [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) initializes the property sheet using the printer specified by **wDeviceOffset**.

If the PD_RETURNDEFAULT flag is set and both **hDevMode** and **hDevNames** are **NULL**, [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) uses the **hDevNames** and **hDevMode** members to return information about the current default printer without displaying the dialog box.

During the execution of [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)), the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) and **DEVNAMES** structures that you specified in the **PRINTDLGEX** structure may not always contain current data. For this reason, application-specific property pages as well as [IPrintDialogCallback](https://learn.microsoft.com/windows/desktop/api/commdlg/nn-commdlg-iprintdialogcallback) routines for the initial page should use the [IPrintDialogServices](https://learn.microsoft.com/windows/desktop/api/commdlg/nn-commdlg-iprintdialogservices) interface to retrieve information about the state of the current printer.

> [!NOTE]
> The commdlg.h header defines PRINTDLGEX as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Common Dialog Box Library](https://learn.microsoft.com/windows/desktop/dlgbox/common-dialog-box-library)

**Conceptual**

[DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea)

[DEVNAMES](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-devnames)

[IPrintDialogCallback](https://learn.microsoft.com/windows/desktop/api/commdlg/nn-commdlg-iprintdialogcallback)

[IPrintDialogServices](https://learn.microsoft.com/windows/desktop/api/commdlg/nn-commdlg-iprintdialogservices)

[PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85))

**Reference**