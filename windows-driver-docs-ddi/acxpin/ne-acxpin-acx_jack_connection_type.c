typedef enum _ACX_JACK_CONNECTION_TYPE {
  AcxConnTypeUnknown,
  AcxConnType3Point5mm,
  AcxConnTypeQuarter,
  AcxConnTypeAtapiInternal,
  AcxConnTypeRCA,
  AcxConnTypeOptical,
  AcxConnTypeOtherDigital,
  AcxConnTypeOtherAnalog,
  AcxConnTypeMultichannelAnalogDIN,
  AcxConnTypeXlrProfessional,
  AcxConnTypeRJ11Modem,
  AcxConnTypeCombination
} ACX_JACK_CONNECTION_TYPE, *PACX_JACK_CONNECTION_TYPE;