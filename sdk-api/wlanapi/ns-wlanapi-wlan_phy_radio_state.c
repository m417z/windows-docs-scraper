typedef struct _WLAN_PHY_RADIO_STATE {
  DWORD             dwPhyIndex;
  DOT11_RADIO_STATE dot11SoftwareRadioState;
  DOT11_RADIO_STATE dot11HardwareRadioState;
} WLAN_PHY_RADIO_STATE, *PWLAN_PHY_RADIO_STATE;