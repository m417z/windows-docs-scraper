# ADRPARM structure

## Description

Do not use. Describes the display and behavior of the common address dialog box.

## Members

### `cbABContEntryID`

Type: **ULONG**

Variable of type **ULONG** that specifies the list of entries that can be added to the recipient wells.

### `lpABContEntryID`

Type: **LPENTRYID**

Pointer to a variable of type [ENTRYID](https://learn.microsoft.com/previous-versions/windows/desktop/api/wabdefs/ns-wabdefs-entryid) that specifies the container that will supply the list of [one-off](https://learn.microsoft.com/windows/win32/api/wabiab/nf-wabiab-iaddrbook-createoneoff) entries that can be added to the recipient wells of the address book's common dialog box. The address book container that **lpABContEntryID** points to determines what is listed in the edit box within the dialog box that holds possible recipient names. Usually, **lpABContEntryID** is **NULL**, indicating the use of a custom recipient provider.

### `ulFlags`

Type: **ULONG**

Value of type **ULONG** that specifies the bitmask of flags associated with various address dialog box options. The following flags can be set in the WAB.

#### AB_RESOLVE

Causes all names to be resolved after the address book dialog box is closed. The Resolve Name dialog box is displayed if there are ambiguous entries in the recipient list.

#### AB_SELECTONLY

Disables the creation of custom recipient addresses and direct type-in entries for a recipient list. This flag is used only if the dialog box is modal.

#### ADDRESS_ONE

Indicates that the user of the dialog box can select exactly one message recipient, instead of a number of recipients from a recipient list. This flag is valid only when **cDestFields** is zero. This flag is used only if the dialog box is modal.

#### DIALOG_MODAL

Causes a modal dialog box to be displayed. The client must set either this flag or **DIALOG_SDI**, but not both.

#### DIALOG_SDI

Causes a modeless dialog box to be displayed. This call returns immediately and thus does not modify the [ADRLIST](https://learn.microsoft.com/windows/desktop/api/wabdefs/ns-wabdefs-adrlist) structure passed in. The caller must set either this flag or **DIALOG_MODAL**, but not both.

### `lpReserved`

Type: **LPVOID**

### `ulHelpContext`

Type: **ULONG**

Not supported. Must be set to 0.

### `lpszHelpFileName`

Type: **LPTSTR**

Not supported. Must be set to **NULL**.

### `lpfnABSDI`

Type: **LPFNABSDI**

Pointer to a WAB function based on the [ACCELERATEABSDI](https://learn.microsoft.com/previous-versions/office/developer/office-2007/cc839835(v=office.12)) prototype (see MAPI documentation), or **NULL**. This member applies only to the modeless version of the dialog box, as indicated by the **DIALOG_SDI** flag being set.

Clients building an **ADRPARM** structure to pass to [Address](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxstatus-get-address-vb) must always set the **lpfnABSDI** member to **NULL**. If the **DIALOG_SDI** flag is set, WAB then sets it to a valid function before returning. Clients call this function from within their message loop to ensure that accelerators in the address book dialog box work. When the dialog box is dismissed and WAB calls the function to which the **lpfnDismiss** member points, clients should unhook the [ACCELERATEABSDI](https://learn.microsoft.com/previous-versions/office/developer/office-2007/cc839835(v=office.12)) function from their message loop.

### `lpfnDismiss`

Type: **LPFNDISMISS**

Pointer to a function based on the [DISMISSMODELESS](https://learn.microsoft.com/previous-versions/office/developer/office-2007/cc815796(v=office.12)) (see MAPI documentation) prototype, or **NULL**. This member applies only to the modeless version of the dialog box, as indicated by the **DIALOG_SDI** flag being set. WAB calls the DISMISSMODELESS function when the user dismisses the modeless address dialog box, informing a client calling [Address](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxstatus-get-address-vb) that the dialog box is no longer active.

### `lpvDismissContext`

Type: **LPVOID**

Pointer to the context information to be passed to the [DISMISSMODELESS](https://learn.microsoft.com/previous-versions/office/developer/office-2007/cc815796(v=office.12)) function to which the **lpfnDismiss** member points. This member applies only to the modeless version of the dialog box, as indicated by the **DIALOG_SDI** flag being set.

### `lpszCaption`

Type: **LPTSTR**

Variable of type **LPTSTR** that specifies the text to be used as a caption for the address book dialog box.

### `lpszNewEntryTitle`

Type: **LPTSTR**

Variable of type **LPTSTR** that specifies the text to be used as a new-entry prompt for an edit box in an address book dialog box.

### `lpszDestWellsTitle`

Type: **LPTSTR**

Variable of type **LPTSTR** that specifies the text to be used as a title for the set of recipient-name edit boxes that appears in the dialog box. This member is used only if the address book dialog box is modal.

### `cDestFields`

Type: **ULONG**

Variable of type **ULONG** that specifies the number of recipient-name edit boxes (that is, destination fields) in the address book dialog box. A number from 0 through 3 is typical. If the **cDestFields** member is zero and the ADDRESS_ONE flag is not set in **ulFlags**, the address book will be open for browsing only.

### `nDestFieldFocus`

Type: **ULONG**

Variable of type **ULONG** that specifies the field in the address book dialog box that should have the initial focus when the dialog box appears. This value must be between 0 and the value of **cDestFields** minus 1.

### `lppszDestTitles`

Type: **LPTSTR***

Pointer to an array of variables of type **LPTSTR** that specify the text titles to be displayed in the recipient-name edit boxes of the address book dialog box. The size of the array is the value of **cDestFields**. If the **lppszDestTitles** member is **NULL**, the [Address](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxstatus-get-address-vb) method chooses default titles.

### `lpulDestComps`

Type: **ULONG***

Pointer to an array of variables of type **ULONG** that specify the recipient types—such as MAPI_TO, MAPI_CC, and MAPI_BCC—associated with each recipient-name edit box. The size of the array is the value of **cDestFields**. If the **lpulDestComps** member is **NULL**, the [Address](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxstatus-get-address-vb) method chooses default recipient types.

### `lpContRestriction`

Type: **LPSRestriction**

Not supported. Must be set to **NULL**.

### `lpHierRestriction`

Type: **LPSRestriction**

Not supported. Must be set to **NULL**.