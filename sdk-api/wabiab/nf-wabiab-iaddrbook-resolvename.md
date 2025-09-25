## Description

Resolves a partial recipient list to full addresses.

## Parameters

### `ulUIParam`

Value of type **ULONG_PTR** that specifies the parent window handle.

### `ulFlags`

Value of type ULONG that specifies flags that affect behavior.

| Flag | Description |
|------|-------------|
| MAPI_DIALOG | Displays a dialog box to prompt the user for additional name-resolution information. If this flag is not set, no dialog box is displayed.|
| WAB_RESOLVE_ALL_EMAILS | Causes name resolution to check against every e-mail address of every entry, instead of checking against the entry's default e-mail address. This makes name resolution slow; avoid using this flag if speed is important.|
| WAB_RESOLVE_NO_ONE_OFFS | Prevents the Windows Address Book (WAB) from resolving valid e-mail addresses or name/e-mail address pairs as one-off addresses after the initial resolution attempt fails. If resolution fails, the default behavior turns the information from a valid name/e-mail pair or e-mail address into a one-off address.|
| WAB_RESOLVE_NEED_CERT | Causes name resolution to succeed only if the matching entry has certificate data that can be returned on resolution. |
| WAB_RESOLVE_NO_NOT_FOUND_UI | Suppresses the Windows Address Book (WAB) UI that typically follows unsuccessful name resolution.|
| WAB_RESOLVE_USE_CURRENT_PROFILE | Restricts the name resolution to contacts corresponding to the current Identity only, in Profile- or Identity-enabled Windows Address Book (WAB) sessions. The name resolution first looks for an exact match within the list of the Identities private folders. If no match is found in the Identities folders, the Windows Address Book (WAB) searches all the shared folders, followed by the LDAP. If this flag is not specified, the Windows Address Book (WAB) searches against all its contents, irrespective of whether the Windows Address Book (WAB) is profile enabled.|
| WAB_RESOLVE_FIRST_MATCH | Causes the Windows Address Book (WAB) to return the first entry that matches the given criteria. Once the Windows Address Book (WAB) finds the first entry, it does not look for any other matches.|
|WAB_RESOLVE_LOCAL_ONLY | Causes the Windows Address Book (WAB) to skip name resolution on any LDAP servers even if such servers have been configured for name resolution. This flag is useful if you want to restrict your resolution or search to the contents within the Windows Address Book (WAB).|

### `lpszNewEntryTitle`

Pointer to a string that specifies the title for the [IAddrBook::NewEntry](https://learn.microsoft.com/windows/win32/api/wabiab/nf-wabiab-iaddrbook-newentry) dialog box.

### `lpAdrList`

Pointer to a variable of type **ADRLIST** that specifies the address list containing property lists to match. On output, *lpAdrList* receives a pointer to a variable containing an address list of resolved recipients.

## Return value

HRESULT

| Value | Description |
|-------|-------------|
|S_OK | The name resolution process succeeded. |
| MAPI_E_AMBIGUOUS_RECIP | At least one recipient in the *lpAdrList* parameter matched more than one entry in the address book. Usually, this value is returned when the **MAPI_DIALOG** flag is not set, prohibiting the display of a dialog box. |
| MAPI_E_NOT_FOUND |At least one recipient in the *lpAdrList* parameter cannot be resolved. Usually, this value is returned when the **MAPI_DIALOG** flag is not set, prohibiting the display of a dialog box.|

## Remarks

**ResolveName** will optionally display a dialog box if ambiguous matches are found. **ResolveName** goes through the address list passed in lpAdrList, finds all the unresolved names, resolves them, and returns the appropriately modified address list. The address list passed in can be a list created using the [IAddrBook::Address](https://learn.microsoft.com/windows/win32/api/wabiab/nf-wabiab-iaddrbook-address) method.
If a recipient is ambiguous and the MAPI_DIALOG flag is not specified, **ResolveName** will return MAPI_E_AMBIGUOUS_RECIPIENT.

> [!NOTE]
> The **ADRENTRY** items in the **ADRLIST** should be separately allocated, NOT allocated with **AllocateMore**.

When **ResolveName** replaces an entry, the **ADRENTRY** is freed through the action of **FreeBuffer**. A new entry is allocated by **AllocateMore**

## See also