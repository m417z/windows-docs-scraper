typedef struct RILCONFPARTICIPANTSTATUS {
  DWORD                   cbSize;
  DWORD                   dwParams;
  DWORD                   dwExecutor;
  DWORD                   dwID;
  BOOL                    bCallTransfer;
  RILADDRESS              raAddress;
  RILPARTICIPANTOPERATION dwParticipantOp;
  DWORD                   dwSIPStatus;
} RILCONFPARTICIPANTSTATUS, *LPRILCONFPARTICIPANTSTATUS;