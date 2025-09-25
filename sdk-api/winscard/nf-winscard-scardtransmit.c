LONG SCardTransmit(
  [in]                SCARDHANDLE         hCard,
  [in]                LPCSCARD_IO_REQUEST pioSendPci,
  [in]                LPCBYTE             pbSendBuffer,
  [in]                DWORD               cbSendLength,
  [in, out, optional] LPSCARD_IO_REQUEST  pioRecvPci,
  [out]               LPBYTE              pbRecvBuffer,
  [in, out]           LPDWORD             pcbRecvLength
);