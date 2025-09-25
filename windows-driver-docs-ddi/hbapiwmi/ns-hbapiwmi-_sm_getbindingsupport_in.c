typedef struct _SM_GetBindingSupport_IN {
  UCHAR HbaPortWWN[8];
  UCHAR DomainPortWWN[8];
} SM_GetBindingSupport_IN, *PSM_GetBindingSupport_IN;