typedef struct _WINBIO_CAPTURE_DATA {
  DWORD                PayloadSize;
  HRESULT              WinBioHresult;
  WINBIO_SENSOR_STATUS SensorStatus;
  WINBIO_REJECT_DETAIL RejectDetail;
  WINBIO_DATA          CaptureData;
} WINBIO_CAPTURE_DATA, *PWINBIO_CAPTURE_DATA;