typedef struct _MFINPUTTRUSTAUTHORITY_ACTION {
  MFPOLICYMANAGER_ACTION Action;
  BYTE                   *pbTicket;
  DWORD                  cbTicket;
} MFINPUTTRUSTAUTHORITY_ACCESS_ACTION;