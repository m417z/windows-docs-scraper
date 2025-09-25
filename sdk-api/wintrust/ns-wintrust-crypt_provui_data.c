typedef struct _CRYPT_PROVUI_DATA {
  DWORD cbStruct;
  DWORD dwFinalError;
  WCHAR *pYesButtonText;
  WCHAR *pNoButtonText;
  WCHAR *pMoreInfoButtonText;
  WCHAR *pAdvancedLinkText;
  WCHAR *pCopyActionText;
  WCHAR *pCopyActionTextNoTS;
  WCHAR *pCopyActionTextNotSigned;
} CRYPT_PROVUI_DATA, *PCRYPT_PROVUI_DATA;