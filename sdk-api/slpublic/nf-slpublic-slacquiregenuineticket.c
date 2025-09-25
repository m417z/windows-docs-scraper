HRESULT SLAcquireGenuineTicket(
  [out]          VOID   **ppTicketBlob,
  [out]          UINT   *pcbTicketBlob,
  [in]           PCWSTR pwszTemplateId,
  [in]           PCWSTR pwszServerUrl,
  [in, optional] PCWSTR pwszClientToken
);