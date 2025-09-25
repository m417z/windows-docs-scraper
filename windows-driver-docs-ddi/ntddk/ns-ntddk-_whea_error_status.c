typedef union _WHEA_ERROR_STATUS {
  ULONGLONG ErrorStatus;
  struct {
    ULONGLONG Reserved1 : 8;
    ULONGLONG ErrorType : 8;
    ULONGLONG Address : 1;
    ULONGLONG Control : 1;
    ULONGLONG Data : 1;
    ULONGLONG Responder : 1;
    ULONGLONG Requester : 1;
    ULONGLONG FirstError : 1;
    ULONGLONG Overflow : 1;
    ULONGLONG Reserved2 : 41;
  } DUMMYSTRUCTNAME;
} WHEA_ERROR_STATUS, *PWHEA_ERROR_STATUS;