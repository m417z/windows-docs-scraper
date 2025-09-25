HRESULT RIL_SendMsgAck(
  HRIL            hRil,
  LPVOID          lpContext,
  DWORD           dwExecutor,
  HUICCAPP        hUiccApp,
  DWORD           dwAckID,
  RILMSGACKSTATUS dwMsgStatus,
  RILSMSFORMAT    dwSmsFormat,
  RILSMSACKOPT    dwOptions
);