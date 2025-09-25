# EAP_METHOD_PROPERTY_VALUE_STRING structure

## Description

The **EAP_METHOD_PROPERTY_VALUE_STRING** structure contains the string value of an EAP method property.

## Members

### `length`

The size, in bytes, of **value**.

### `value.size_is`

### `value.size_is.length`

### `value`

Pointer to a byte buffer than contains the data value of an EAP method property.

## See also

[EAPHost Supplicant Structures](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-structures)

[EAP_METHOD_PROPERTY_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_property_value)

[EapHostPeerGetMethodProperties](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeergetmethodproperties)