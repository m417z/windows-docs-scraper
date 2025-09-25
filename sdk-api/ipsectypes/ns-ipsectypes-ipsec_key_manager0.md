# IPSEC_KEY_MANAGER0 structure

## Description

The **IPSEC_KEY_MANAGER0** structure is used to register key management callbacks with IPsec.

## Members

### `keyManagerKey`

Type: **GUID**

Uniquely identifies the Key Manager.

### `displayData`

Type: [FWPM_DISPLAY_DATA0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwpm_display_data0)

Contains annotations associated with the filter.

### `flags`

Type: **UINT32**

Possible values:

| Value | Meaning |
| --- | --- |
| **IPSEC_KEY_MANAGER_FLAG_DICTATE_KEY** | Specifies that the TIA will be able to accept key notifications and also potentially dictate keys. If this flag is not set, the TIA can only accept key notifications and will not be able to dictate keys. |

### `keyDictationTimeoutHint`

Type: **UINT8**

Time, in seconds, after which the **keyDictation** callback must return in order for registration to succeed. Set this field to **0** in order to use the default timeout (5 seconds).

## See also

[FWPM_DISPLAY_DATA0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwpm_display_data0)

[IPSEC_KEY_MANAGER_CALLBACKS0](https://learn.microsoft.com/windows/desktop/api/fwpmu/ns-fwpmu-ipsec_key_manager_callbacks0)

[IPsecKeyManagerAddAndRegister0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ipseckeymanageraddandregister0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)