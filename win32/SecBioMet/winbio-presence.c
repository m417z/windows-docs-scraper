typedef struct _WINBIO_PRESENCE {
  WINBIO_BIOMETRIC_TYPE      Factor;
  WINBIO_BIOMETRIC_SUBTYPE   SubFactor;
  HRESULT                    Status;
  WINBIO_REJECT_DETAIL       RejectDetail;
  WINBIO_IDENTITY            Identity;
  ULONGLONG                  TrackingId;
  WINBIO_PROTECTION_TICKET   Ticket;
  WINBIO_PRESENCE_PROPERTIES Properties;
} WINBIO_PRESENCE, *PWINBIO_PRESENCE;