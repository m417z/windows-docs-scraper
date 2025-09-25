typedef struct _CTL_FIND_SUBJECT_PARA {
  DWORD                cbSize;
  PCTL_FIND_USAGE_PARA pUsagePara;
  DWORD                dwSubjectType;
  void                 *pvSubject;
} CTL_FIND_SUBJECT_PARA, *PCTL_FIND_SUBJECT_PARA;