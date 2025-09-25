# RAS_AUTH_ATTRIBUTE structure

## Description

The
**RAS_AUTH_ATTRIBUTE** structure is used to pass authentication attributes, of type
[RAS_AUTH_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/win32/api/raseapif/ne-raseapif-ras_auth_attribute_type), during an EAP session.

## Members

### `raaType`

Specifies the type of attribute, as defined in the
[RAS_AUTH_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/win32/api/raseapif/ne-raseapif-ras_auth_attribute_type) enumerated type.

### `dwLength`

Specifies the length in bytes of the value of this attribute. If the **Value** member is a pointer, **dwLength** specifies the length of the buffer pointed to. If the **Value** member is the value itself, **dwLength** specifies how much of the length of the **Value** member is taken up by the value.

### `Value`

Specifies the value of the attribute. Although this member is of the **PVOID** type, this member sometimes contains the value of the attribute rather than pointing to the value. The only way to know whether to interpret the **Value** member as a pointer to the value or the value itself, is to check the **raaType** member. See the reference page for
[RAS_AUTH_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/win32/api/raseapif/ne-raseapif-ras_auth_attribute_type) for information about how the **Value** member should be interpreted for different types.

## Remarks

Often an array of these structures is used to store or obtain a set of attributes for a given user. Since the number of attributes for a session is unknown, the array must be dynamic. The array is terminated by a structure with an **raaType** member that has a value of **raatMinimum**.

## See also

[EAP Structures](https://learn.microsoft.com/windows/win32/eap/eap-structures)

[Extensible Authentication Protocol Reference](https://learn.microsoft.com/windows/win32/eap/extensible-authentication-protocol-reference)

[RAS_AUTH_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/win32/api/raseapif/ne-raseapif-ras_auth_attribute_type)