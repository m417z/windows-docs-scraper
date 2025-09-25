typedef enum _DOT11_POWER_MODE_REASON {
  dot11_power_mode_reason_no_change             = 0,
  dot11_power_mode_reason_noncompliant_AP       = 1,
  dot11_power_mode_reason_legacy_WFD_device     = 2,
  dot11_power_mode_reason_compliant_AP          = 3,
  dot11_power_mode_reason_compliant_WFD_device  = 4,
  dot11_power_mode_reason_others                = 5
} DOT11_POWER_MODE_REASON;