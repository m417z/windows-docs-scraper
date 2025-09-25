typedef enum _WLAN_INTERFACE_STATE {
  wlan_interface_state_not_ready,
  wlan_interface_state_connected,
  wlan_interface_state_ad_hoc_network_formed,
  wlan_interface_state_disconnecting,
  wlan_interface_state_disconnected,
  wlan_interface_state_associating,
  wlan_interface_state_discovering,
  wlan_interface_state_authenticating
} WLAN_INTERFACE_STATE, *PWLAN_INTERFACE_STATE;