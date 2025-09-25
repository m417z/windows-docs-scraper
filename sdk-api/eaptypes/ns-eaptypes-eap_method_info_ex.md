## Description

The **EAP_METHOD_INFO_EX** structure contains information about an EAP method.

## Members

### `eaptype`

An [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure that identifies the EAP method.

### `pwszAuthorName`

Pointer to a zero-terminated Unicode string that contains the name of the EAP method's author.

### `pwszFriendlyName`

Pointer to a zero-terminated Unicode string that contains the display name of the EAP method.

### `eapProperties`

Set of flags that describe specific properties of the EAP methods. For flag descriptions, see [EAP Method Properties](https://learn.microsoft.com/windows/win32/eaphost/eap-method-properties).

### `pInnerMethodInfoArray`

Pointer to an [EAP_METHOD_INFO_ARRAY_EX](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_info_array_ex) structure that contains information about all of the EAP methods installed on the client computer.

## See also

[Common EAPHost API Structures](https://learn.microsoft.com/windows/win32/eaphost/common-eap-host-api-structures)

[EAP Method Properties](https://learn.microsoft.com/windows/win32/eaphost/eap-method-properties)

[EAP_METHOD_INFO](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_info)

[EAP_METHOD_INFO_ARRAY](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_info_array)

[EAP_METHOD_INFO_ARRAY_EX](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_info_array_ex)

[EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type)