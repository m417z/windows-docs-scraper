typedef struct _MSFC_FibrePortHBAStatistics {
  ULONGLONG              UniquePortId;
  ULONG                  HBAStatus;
  MSFC_HBAPortStatistics Statistics;
} MSFC_FibrePortHBAStatistics, *PMSFC_FibrePortHBAStatistics;