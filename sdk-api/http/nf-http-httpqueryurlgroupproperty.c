HTTPAPI_LINKAGE ULONG HttpQueryUrlGroupProperty(
  [in]            HTTP_URL_GROUP_ID    UrlGroupId,
  [in]            HTTP_SERVER_PROPERTY Property,
  [out]           PVOID                PropertyInformation,
  [in]            ULONG                PropertyInformationLength,
  [out, optional] PULONG               ReturnLength
);