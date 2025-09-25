HTTPAPI_LINKAGE ULONG HttpQueryRequestQueueProperty(
                  HANDLE               RequestQueueHandle,
  [in]            HTTP_SERVER_PROPERTY Property,
  [out]           PVOID                PropertyInformation,
  [in]            ULONG                PropertyInformationLength,
  [in]            ULONG                Reserved1,
  [out, optional] PULONG               ReturnLength,
  [in]            PVOID                Reserved2
);