typedef struct _FAX_PRINT_INFOW {
  DWORD   SizeOfStruct;
  LPCWSTR DocName;
  LPCWSTR RecipientName;
  LPCWSTR RecipientNumber;
  LPCWSTR SenderName;
  LPCWSTR SenderCompany;
  LPCWSTR SenderDept;
  LPCWSTR SenderBillingCode;
  LPCWSTR Reserved;
  LPCWSTR DrEmailAddress;
  LPCWSTR OutputFileName;
} FAX_PRINT_INFOW, *PFAX_PRINT_INFOW;