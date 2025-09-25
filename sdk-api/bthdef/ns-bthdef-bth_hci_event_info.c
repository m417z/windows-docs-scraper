typedef struct _BTH_HCI_EVENT_INFO {
  BTH_ADDR bthAddress;
  UCHAR    connectionType;
  UCHAR    connected;
} BTH_HCI_EVENT_INFO, *PBTH_HCI_EVENT_INFO;