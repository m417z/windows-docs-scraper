typedef struct {
  ULONG  ulReserved;
  ULONG  ulRecipClass;
  LPSTR  lpszName;
  LPSTR  lpszAddress;
  ULONG  ulEIDSize;
  LPVOID lpEntryID;
} MapiRecipDesc, *lpMapiRecipDesc;