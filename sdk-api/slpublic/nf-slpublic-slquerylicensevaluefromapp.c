HRESULT SLQueryLicenseValueFromApp(
  [in]            PCWSTR valueName,
  [out, optional] ULONG  *valueType,
  [out, optional] PVOID  dataBuffer,
  [in]            ULONG  dataSize,
  [out]           ULONG  *resultDataSize
);