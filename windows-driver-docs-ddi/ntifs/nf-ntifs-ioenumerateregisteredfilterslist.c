NTSTATUS IoEnumerateRegisteredFiltersList(
  [out] PDRIVER_OBJECT *DriverObjectList,
  [in]  ULONG          DriverObjectListSize,
  [out] PULONG         ActualNumberDriverObjects
);