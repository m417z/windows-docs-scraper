typedef struct _WWAN_PIN_LIST {
  WWAN_PIN_DESC WwanPinDescPin1;
  WWAN_PIN_DESC WwanPinDescPin2;
  WWAN_PIN_DESC WwanPinDescDeviceSimPin;
  WWAN_PIN_DESC WwanPinDescDeviceFirstSimPin;
  WWAN_PIN_DESC WwanPinDescNetworkPin;
  WWAN_PIN_DESC WwanPinDescNetworkSubsetPin;
  WWAN_PIN_DESC WwanPinDescSvcProviderPin;
  WWAN_PIN_DESC WwanPinDescCorporatePin;
  WWAN_PIN_DESC WwanPinDescSubsidyLock;
  WWAN_PIN_DESC WwanPinDescCustom;
} WWAN_PIN_LIST, *PWWAN_PIN_LIST;