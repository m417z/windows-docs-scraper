# _DOT11EXT_APIS structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11EXT_APIS structure specifies a list of pointers to the IHV Extensibility functions that are
supported by the operating system.

## Members

### `Dot11ExtAllocateBuffer`

A pointer to the
[Dot11ExtAllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_allocate_buffer) function.

### `Dot11ExtFreeBuffer`

A pointer to the
[Dot11ExtFreeBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_free_buffer) function.

### `Dot11ExtSetProfileCustomUserData`

A pointer to the
[Dot11ExtSetProfileCustomUserData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_profile_custom_user_data) function.

### `Dot11ExtGetProfileCustomUserData`

A pointer to the
[Dot11ExtGetProfileCustomUserData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_get_profile_custom_user_data) function.

### `Dot11ExtSetCurrentProfile`

A pointer to the
[Dot11ExtSetCurrentProfile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_current_profile) function.

### `Dot11ExtSendUIRequest`

A pointer to the
[Dot11ExtSendUIRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_send_ui_request) function.

### `Dot11ExtPreAssociateCompletion`

A pointer to the
[Dot11ExtPreAssociateCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_pre_associate_completion) function.

### `Dot11ExtPostAssociateCompletion`

A pointer to the
[Dot11ExtPostAssociateCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_post_associate_completion) function.

### `Dot11ExtSendNotification`

A pointer to the
[Dot11ExtSendNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_send_notification) function.

### `Dot11ExtSendPacket`

A pointer to the
[Dot11ExtSendPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_send_packet) function.

### `Dot11ExtSetEtherTypeHandling`

A pointer to the
[Dot11ExtSetEtherTypeHandling](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_ethertype_handling) function.

### `Dot11ExtSetAuthAlgorithm`

A pointer to the
[Dot11ExtSetAuthAlgorithm](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_auth_algorithm) function.

### `Dot11ExtSetUnicastCipherAlgorithm`

A pointer to the
[Dot11ExtSetUnicastCipherAlgorithm](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_unicast_cipher_algorithm) function.

### `Dot11ExtSetMulticastCipherAlgorithm`

A pointer to the
[Dot11ExtSetMulticastCipherAlgorithm](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_multicast_cipher_algorithm) function.

### `Dot11ExtSetDefaultKey`

A pointer to the
[Dot11ExtSetDefaultKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_default_key) function.

### `Dot11ExtSetKeyMappingKey`

A pointer to the
[Dot11ExtSetKeyMappingKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_key_mapping_key) function.

### `Dot11ExtSetDefaultKeyId`

A pointer to the
[Dot11ExtSetDefaultKeyId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_default_key_id) function.

### `Dot11ExtNicSpecificExtension`

A pointer to the
[Dot11ExtNicSpecificExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_nic_specific_extension) function.

### `Dot11ExtSetExcludeUnencrypted`

A pointer to the
[Dot11ExtSetExcludeUnencrypted](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_exclude_unencrypted) function.

### `Dot11ExtStartOneX`

A pointer to the
[Dot11ExtStartOneX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_onex_start) function.

### `Dot11ExtStopOneX`

A pointer to the
[Dot11ExtStopOneX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_onex_stop) function.

### `Dot11ExtProcessSecurityPacket`

### `Dot11ExtProcessOneXPacket`

A pointer to the
[Dot11ExtProcessOneXPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_process_onex_packet) function.

## Syntax

