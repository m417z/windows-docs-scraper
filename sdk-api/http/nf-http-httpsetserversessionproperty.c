HTTPAPI_LINKAGE ULONG HttpSetServerSessionProperty(
  [in] HTTP_SERVER_SESSION_ID ServerSessionId,
  [in] HTTP_SERVER_PROPERTY   Property,
  [in] PVOID                  PropertyInformation,
  [in] ULONG                  PropertyInformationLength
);