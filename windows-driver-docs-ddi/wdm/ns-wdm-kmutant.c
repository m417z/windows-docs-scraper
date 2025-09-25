typedef struct _KMUTANT {
  DISPATCHER_HEADER Header;
  LIST_ENTRY        MutantListEntry;
  struct _KTHREAD   *OwnerThread;
  union {
    UCHAR MutantFlags;
    struct {
      UCHAR Abandoned : 1;
      UCHAR Spare1 : 7;
    } DUMMYSTRUCTNAME;
  } DUMMYUNIONNAME;
  UCHAR             ApcDisable;
} KMUTANT, *PKMUTANT, *PRKMUTANT, KMUTEX, *PKMUTEX, *PRKMUTEX;