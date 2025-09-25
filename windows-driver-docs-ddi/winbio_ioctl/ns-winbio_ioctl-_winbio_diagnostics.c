typedef struct _WINBIO_DIAGNOSTICS {
  DWORD                PayloadSize;
  HRESULT              WinBioHresult;
  WINBIO_SENSOR_STATUS SensorStatus;
  WINBIO_DATA          VendorDiagnostics;
} WINBIO_DIAGNOSTICS, *PWINBIO_DIAGNOSTICS;