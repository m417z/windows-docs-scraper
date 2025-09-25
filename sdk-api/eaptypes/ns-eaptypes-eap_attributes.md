# EAP_ATTRIBUTES structure

## Description

The **EAP_ATTRIBUTES** structure contains an array of EAP attributes.

## Members

### `dwNumberOfAttributes`

The number of [EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) structures in **pAttribs**.

### `pAttribs.size_is`

### `pAttribs.size_is.dwNumberOfAttributes`

### `pAttribs`

Pointer to the address of the first element in an array of [EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) structures. The total number of elements is specified in **dwNumberOfAttributes**.

## See also

[Common EAPHost API Structures](https://learn.microsoft.com/windows/win32/eaphost/common-eap-host-api-structures)

[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute)