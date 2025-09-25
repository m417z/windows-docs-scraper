# EAP_CONFIG_INPUT_FIELD_DATA structure

## Description

The **EAP_CONFIG_INPUT_FIELD_DATA** structure contains the data associated with a single input field.

## Members

### `dwSize`

The size, in bytes, of the **EAP_CONFIG_INPUT_FIELD_DATA** structure. This field is used for versioning purposes.

### `Type`

An [EAP_CONFIG_INPUT_FIELD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ne-eaptypes-eap_config_input_field_type) enumeration value that specifies the type of the input field.

### `dwFlagProps`

A set of flag values that describe properties of the EAP configuration input field.

| Value | Meaning |
| --- | --- |
| **EAP_UI_INPUT_FIELD_PROPS_DEFAULT**<br><br>0X00000000 | Windows Vista with SP1 or later: Represents the default property value for input field entries displayed in the UI. |
| **EAP_CONFIG_INPUT_FIELD_PROPS_DEFAULT**<br><br>0X00000000 | Represents the default property value for configuration input field entries displayed in the UI. |
| **EAP_UI_INPUT_FIELD_PROPS_NON_DISPLAYABLE**<br><br>0X00000001 | Windows Vista with SP1 or later: Specifies that input field entries will not be displayed in the UI (a password or PIN number, for example). |
| **EAP_CONFIG_INPUT_FIELD_PROPS_NON_DISPLAYABLE**<br><br>0X00000001 | Specifies that configuration input field entries will not be displayed in the UI (a password or PIN number, for example). |
| **EAP_UI_INPUT_FIELD_PROPS_NON_PERSIST**<br><br>0X00000002 | Windows Vista with SP1 or later: Indicates that the EAP method will not cache the field data; the supplicant must cache the field data for roaming. |
| **EAP_CONFIG_INPUT_FIELD_PROPS_NON_PERSIST**<br><br>0X00000002 | Indicates that the EAP method will not cache the field data; the supplicant must cache the field data for roaming. |
| **EAP_UI_INPUT_FIELD_PROPS_READ_ONLY**<br><br>0x00000004 | Windows Vista with SP1 or later: Indicates that the input field is read-only and cannot be edited. |

### `pwszLabel`

A pointer to a zero-terminated Unicode string that contains the label for the input field. The caller must free the inner pointers
using the function [EapHostPeerFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreememory), starting at the innermost pointer.

| Value | Meaning |
| --- | --- |
| **MAX_EAP_CONFIG_INPUT_FIELD_LENGTH**<br><br>256 | Specifies the maximum supported length of an input field. |

### `pwszData`

A pointer to a zero-terminated Unicode string that contains the data entered by the user into the input field. This value is initially empty. It is populated in a Single-Sign-On (SSO) scenario and returned to EAPHost with a call to [EapHostPeerQueryUserBlobFromCredentialInputFields](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerqueryuserblobfromcredentialinputfields). The caller must free the inner pointers
using the function EapHostPeerFreeMemory, starting at the innermost pointer.

| Value | Meaning |
| --- | --- |
| **MAX_EAP_CONFIG_INPUT_FIELD_VALUE_LENGTH**<br><br>1024 | Specifies the maximum supported length of an input field. |

### `dwMinDataLength`

The minimum length, in bytes, allowed for data entered by the user into the EAP configuration dialog box input field.

### `dwMaxDataLength`

The maximum length, in bytes, allowed for data entered by the user into the EAP configuration dialog box input field.

## Remarks

The **EAP_CONFIG_INPUT_FIELD_DATA** structure can be employed to support SSO.

This structure represents the data associated with a single input field in an EAP configuration dialog box. For example, it could contain the data for the "Login User" as supplied by the EAP application user.

The entire collection of input fields in a EAP configuration dialog box is represented by a [EAP_CONFIG_INPUT_FIELD_ARRAY](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_config_input_field_array) structure.

## See also

[EAP_CONFIG_INPUT_FIELD_ARRAY](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_config_input_field_array)

[EapPeerQueryCredentialInputFields](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerquerycredentialinputfields)

[SSO and PLAP](https://learn.microsoft.com/windows/win32/eaphost/understanding-sso-and-plap)