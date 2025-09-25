# IContactManagerInterop::ShowContactCardForWindow

## Description

Displays the UI for a contact on the specified window.

## Parameters

### `appWindow` [in]

Type: **HWND**

The [HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) of the foreground window of the app from which the contact card is launched and where focus is returned when the contact card is dismissed.

### `contact` [in]

Type: **IUnknown***

A pointer to the contact object. Use a [Windows.ApplicationModel.Contacts.Contact](https://learn.microsoft.com/uwp/api/windows.applicationmodel.contacts.contact) object but cast to [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) here because classic COM IDL can't use Windows Runtime types.

### `selection` [in]

Type: **RECT const***

The [Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect) is the rectangular area of user selection (for example, pressing a button), around which the operating system displays the contact card, not within that rectangular area. For example, if an app uses a button to show the contact card, pass the **Rect** of the button so the contact card displays around the button, not overlapping it.

### `preferredPlacement` [in]

Type: **FLYOUT_PLACEMENT**

A **FLYOUT_PLACEMENT**-typed value that describes the preferred placement of the contact card.

| Value | Meaning |
| --- | --- |
| **FP_DEFAULT**<br><br>0 | Use the default. |
| **FP_ABOVE**<br><br>1 | Prefer to place the contact card above the rectangular area of user selection specified by the *selection* parameter. |
| **FP_BELOW**<br><br>2 | Prefer to place the contact card below the rectangular area of user selection specified by the *selection* parameter. |
| **FP_LEFT**<br><br>3 | Prefer to place the contact card to the left of the rectangular area of user selection specified by the *selection* parameter. |
| **FP_RIGHT**<br><br>4 | Prefer to place the contact card to the right of the rectangular area of user selection specified by the *selection* parameter. |

## Return value

Type: **HRESULT**

[ShowContactCardForWindow](https://learn.microsoft.com/previous-versions/dn302110(v=vs.85)) returns:

* S_OK if the contact card is successfully displayed
* E_POINTER if *appWindow* is NULL or *contact* is NULL or *selection* is NULL
* E_INVALIDARG if *contact* isn't a [Windows.ApplicationModel.Contacts.Contact](https://learn.microsoft.com/uwp/api/windows.applicationmodel.contacts.contact) object or *preferredPlacement* is an invalid enumeration value

Other [HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) values are possible.

## See also

[IContactManagerInterop](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontactmanagerinterop)

[ShowContactCardForWindow](https://learn.microsoft.com/previous-versions/dn302110(v=vs.85))