# EAP_METHOD_INFO_ARRAY_EX structure

## Description

The **EAP_METHOD_INFO_ARRAY_EX** structure contains information about all of the EAP methods installed on the client computer. After populating **EAP_METHOD_INFO_ARRAY_EX**, EAPHost passes this method information to the supplicant.

## Members

### `dwNumberOfMethods`

The number of [EAP_METHOD_INFO_EX](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_info_ex) structures in **pEapMethods**.

### `pEapMethods`

Pointer to the address of the first element in an array of [EAP_METHOD_INFO_EX](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_info_ex) structures. The total number of elements is specified in **dwNumberOfMethods**.

## See also

[Common EAPHost API Structures](https://learn.microsoft.com/windows/win32/eaphost/common-eap-host-api-structures)

[EAP Method Properties](https://learn.microsoft.com/windows/win32/eaphost/eap-method-properties)

[EAP_METHOD_INFO](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_info)

[EAP_METHOD_INFO_ARRAY](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_info_array)

[EAP_METHOD_INFO_EX](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_info_ex)

[EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type)