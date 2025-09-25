DWORD RasEapInvokeInteractiveUI(
  [in]  DWORD dwEapTypeId,
  [in]  HWND  hwndParent,
  [in]  BYTE  *pUIContextData,
  [in]  DWORD dwSizeOfUIContextData,
        BYTE  **ppDataFromInteractiveUI,
  [out] DWORD *pdwSizeOfDataFromInteractiveUI
);