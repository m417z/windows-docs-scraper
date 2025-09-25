HRESULT WinBioGetProperty(
  [in]            WINBIO_SESSION_HANDLE    SessionHandle,
  [in]            WINBIO_PROPERTY_TYPE     PropertyType,
  [in]            WINBIO_PROPERTY_ID       PropertyId,
  [in, optional]  WINBIO_UNIT_ID           UnitId,
  [in, optional]  WINBIO_IDENTITY          *Identity,
  [in, optional]  WINBIO_BIOMETRIC_SUBTYPE SubFactor,
                  PVOID                    *PropertyBuffer,
  [out, optional] SIZE_T                   *PropertyBufferSize
);