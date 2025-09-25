typedef struct _WRDS_CONNECTION_SETTINGS_1 {
  BOOLEAN                    fInheritInitialProgram;
  BOOLEAN                    fInheritColorDepth;
  BOOLEAN                    fHideTitleBar;
  BOOLEAN                    fInheritAutoLogon;
  BOOLEAN                    fMaximizeShell;
  BOOLEAN                    fDisablePNP;
  BOOLEAN                    fPasswordIsScPin;
  BOOLEAN                    fPromptForPassword;
  BOOLEAN                    fDisableCpm;
  BOOLEAN                    fDisableCdm;
  BOOLEAN                    fDisableCcm;
  BOOLEAN                    fDisableLPT;
  BOOLEAN                    fDisableClip;
  BOOLEAN                    fResetBroken;
  BOOLEAN                    fDisableEncryption;
  BOOLEAN                    fDisableAutoReconnect;
  BOOLEAN                    fDisableCtrlAltDel;
  BOOLEAN                    fDoubleClickDetect;
  BOOLEAN                    fEnableWindowsKey;
  BOOLEAN                    fUsingSavedCreds;
  BOOLEAN                    fMouse;
  BOOLEAN                    fNoAudioPlayback;
  BOOLEAN                    fRemoteConsoleAudio;
  BYTE                       EncryptionLevel;
  USHORT                     ColorDepth;
  USHORT                     ProtocolType;
  USHORT                     HRes;
  USHORT                     VRes;
  USHORT                     ClientProductId;
  USHORT                     OutBufCountHost;
  USHORT                     OutBufCountClient;
  USHORT                     OutBufLength;
  ULONG                      KeyboardLayout;
  ULONG                      MaxConnectionTime;
  ULONG                      MaxDisconnectionTime;
  ULONG                      MaxIdleTime;
  ULONG                      PerformanceFlags;
  ULONG                      KeyboardType;
  ULONG                      KeyboardSubType;
  ULONG                      KeyboardFunctionKey;
  ULONG                      ActiveInputLocale;
  ULONG                      SerialNumber;
  ULONG                      ClientAddressFamily;
  ULONG                      ClientBuildNumber;
  ULONG                      ClientSessionId;
  WCHAR                      WorkDirectory[WTS_DIRECTORY_LENGTH + 1];
  WCHAR                      InitialProgram[WTS_INITIALPROGRAM_LENGTH + 1];
  WCHAR                      UserName[WTS_USERNAME_LENGTH + 1];
  WCHAR                      Domain[WTS_DOMAIN_LENGTH + 1];
  WCHAR                      Password[WTS_PASSWORD_LENGTH + 1];
  WCHAR                      ProtocolName[WTS_PROTOCOL_NAME_LENGTH + 1];
  WCHAR                      DisplayDriverName[WTS_DRIVER_NAME_LENGTH + 1];
  WCHAR                      DisplayDeviceName[WTS_DEVICE_NAME_LENGTH + 1];
  WCHAR                      imeFileName[WTS_IMEFILENAME_LENGTH + 1];
  WCHAR                      AudioDriverName[WTS_DRIVER_NAME_LENGTH + 1];
  WCHAR                      ClientName[WTS_CLIENTNAME_LENGTH + 1];
  WCHAR                      ClientAddress[WTS_CLIENTADDRESS_LENGTH + 1];
  WCHAR                      ClientDirectory[WTS_DIRECTORY_LENGTH + 1];
  WCHAR                      ClientDigProductId[WTS_CLIENT_PRODUCT_ID_LENGTH + 1];
  WRDS_SOCKADDR              ClientSockAddress;
  WRDS_TIME_ZONE_INFORMATION ClientTimeZone;
  WRDS_LISTENER_SETTINGS     WRdsListenerSettings;
  GUID                       EventLogActivityId;
#if ...
  ULONG                      ContextSize;
#if ...
  PBYTE                      ContextData;
#else
  ULONG                      ContextSize;
#endif
#else
  PBYTE                      ContextData;
#endif
} WRDS_CONNECTION_SETTINGS_1, *PWRDS_CONNECTION_SETTINGS_1;