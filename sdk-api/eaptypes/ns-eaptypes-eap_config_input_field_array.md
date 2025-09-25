## Description

The **EAP_CONFIG_INPUT_FIELD_ARRAY** structure contains a set of [EAP_CONFIG_INPUT_FIELD_DATA](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_config_input_field_data) structures that collectively contain the user input field data obtained from the user.

## Members

### `dwVersion`

The version of the [EAP_CONFIG_INPUT_FIELD_DATA](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_config_input_field_data) structures pointed to by **pFields**.

| Value | Meaning |
| --- | --- |
| **EAP_CREDENTIAL_VERSION**<br><br>1 | The version of the EAP credentials supplied by the user. |

### `dwNumberOfFields`

The total number of elements in the array specified by **pFields**.

### `pFields`

Pointer to an array of [EAP_CONFIG_INPUT_FIELD_DATA](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_config_input_field_data) structures that contain specific user input data obtained from an EAP configuration dialog box.

## Remarks

The **EAP_CONFIG_INPUT_FIELD_ARRAY** structure can be employed to support Single-Sign-On (SSO).

## See also

[EAP_CONFIG_INPUT_FIELD_DATA](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_config_input_field_data)

[SSO and PLAP](https://learn.microsoft.com/windows/win32/eaphost/understanding-sso-and-plap)