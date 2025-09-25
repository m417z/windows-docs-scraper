typedef struct _WWAN_CONTEXT_STATE {
  ULONG                    uNwError;
  ULONG                    ConnectionId;
  WWAN_ACTIVATION_STATE    ActivationState;
  WWAN_VOICE_CALL_STATE    VoiceCallState;
  WWAN_IP_TYPE             IPType;
  WWAN_CONNECTION_MEDIA    ConnectionMedia;
  WCHAR                    AccessString[WWAN_ACCESSSTRING_LEN];
  WWAN_SINGLE_NSSAI        Snssai;
  ULONG                    FoundMatchingConnectionId;
  WWAN_OFFSET_SIZE_ELEMENT TrafficParameters;
} WWAN_CONTEXT_STATE, *PWWAN_CONTEXT_STATE;