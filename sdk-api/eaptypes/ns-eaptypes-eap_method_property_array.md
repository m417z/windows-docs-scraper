# EAP_METHOD_PROPERTY_ARRAY structure

## Description

The **EAP_METHOD_PROPERTY_ARRAY** structure contains an array of EAP method properties.

## Members

### `dwNumberOfProperties`

The number of [EAP_METHOD_PROPERTY](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_property) structures in **pMethodProperty**.

### `pFields`

### `pFields.size_is`

### `pFields.size_is.dwNumberOfProperties`

### `pMethodProperty`

Pointer to the address of the first element in an array of [EAP_METHOD_PROPERTY](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_property) structures. The total number of elements is specified in **dwNumberOfProperties**.

## See also

[EAPHost Supplicant Structures](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-structures)

[EapHostPeerGetMethodProperties](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeergetmethodproperties)