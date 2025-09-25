# NPAddConnection function

## Description

The **NPAddConnection** function connects a local device to a network resource.

## Parameters

### `lpNetResource` [in]

Pointer to a
[NETRESOURCE](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-netresourcea) structure which specifies the network resource to connect to. The following fields must be set in the **NETRESOURCE** structure you pass in. The **NPAddConnection** function ignores the other fields.

| Value | Meaning |
| --- | --- |
| **lpRemoteName** | Specifies the network resource to connect to. |
| **lpLocalName** | Specifies the name of a local device to be redirected, such as "F:" or "LPT1". This name is treated as case insensitive and may be an empty string or **NULL** pointer. If the string is empty or **NULL**, the function connects to the network resource without making a redirection. |
| **dwType** | Specifies the type of resource to connect to. This can be RESOURCETYPE_DISK, RESOURCETYPE _PRINT, or RESOURCETYPE_ANY. The value RESOURCETYPE _ANY is used if the caller does not care or does not know. |

### `lpPassword` [in]

Pointer to the password to be used in making the connection, normally the password associated with *lpUserName*. The **NULL** value may be passed in to cause the function to use the default password. An empty string may be used to indicate no password. When you have finished using the password, clear it from memory by calling the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function. For more information about protecting the password, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

### `lpUserName` [in]

Pointer to the user name used to make the connection. If **NULL**, the default user name (that of the currently logged-on user) is applied. This is used when the user wants to connect to a resource but has a different assigned user name or account for that resource.

For example, if you were logged using the user name "MyAccount" and wanted to connect to a network resource that was available only to a second account, where the user name was "MyOtherAccount", you could specify "MyOtherAccount" in *lpUserName* in order to connect to the resource. You would also specify the password of this second account in *lpPassword*.

## Return value

If the function succeeds, it should return WN_SUCCESS. Otherwise, it should return an error code, which can be one of the following.

| Return code | Description |
| --- | --- |
| **WN_BAD_NETNAME** | The value of the **lpRemoteName** member of the structure passed into *lpNetResource* is not valid for this provider. |
| **WN_BAD_LOCALNAME** | The value of the **lpLocalName** member of the structure passed into *lpNetResource* is not valid. |
| **WN_BAD_PASSWORD** | The specified password is not valid. |
| **WN_ALREADY_CONNECTED** | The device specified in the **lpLocalName** member of the structure passed into *lpNetResource* is already connected. |
| **WN_ACCESS_DENIED** | Permission to establish the connection is denied. |
| **WN_NO_NETWORK** | The network is not present. |