```cpp
typedef struct _DOT11EXT_APIS {
  DOT11EXT_ALLOCATE_BUFFER                Dot11ExtAllocateBuffer;
  DOT11EXT_FREE_BUFFER                    Dot11ExtFreeBuffer;
  DOT11EXT_SET_PROFILE_CUSTOM_USER_DATA   Dot11ExtSetProfileCustomUserData;
  DOT11EXT_GET_PROFILE_CUSTOM_USER_DATA   Dot11ExtGetProfileCustomUserData;
  DOT11EXT_SET_CURRENT_PROFILE            Dot11ExtSetCurrentProfile;
  DOT11EXT_SEND_UI_REQUEST                Dot11ExtSendUIRequest;
  DOT11EXT_PRE_ASSOCIATE_COMPLETION       Dot11ExtPreAssociateCompletion;
  DOT11EXT_POST_ASSOCIATE_COMPLETION      Dot11ExtPostAssociateCompletion;
  DOT11EXT_SEND_NOTIFICATION              Dot11ExtSendNotification;
  DOT11EXT_SEND_PACKET                    Dot11ExtSendPacket;
  DOT11EXT_SET_ETHERTYPE_HANDLING         Dot11ExtSetEtherTypeHandling;
  DOT11EXT_SET_AUTH_ALGORITHM             Dot11ExtSetAuthAlgorithm;
  DOT11EXT_SET_UNICAST_CIPHER_ALGORITHM   Dot11ExtSetUnicastCipherAlgorithm;
  DOT11EXT_SET_MULTICAST_CIPHER_ALGORITHM Dot11ExtSetMulticastCipherAlgorithm;
  DOT11EXT_SET_DEFAULT_KEY                Dot11ExtSetDefaultKey;
  DOT11EXT_SET_KEY_MAPPING_KEY            Dot11ExtSetKeyMappingKey;
  DOT11EXT_SET_DEFAULT_KEY_ID             Dot11ExtSetDefaultKeyId;
  DOT11EXT_NIC_SPECIFIC_EXTENSION         Dot11ExtNicSpecificExtension;
  DOT11EXT_SET_EXCLUDE_UNENCRYPTED        Dot11ExtSetExcludeUnencrypted;
  DOT11EXT_ONEX_START                     Dot11ExtStartOneX;
  DOT11EXT_ONEX_STOP                      Dot11ExtStopOneX;
  DOT11EXT_PROCESS_ONEX_PACKET            Dot11ExtProcessOneXPacket;
} DOT11EXT_APIS, *PDOT11EXT_APIS;
```

## Remarks

The IHV Extensibility functions are not statically or dynamically linked to the IHV Extensions DLL.
Instead, when the operating system calls the
[Dot11ExtIhvInitService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_service) IHV
handler function, it passes the list of pointers to the IHV Extensibility functions through the
*pDot11ExtAPI* parameter.

All of the function pointers are required and will not be set to **NULL**.

## See also

[Dot11ExtSetDefaultKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_default_key)

[Dot11ExtGetUserData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_get_profile_custom_user_data)

[Native 802.11 IHV Handler
Functions](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-ihv-handler-functions)

[Dot11ExtStartOneX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_onex_start)

[Dot11ExtSetProfileCustomUserData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_profile_custom_user_data)

[Dot11ExtSetEtherTypeHandling](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_ethertype_handling)

[Dot11ExtSetDefaultKeyId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_default_key_id)

[Native 802.11 IHV
Extensibility Functions](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-ihv-extensibility-functions)

[Dot11ExtSetExcludeUnencrypted](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_exclude_unencrypted)

[Dot11ExtSetKeyMappingKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_key_mapping_key)

[Dot11ExtSetCurrentProfile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_current_profile)

[Dot11ExtSendPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_send_packet)

[Dot11ExtSendUIRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_send_ui_request)

[Dot11ExtStopOneX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_onex_stop)

[Dot11ExtIhvInitService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_service)

[Dot11ExtSetUnicastCipherAlgorithm](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_unicast_cipher_algorithm)

[Dot11ExtSetMulticastCipherAlgorithm](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_multicast_cipher_algorithm)

[Dot11ExtProcessOneXPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_process_onex_packet)

[Dot11ExtFreeBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_free_buffer)

[Dot11ExtPreAssociateCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_pre_associate_completion)

[Dot11ExtAllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_allocate_buffer)

[Dot11ExtPostAssociateCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_post_associate_completion)

[Dot11ExtNicSpecificExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_nic_specific_extension)

[Dot11ExtSetAuthAlgorithm](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_auth_algorithm)

[Dot11ExtSendNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_send_notification)