# NPAddConnection3 function

## Description

The **NPAddConnection3** function connects a local device to a network resource. It performs the same operation as
[NPAddConnection](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npaddconnection) but in addition lets you specify a handle to the window that should own any resulting dialog boxes and specify how the connection should be established.

## Parameters

### `hwndOwner` [in]

A handle to a window that should own any messages or dialog boxes. This handle is valid only if CONNECT_INTERACTIVE is set in *dwFlags*, and the handle should only be used to produce dialog boxes needed for authentication.

### `lpNetResource` [in]

Pointer to a
[NETRESOURCE](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-netresourcea) structure that specifies the network resource to connect to. The following fields must be set when making a connection. The others are ignored.

| Value | Meaning |
| --- | --- |
| **lpRemoteName** | Specifies the network resource to connect to. |
| **lpLocalName** | Specifies the name of a local device to be redirected, such as "F:" or "LPT1". This name is treated as case insensitive and may be the empty string or **NULL** pointer. If the string is empty or **NULL**, the function connects to the network resource without making a redirection. |
| **dwType** | Specifies the type of resource to connect to. This can be RESOURCETYPE_DISK, RESOURCETYPE_PRINT, or RESOURCETYPE_ANY. The value RESOURCETYPE_ANY is used if the caller does not care or does not know. |

### `lpPassword` [in]

Pointer to the password to be used in making the connection, normally the password associated with *lpUserName*. The **NULL** value may be passed in to cause the function to use the default password. An empty string may be used to indicate no password. When you have finished using the password, clear it from memory by calling the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function. For more information about protecting the password, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

### `lpUserName` [in]

Pointer to the user name used to make the connection. If **NULL**, the default user name (that of the currently logged-on user) is applied. This is used when the user wants to connect to a resource but has a different assigned user name or account for that resource.

### `dwFlags` [in]

Any combination of the following values. The provider should ignore any other bits of *dwFlags* that may be set.

| Value | Meaning |
| --- | --- |
| **CONNECT_TEMPORARY** | The connection is being established for browsing purposes and will probably be released quickly. |
| **CONNECT_INTERACTIVE** | The connection may have interaction with the user for authentication purposes. |
| **CONNECT_PROMPT** | Do not use any defaults for user names or passwords without offering the user a chance to supply an alternative. This flag is only valid if CONNECT_INTERACTIVE is also set. |
| **CONNECT_DEFERRED** | Do not perform any remote network operations to make the network connection; instead, restore the connection in a "disconnected state." Attempt the actual connection only when some process attempts to use the connection. If this bit is set, the caller must supply *lpLocalName*. <br><br>This feature is used to speed the restoring of network connections at logon. A provider that supports it should return the WNNC_CON_DEFERRED bit in [NPGetCaps](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npgetcaps). |

## Return value

If the function succeeds, it will return WN_SUCCESS. Otherwise, it will return an error code. This may include one of the following.

| Return code | Description |
| --- | --- |
| **WN_BAD_NETNAME** | The value of the **lpRemoteName** member of the structure passed into *lpNetResource* is not valid for this provider. |
| **WN_BAD_LOCALNAME** | The value of the **lpLocalName** member of the structure passed into *lpNetResource* is not valid. |
| **WN_BAD_PASSWORD** | The specified password is not valid. |
| **WN_ALREADY_CONNECTED** | The device specified in the **lpLocalName** member of the structure passed into *lpNetResource* is already connected. |
| **WN_ACCESS_DENIED** | Permission to establish the connection is denied. |
| **WN_NO_NETWORK** | The network is not present. |
| **WN_CANCEL** | The attempt to make the connection was canceled by the user using a dialog box displayed by the provider. |

## Remarks

If a provider displays a password dialog box because the specified credentials are insufficient and the CONNECT_INTERACTIVE flag is set, then the provider may not return an access-denied error code (one of ERROR_LOGON_FAILURE, WN_BAD_PASSWORD, WN_ACCESS_DENIED). The suggested behavior is for the provider to continue asking the user for valid credentials until the user either supplies them or presses a "cancel" button. If **NPAddConnection3** is called to make the connection requested during the
[WNetConnectionDialog](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetconnectiondialog) or
[WNetConnectionDialog1](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetconnectiondialog1a) function and an access-denied code is returned, the
**WNetConnectionDialog** or
**WNetConnectionDialog1** function will, itself, display a password dialog box.

## See also

[NPAddConnection](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npaddconnection)