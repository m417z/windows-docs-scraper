DWORD RasSecurityDialogBegin(
  [in] HPORT                        hPort,
  [in] PBYTE                        pSendBuf,
  [in] DWORD                        SendBufSize,
  [in] PBYTE                        pRecvBuf,
  [in] DWORD                        RecvBufSize,
       VOID(* )(SECURITY_MESSAGE *) RasSecurityDialogComplete
);