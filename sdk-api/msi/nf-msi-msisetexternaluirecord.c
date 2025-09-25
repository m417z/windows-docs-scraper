UINT MsiSetExternalUIRecord(
  [in]            INSTALLUI_HANDLER_RECORD  puiHandler,
  [in]            DWORD                     dwMessageFilter,
  [in]            LPVOID                    pvContext,
  [out, optional] PINSTALLUI_HANDLER_RECORD ppuiPrevHandler
);