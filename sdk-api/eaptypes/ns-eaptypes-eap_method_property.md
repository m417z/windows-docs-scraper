# EAP_METHOD_PROPERTY structure

## Description

An **EAP_METHOD_PROPERTY** structure contains an EAP method property.

## Members

### `eapMethodPropertyType`

An [EAP_METHOD_PROPERTY_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ne-eaptypes-eap_method_property_type) enumeration value that describes the type of the EAP method property.

### `eapMethodPropertyValueType`

An [EAP_METHOD_PROPERTY_VALUE_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ne-eaptypes-eap_method_property_value_type) enumeration value that describes the data type of the value specified in **eapMethodPropertyValue**.

### `eapMethodPropertyValue`

An [EAP_METHOD_PROPERTY_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_property_value) union that contains the method property value.

## See also

[EAPHost Supplicant Structures](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-structures)

[EAP_METHOD_PROPERTY_ARRAY](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_property_array)

[EapHostPeerGetMethodProperties](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeergetmethodproperties)