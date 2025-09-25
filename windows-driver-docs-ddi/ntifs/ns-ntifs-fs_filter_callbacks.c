typedef struct _FS_FILTER_CALLBACKS {
  ULONG                          SizeOfFsFilterCallbacks;
  ULONG                          Reserved;
  PFS_FILTER_CALLBACK            PreAcquireForSectionSynchronization;
  PFS_FILTER_COMPLETION_CALLBACK PostAcquireForSectionSynchronization;
  PFS_FILTER_CALLBACK            PreReleaseForSectionSynchronization;
  PFS_FILTER_COMPLETION_CALLBACK PostReleaseForSectionSynchronization;
  PFS_FILTER_CALLBACK            PreAcquireForCcFlush;
  PFS_FILTER_COMPLETION_CALLBACK PostAcquireForCcFlush;
  PFS_FILTER_CALLBACK            PreReleaseForCcFlush;
  PFS_FILTER_COMPLETION_CALLBACK PostReleaseForCcFlush;
  PFS_FILTER_CALLBACK            PreAcquireForModifiedPageWriter;
  PFS_FILTER_COMPLETION_CALLBACK PostAcquireForModifiedPageWriter;
  PFS_FILTER_CALLBACK            PreReleaseForModifiedPageWriter;
  PFS_FILTER_COMPLETION_CALLBACK PostReleaseForModifiedPageWriter;
  PFS_FILTER_CALLBACK            PreQueryOpen;
  PFS_FILTER_COMPLETION_CALLBACK PostQueryOpen;
} FS_FILTER_CALLBACKS, *PFS_FILTER_CALLBACKS;