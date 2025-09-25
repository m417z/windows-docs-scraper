typedef struct _FAX_JOB_PARAMA {
  DWORD      SizeOfStruct;
  LPCSTR     RecipientNumber;
  LPCSTR     RecipientName;
  LPCSTR     Tsid;
  LPCSTR     SenderName;
  LPCSTR     SenderCompany;
  LPCSTR     SenderDept;
  LPCSTR     BillingCode;
  DWORD      ScheduleAction;
  SYSTEMTIME ScheduleTime;
  DWORD      DeliveryReportType;
  LPCSTR     DeliveryReportAddress;
  LPCSTR     DocumentName;
  HCALL      CallHandle;
  DWORD_PTR  Reserved[3];
} FAX_JOB_PARAMA, *PFAX_JOB_PARAMA;