# DSDISPLAYSPECOPTIONS structure

## Description

The **DSDISPLAYSPECOPTIONS** structure is returned by the [CFSTR_DS_DISPLAY_SPEC_OPTIONS](https://learn.microsoft.com/windows/desktop/AD/cfstr-ds-display-spec-options) clipboard format and is used to supply data to a context menu or property page extension about the display specifiers used. It is important to specify the credentials required by the extension, to access data in the Active Directory server.

## Members

### `dwSize`

The size of the structure for versioning purposes.

### `dwFlags`

A set of flags that indicate data about the object and define the contents of the structure. This can be zero or a combination of one or more of the following values.

#### DSDSOF_HASUSERANDSERVERINFO (0x00000001)

The **offsetUserName**, **offsetPassword**, **offsetServer** and **offsetServerConfigPath** members are valid.

#### DSDSOF_SIMPLEAUTHENTICATE (0x00000002)

Do not specify **ADS_SECURE_AUTHENTICATION** flag when calling [ADsOpenObject](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsopenobject).

#### DSDSOF_DONTSIGNSEAL (0x00000004)

Do not sign and seal when opening directory service objects.

#### DSDSOF_DSAVAILABLE (0x40000000)

Forces the client to avoid checking if the user is authenticated, the network is present or logged in, assuming the client belongs to a domain controlled by Active Directory Domain Services.

### `offsetAttribPrefix`

Contains the offset, in bytes, from the start of the **DSDISPLAYSPECOPTIONS** structure to a NULL-terminated, Unicode string that contains the prefix of the display specifier that the created extension was obtained from. This string can be one of the following values.

#### "admin"

The extension was obtained from the [adminPropertyPages](https://learn.microsoft.com/windows/desktop/ADSchema/a-adminpropertypages) attribute.

#### "shell"

The extension was obtained from the [shellPropertyPages](https://learn.microsoft.com/windows/desktop/ADSchema/a-shellpropertypages) attribute.

The following example shows how to use this member.

```cpp
pwszAttribPrefix = (LPWSTR)((LPBYTE)pdos +
    pdso->offsetAttribPrefix);

```

### `offsetUserName`

Contains the offset, in bytes, from the start of the **DSDISPLAYSPECOPTIONS** structure to a NULL-terminated, Unicode string that contains the name of the user used to authenticate the bind. This member is only valid if **dwFlags** contains the **DSDSOF_HASUSERANDSERVERINFO** flag. If this member contains zero, the user name is not included.

The following example shows how to use this member.

```cpp
pwszUserName = (LPWSTR)((LPBYTE)pdso +
    pdso->offsetUserName);

```

### `offsetPassword`

Contains the offset, in bytes, from the start of the **DSDISPLAYSPECOPTIONS** structure to a NULL-terminated, Unicode string that contains the password used to authenticate the bind. This member is only valid if **dwFlags** contains the **DSDSOF_HASUSERANDSERVERINFO** flag. If this member contains zero, the password is not included.

The following example shows how to use this member.

```cpp
pwszPassword = (LPWSTR)((LPBYTE)pdso +
    pdso->offsetPassword);

```

### `offsetServer`

Contains the offset, in bytes, from the start of the **DSDISPLAYSPECOPTIONS** structure to a NULL-terminated, Unicode string that contains the name of the server. This member is only valid if **dwFlags** contains the **DSDSOF_HASUSERANDSERVERINFO** flag. If this member contains zero, the server name is not included.

The following example shows how to use this member.

```cpp
pwszServer = (LPWSTR)((LPBYTE)pdso +
    pdso->offsetServer);

```

### `offsetServerConfigPath`

Contains the offset, in bytes, from the start of the **DSDISPLAYSPECOPTIONS** structure to a NULL-terminated, Unicode string that contains the ADsPath of the server. This member is only valid if **dwFlags** contains the **DSDSOF_HASUSERANDSERVERINFO** flag. If this member contains zero, the server path is not included.

The following example shows how to use this member.

```cpp
pwszServerConfigPath = (LPWSTR)((LPBYTE)pdso +
    pdso->offsetServerConfigPath);

```

## See also

[ADsOpenObject](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsopenobject)

[CFSTR_DS_DISPLAY_SPEC_OPTIONS](https://learn.microsoft.com/windows/desktop/AD/cfstr-ds-display-spec-options)

[Display Structures in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-structures-in-active-directory-domain-services)