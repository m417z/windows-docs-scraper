typedef struct drt_event_data_tag {
  DRT_EVENT_TYPE type;
  HRESULT        hr;
  PVOID          pvContext;
  union {
    struct {
      DRT_LEAFSET_KEY_CHANGE_TYPE change;
      DRT_DATA                    localKey;
      DRT_DATA                    remoteKey;
    } leafsetKeyChange;
    struct {
      DRT_REGISTRATION_STATE state;
      DRT_DATA               localKey;
    } registrationStateChange;
    struct {
      DRT_STATUS status;
      struct {
        ULONG             cntAddress;
        PSOCKADDR_STORAGE pAddresses;
      } bootstrapAddresses;
    } statusChange;
  };
} DRT_EVENT_DATA, *PDRT_EVENT_DATA;