typedef struct _PPP_EAP_INFO {
  DWORD  dwSizeInBytes;
  DWORD  dwEapTypeId;
  DWORD( )(BOOL fInitialize) *RasEapInitialize;
  DWORD(VOID **ppWorkBuffer,PPP_EAP_INPUT *pPppEapInput) * )(RasEapBegin;
  DWORD()(VOID *pWorkBuffer) * RasEapEnd;
  DWORD(ID *pWorkBuf,PPP_EAP_PACKET *pReceivePacket,PPP_EAP_PACKET *pSendPacket,DWORD cbSendPacket,PPP_EAP_OUTPUT *pEapOutput,PPP_EAP_INPUT *pEapInput) * )(VORasEapMakeMessage;
} PPP_EAP_INFO, *PPPP_EAP_INFO;