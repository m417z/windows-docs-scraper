HTTPAPI_LINKAGE ULONG HttpSetRequestQueueProperty(
  [in] HANDLE               RequestQueueHandle,
  [in] HTTP_SERVER_PROPERTY Property,
  [in] PVOID                PropertyInformation,
  [in] ULONG                PropertyInformationLength,
  [in] ULONG                Reserved1,
  [in] PVOID                Reserved2
);