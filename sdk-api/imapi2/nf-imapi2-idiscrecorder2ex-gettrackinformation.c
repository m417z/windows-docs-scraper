HRESULT GetTrackInformation(
  [in]  ULONG                          address,
  [in]  IMAPI_READ_TRACK_ADDRESS_TYPE  addressType,
  [out] BYTE                           **trackInformation,
  [out] ULONG_IMAPI2_TRACK_INFORMATION *byteSize
);