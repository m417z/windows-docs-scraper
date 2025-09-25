DWORD EapHostPeerQueryUIBlobFromInteractiveUIInputFields(
  [in]      DWORD                         dwVersion,
  [in]      DWORD                         dwFlags,
  [in]      DWORD                         dwSizeofUIContextData,
  [in]      const BYTE                    *pUIContextData,
  [in]      const EAP_INTERACTIVE_UI_DATA *pEapInteractiveUIData,
  [in, out] DWORD                         *pdwSizeOfDataFromInteractiveUI,
  [in, out] BYTE                          **ppDataFromInteractiveUI,
  [out]     EAP_ERROR                     **ppEapError,
  [in, out] LPVOID                        *ppvReserved
);