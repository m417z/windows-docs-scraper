typedef struct _BDA_CAS_OPENMMIDATA {
  ULONG  ulDialogNumber;
  ULONG  ulDialogRequest;
  GUID   uuidDialogType;
  USHORT usDialogDataLength;
  BYTE   argbDialogData[MIN_DIMENSION];
} BDA_CAS_OPENMMIDATA, *PBDA_CAS_OPENMMIDATA;