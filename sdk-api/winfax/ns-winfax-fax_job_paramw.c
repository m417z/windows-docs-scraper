typedef struct _FAX_JOB_PARAMW {
  DWORD      SizeOfStruct;
  LPCWSTR    RecipientNumber;
  LPCWSTR    RecipientName;
  LPCWSTR    Tsid;
  LPCWSTR    SenderName;
  LPCWSTR    SenderCompany;
  LPCWSTR    SenderDept;
  LPCWSTR    BillingCode;
  DWORD      ScheduleAction;
  SYSTEMTIME ScheduleTime;
  DWORD      DeliveryReportType;
  LPCWSTR    DeliveryReportAddress;
  LPCWSTR    DocumentName;
  HCALL      CallHandle;
  DWORD_PTR  Reserved[3];
} FAX_JOB_PARAMW, *PFAX_JOB_PARAMW;