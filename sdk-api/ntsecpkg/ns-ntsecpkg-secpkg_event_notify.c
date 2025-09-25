typedef struct _SECPKG_EVENT_NOTIFY {
  ULONG EventClass;
  ULONG Reserved;
  ULONG EventDataSize;
  PVOID EventData;
  PVOID PackageParameter;
} SECPKG_EVENT_NOTIFY, *PSECPKG_EVENT_NOTIFY;