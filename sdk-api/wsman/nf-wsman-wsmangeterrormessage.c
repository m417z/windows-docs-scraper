DWORD WSManGetErrorMessage(
  [in]           WSMAN_API_HANDLE apiHandle,
                 DWORD            flags,
  [in, optional] PCWSTR           languageCode,
                 DWORD            errorCode,
                 DWORD            messageLength,
  [out]          PWSTR            message,
  [out]          DWORD            *messageLengthUsed
);