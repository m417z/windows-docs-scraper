typedef enum _WWAN_IP_TYPE {
  WwanIPTypeDefault,
  WwanIPTypeIPv4,
  WwanIPTypeIPv6,
  WwanIPTypeIpv4v6,
  WwanIPTypeXlat,
  WwanSessionTypeEthernet,
  WwanSessionTypeUnstructured,
  WwanSessionTypeMax
} WWAN_IP_TYPE, *PWWAN_IP_TYPE;