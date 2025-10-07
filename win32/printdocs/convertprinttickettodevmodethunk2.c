HRESULT ConvertPrintTicketToDevModeThunk2(
  _In_      HPTPROVIDER hProvider,
  _In_      BYTE        *pPrintTicket,
  _In_      ULONG       cbSize,
  _In_      INT         baseType,
  _In_      DWORD       scope,
  _Out_     BYTE        **ppDevmode,
  _Out_     ULONG       *pcbDevModeLength,
  _Out_opt_ BSTR        *errMsg
);