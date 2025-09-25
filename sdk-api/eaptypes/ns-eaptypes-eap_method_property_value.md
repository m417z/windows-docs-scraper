# EAP_METHOD_PROPERTY_VALUE structure overview

## Description

The **EAP_METHOD_PROPERTY_VALUE** union contains the value of an EAP method property.

## Members

### `empvBool`

case(*empvtBool*)

If [eapMethodPropertyValueType](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_property) specifies a Boolean type (*empvtBool*), the data pointed to by this parameter is defined by the [EAP_METHOD_PROPERTY_VALUE_BOOL](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_property_value_bool) structure.

### `case`

### `case.empvtBool`

### `empvDword`

case(*empvDword*)

If [eapMethodPropertyValueType](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_property) specifies a DWORD type (empvtDword), the data pointed to by this parameter is defined by the [EAP_METHOD_PROPERTY_VALUE_DWORD](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_property_value_dword) structure.

### `case.empvtDword`

### `empvString`

case(*empvString*)

If [eapMethodPropertyValueType](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_property) specifies a BYTE *(empvtString), the data pointed to by this parameter is defined by the [EAP_METHOD_PROPERTY_VALUE_STRING](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_property_value_string) structure.

### `case.empvtString`

### `EAP_METHOD_PROPERTY_VALUE_TYPE`

## See also

[EAPHost Supplicant Structures](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-structures)

[EAP_METHOD_PROPERTY](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_property)

[EapHostPeerGetMethodProperties](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeergetmethodproperties)