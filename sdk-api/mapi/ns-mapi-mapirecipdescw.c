typedef struct {
  ULONG ulReserved;
  ULONG ulRecipClass;
  PWSTR lpszName;
  PWSTR lpszAddress;
  ULONG ulEIDSize;
  PVOID lpEntryID;
} MapiRecipDescW, *lpMapiRecipDescW;