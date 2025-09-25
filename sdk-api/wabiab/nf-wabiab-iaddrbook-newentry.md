## Description

Displays a blank dialog box that enables the user to create a new entry.

## Parameters

### `ulUIParam`

Value of type ULONG_PTR that specifies the parent window handle for dialog boxes.

### `ulFlags`

Reserved. Must be set to 0.

### `cbEIDContainer`

Value of type **ULONG** that specifies the size of *lpEIDContainer*.

### `lpEIDContainer`

Pointer to a variable of type **ENTRYID** that specifies the entry identifier of the container where the new address is to be created. If the value of this parameter is NULL, the method creates the entry in the root container. Note that this differs from the MAPI implementation of **NewEntry**.

### `cbEIDNewEntryTpl`

Value of type ULONG that specifies the template entry identifier used to determine the object being created.

### `lpEIDNewEntryTpl`

Pointer to a variable of type **ENTRYID** that specifies the template entry identifier used to determine the object being created.

### `lpcbEIDNewEntry`

Pointer to a variable of type ULONG that specifies the returned size of the contents of **lppEIDNewEntry**.

### `lppEIDNewEntry`

Address of a pointer to a variable of type **ENTRYID** that receives the returned entry identifier of the new entry.

## Return value

HRESULT

## Remarks

To create a new entry in the Windows Address Book (WAB) without showing any dialog boxes, use **CreateEntry**. The *cbEIDNewEntryTpl* and the *lpEIDNewEntryTpl* are the template entry identifiers that define the kind of object being created. To obtain the template entry identifiers, open any Windows Address Book (WAB) container and request the PR_DEF_CREATE_MAILUSER or PR_DEF_CREATE_DL property from the container by calling **IMAPIProp::GetProps**. The resulting binary properties are the corresponding template identifiers.

## See also