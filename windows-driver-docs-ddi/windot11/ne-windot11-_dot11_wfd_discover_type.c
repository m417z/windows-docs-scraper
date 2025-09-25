typedef enum _DOT11_WFD_DISCOVER_TYPE {
  dot11_wfd_discover_type_scan_only             = 1,
  dot11_wfd_discover_type_find_only             = 2,
  dot11_wfd_discover_type_auto                  = 3,
  dot11_wfd_discover_type_scan_social_channels  = 4,
  dot11_wfd_discover_type_forced                = 0x80000000
} DOT11_WFD_DISCOVER_TYPE;