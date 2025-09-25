# IPSEC_KEY_MANAGER_CALLBACKS0 structure

## Description

The **IPSEC_KEY_MANAGER_CALLBACKS0** structure specifies the set of callbacks which should be invoked by IPsec at various stages of SA negotiation

## Members

### `reserved`

Type: **GUID**

Reserved for system use.

### `flags`

Type: **UINT32**

Reserved for system use.

### `keyDictationCheck`

Type: **[IPSEC_KEY_MANAGER_KEY_DICTATION_CHECK0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nc-fwpmu-ipsec_key_manager_key_dictation_check0)**

Specifies that the Trusted Intermediary Agent (TIA) will dictate the keys for the SA being negotiated. Only used if the **IPSEC_DICTATE_KEY** flag is set.

### `keyDictation`

Type: **[IPSEC_KEY_MANAGER_DICTATE_KEY0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nc-fwpmu-ipsec_key_manager_dictate_key0)**

Allows the TIA to dictate the keys for the SA being negotiated. Only used if the **IPSEC_DICTATE_KEY** flag is set.

### `keyNotify`

Type: **[IPSEC_KEY_MANAGER_NOTIFY_KEY0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nc-fwpmu-ipsec_key_manager_notify_key0)**

Notifies the TIA of the keys for the SA being negotiated.

## Remarks

If the **IPSEC_KEY_MANAGER_FLAG_DICTATE_KEY** flag is set, all three callbacks must be specified; otherwise, only the **keyNotify** callback should be specified.

## See also

[IPSEC_KEY_MANAGER0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_key_manager0)

[IPSEC_KEY_MANAGER_DICTATE_KEY0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nc-fwpmu-ipsec_key_manager_dictate_key0)

[IPSEC_KEY_MANAGER_KEY_DICTATION_CHECK0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nc-fwpmu-ipsec_key_manager_key_dictation_check0)

[IPSEC_KEY_MANAGER_NOTIFY_KEY0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nc-fwpmu-ipsec_key_manager_notify_key0)

[IPsecKeyManagerAddAndRegister0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ipseckeymanageraddandregister0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)