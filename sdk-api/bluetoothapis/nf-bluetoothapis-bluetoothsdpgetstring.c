DWORD BluetoothSdpGetString(
  [in]      LPBYTE                      pRecordStream,
  [in]      ULONG                       cbRecordLength,
  [in]      const PSDP_STRING_TYPE_DATA pStringData,
  [in]      USHORT                      usStringOffset,
  [out]     PWSTR                       pszString,
  [in, out] PULONG                      pcchStringLength
);