HTTPAPI_LINKAGE ULONG HttpQueryServerSessionProperty(
  [in]            HTTP_SERVER_SESSION_ID ServerSessionId,
  [in]            HTTP_SERVER_PROPERTY   Property,
  [out]           PVOID                  PropertyInformation,
  [in]            ULONG                  PropertyInformationLength,
  [out, optional] PULONG                 ReturnLength
);