## Description

The **EAP_ATTRIBUTE** structure contains an EAP attribute.

## Members

### `eaType`

An [EAP_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ne-eaptypes-eap_attribute_type) enumeration value that describes the type of the EAP attribute value supplied in **pValue**.

### `dwLength`

The size, in bytes, of **pValue**.

### `pValue`

Pointer to a byte buffer that contains the data value of the attribute.

## See also

[Common EAPHost API Structures](https://learn.microsoft.com/windows/win32/eaphost/common-eap-host-api-structures)

[EAP_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attributes)