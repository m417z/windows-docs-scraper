DWORD EapHostPeerQueryInteractiveUIInputFields(
  [in]      DWORD                   dwVersion,
  [in]      DWORD                   dwFlags,
  [in]      DWORD                   dwSizeofUIContextData,
  [in]      const BYTE              *pUIContextData,
  [out]     EAP_INTERACTIVE_UI_DATA *pEapInteractiveUIData,
  [out]     EAP_ERROR               **ppEapError,
  [in, out] LPVOID                  *ppvReserved
);