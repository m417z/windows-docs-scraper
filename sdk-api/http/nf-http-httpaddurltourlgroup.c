HTTPAPI_LINKAGE ULONG HttpAddUrlToUrlGroup(
  [in]           HTTP_URL_GROUP_ID UrlGroupId,
  [in]           PCWSTR            pFullyQualifiedUrl,
  [in, optional] HTTP_URL_CONTEXT  UrlContext,
  [in]           ULONG             Reserved
);