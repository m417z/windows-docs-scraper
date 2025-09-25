typedef struct _FAX_PRINT_INFOA {
  DWORD  SizeOfStruct;
  LPCSTR DocName;
  LPCSTR RecipientName;
  LPCSTR RecipientNumber;
  LPCSTR SenderName;
  LPCSTR SenderCompany;
  LPCSTR SenderDept;
  LPCSTR SenderBillingCode;
  LPCSTR Reserved;
  LPCSTR DrEmailAddress;
  LPCSTR OutputFileName;
} FAX_PRINT_INFOA, *PFAX_PRINT_INFOA;