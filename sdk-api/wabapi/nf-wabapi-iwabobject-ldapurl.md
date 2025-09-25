# IWABObject::LDAPUrl

## Description

Processes an Lightweight Directory Access Protocol (LDAP) URL
and displays the results obtained from the URL.
If the URL only contains a server name,
the Windows Address Book (WAB) launches the Find window with the server name
filled in. If the URL contains an
LDAP query, the query is processed. If the query has
a single result, the WAB shows details about the result;
if the query has multiple results, the WAB shows the Find
dialog box with multiple search results filled in.

## Parameters

### `lpIAB`

Type: **[IAddrBook](https://learn.microsoft.com/windows/desktop/api/wabiab/nn-wabiab-iaddrbook)***

Pointer to an [IAddrBook](https://learn.microsoft.com/windows/desktop/api/wabiab/nn-wabiab-iaddrbook) interface
that specifies the address book to use.

### `hWnd`

Type: **HWND**

Value of type **HWND** that specifies the
handle to the parent window for displayed dialog boxes.

### `ulFlags`

Type: **ULONG**

Value of type **ULONG** that specifies flags
that affect functionality.

#### WABOBJECT_LDAPURL_RETURN_MAILUSER

Indicates that a Mailuser object is to be returned if
the query returns a single result. If the query returns multiple
hits, the WAB returns MAPI_E_AMBIGUOUS_RECIPIENT.

#### LDAP_AUTH_NEGOTIATE

Indicates that the WAB must attempt a
negotiated bind with the server.

#### MAPI_UNICODE

Indicates that *lpszURL* must be cast to a
**LPWSTR** before using it.

### `lpszURL`

Type: **LPSTR**

Value of type **LPSTR** that specifies the
LDAP URL string. This
string must begin with "ldap://".

### `lppMailUser`

Type: **[IMailUser](https://learn.microsoft.com/windows/desktop/api/wabdefs/nn-wabdefs-imailuser)****

Address of a pointer to an [IMailUser](https://learn.microsoft.com/windows/desktop/api/wabdefs/nn-wabdefs-imailuser)
interface that receives the returned Mailuser object,
if requested. Otherwise, it is **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The default behavior for this API is to bind anonymously to the
LDAP server. To specify a negotiated bind, you can pass
**LDAP_AUTH_NEGOTIATE** into *ulFlags*.
This flag is defined in Winldap.h.

To pass in a Unicode LDAP
URL without losing any data, cast the
URL pointer to a **LPSTR** and pass it into
this function. Mark *ulFlags* to include **MAPI_UNICODE**, and the WAB will cast the
URL back to an **LPWSTR** prior to using it.