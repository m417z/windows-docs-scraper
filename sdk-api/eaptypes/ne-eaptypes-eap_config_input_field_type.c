typedef enum _EAP_CONFIG_INPUT_FIELD_TYPE {
  EapConfigInputUsername,
  EapConfigInputPassword,
  EapConfigInputNetworkUsername,
  EapConfigInputNetworkPassword,
  EapConfigInputPin,
  EapConfigInputPSK,
  EapConfigInputEdit,
  EapConfigSmartCardUsername,
  EapConfigSmartCardError
} EAP_CONFIG_INPUT_FIELD_TYPE, *PEAP_CONFIG_INPUT_FIELD_TYPE;