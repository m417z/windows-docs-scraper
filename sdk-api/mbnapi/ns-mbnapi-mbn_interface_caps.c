typedef struct MBN_INTERFACE_CAPS {
  MBN_CELLULAR_CLASS cellularClass;
  MBN_VOICE_CLASS    voiceClass;
  ULONG              dataClass;
  BSTR               customDataClass;
  ULONG              gsmBandClass;
  ULONG              cdmaBandClass;
  BSTR               customBandClass;
  ULONG              smsCaps;
  ULONG              controlCaps;
  BSTR               deviceID;
  BSTR               manufacturer;
  BSTR               model;
  BSTR               firmwareInfo;
} MBN_INTERFACE_CAPS;