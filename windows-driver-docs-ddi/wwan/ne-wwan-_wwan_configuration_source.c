typedef enum _WWAN_CONFIGURATION_SOURCE {
  WwanUserProvisioned,
  WwanAdminProvisioned,
  WwanOperatorProvisioned,
  WwanDeviceProvisioned,
  WwanModemProvisioned,
  WwanModemOperatorProvisioned,
  WwanMaxProvisionSource
} WWAN_CONFIGURATION_SOURCE, *PWWAN_CONFIGURATION_SOURCE;