HTTPAPI_LINKAGE ULONG HttpCreateRequestQueue(
  [in]           HTTPAPI_VERSION      Version,
  [in, optional] PCWSTR               Name,
  [in, optional] PSECURITY_ATTRIBUTES SecurityAttributes,
  [in, optional] ULONG                Flags,
  [out]          PHANDLE              RequestQueueHandle
);