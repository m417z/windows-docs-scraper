## Description

The **EAP_METHOD_INFO** structure contains information about an EAP method.

## Members

### `eaptype`

[EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure that identifies the EAP method.

### `pwszAuthorName`

Pointer to a zero-terminated Unicode string that contains the name of the EAP method's author.

### `pwszFriendlyName`

Pointer to a zero-terminated Unicode string that contains the display name of the EAP method.

### `eapProperties`

Set of flags that describe specific properties of the EAP method. For flag descriptions, see [EAP Method Properties](https://learn.microsoft.com/windows/win32/eaphost/eap-method-properties).

### `pInnerMethodInfo`

Pointer to an **EAP_METHOD_INFO** structure that contains information about the inner method.

## See also

[Common EAPHost API Structures](https://learn.microsoft.com/windows/win32/eaphost/common-eap-host-api-structures)

[EAP Method Properties](https://learn.microsoft.com/windows/win32/eaphost/eap-method-properties)

[EAP_METHOD_INFO_ARRAY](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_info_array)

[EAP_METHOD_INFO_ARRAY_EX](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_info_array_ex)

[EAP_METHOD_INFO_EX](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_info_ex)

[EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type)