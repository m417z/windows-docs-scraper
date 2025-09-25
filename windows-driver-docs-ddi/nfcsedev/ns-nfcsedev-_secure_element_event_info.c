typedef struct _SECURE_ELEMENT_EVENT_INFO {
  GUID                      guidSecureElementId;
  SECURE_ELEMENT_EVENT_TYPE eEventType;
  DWORD                     cbEventData;
  BYTE                      pbEventData[ANYSIZE_ARRAY];
} SECURE_ELEMENT_EVENT_INFO, *PSECURE_ELEMENT_EVENT_INFO;