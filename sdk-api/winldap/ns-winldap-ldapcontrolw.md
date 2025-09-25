# LDAPControlW structure

## Description

The **LDAPControl** structure represents both client-side and server controls.

## Members

### `ldctl_oid`

Pointer to a wide, null-terminated string that indicates control type, such as "1.2.840.113556.1.4.805".

### `ldctl_value`

The data associated with the control, if any. If no data is associated with the control, set this member to **NULL**.

### `ldctl_iscritical`

Indicates whether the control is critical, called the Criticality field.

## Remarks

Effective with LDAP 3, you can extend LDAP operations through the use of controls. Server controls can be sent to the server or returned to the client with any LDAP message. Client controls extend the behavior of the LDAP API on the client-side only and are never sent to the server. A supported control is stored as an object identifier (OID) in the Directory Service root.

The **ldctl_iscritical** member enables an extended operation to succeed when the server or client does not support the control. If the value of this field is zero, the server and/or client ignores the control if it is not supported and carries out the operation. If the value is nonzero the operation is carried out only if the control is recognized by the server and/or client.

For more information, and a list of the supported LDAP extended controls and their descriptions, see

[Extended Controls](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/extended-controls).

> [!NOTE]
> The winldap.h header defines LDAPControl as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Data Structures](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/data-structures)

[LDAPMessage](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldapmessage)

[Using Controls](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/using-controls)