typedef enum _WLAN_AUTOCONF_OPCODE {
  wlan_autoconf_opcode_start = 0,
  wlan_autoconf_opcode_show_denied_networks,
  wlan_autoconf_opcode_power_setting,
  wlan_autoconf_opcode_only_use_gp_profiles_for_allowed_networks,
  wlan_autoconf_opcode_allow_explicit_creds,
  wlan_autoconf_opcode_block_period,
  wlan_autoconf_opcode_allow_virtual_station_extensibility,
  wlan_autoconf_opcode_end
} WLAN_AUTOCONF_OPCODE, *PWLAN_AUTOCONF_OPCODE;