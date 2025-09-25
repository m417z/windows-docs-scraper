typedef struct _RX_CONTEXT {
  NODE_TYPE_CODE         NodeTypeCode;
  NODE_BYTE_SIZE         NodeByteSize;
  __volatile ULONG       ReferenceCount;
  LIST_ENTRY             ContextListEntry;
  UCHAR                  MajorFunction;
  UCHAR                  MinorFunction;
  BOOLEAN                PendingReturned;
  BOOLEAN                PostRequest;
  PDEVICE_OBJECT         RealDevice;
  PIRP                   CurrentIrp;
  PIO_STACK_LOCATION     CurrentIrpSp;
  PMRX_FCB               pFcb;
  PMRX_FOBX              pFobx;
  PMRX_SRV_OPEN          pRelevantSrvOpen;
  PNON_PAGED_FCB         NonPagedFcb;
  PRDBSS_DEVICE_OBJECT   RxDeviceObject;
  PETHREAD               OriginalThread;
  PETHREAD               LastExecutionThread;
  __volatile PVOID       LockManagerContext;
  PVOID                  RdbssDbgExtension;
  RX_SCAVENGER_ENTRY     ScavengerEntry;
  ULONG                  SerialNumber;
  ULONG                  FobxSerialNumber;
  ULONG                  Flags;
  BOOLEAN                FcbResourceAcquired;
  BOOLEAN                FcbPagingIoResourceAcquired;
  UCHAR                  MustSucceedDescriptorNumber;
  union {
    struct {
      union {
        NTSTATUS StoredStatus;
        PVOID    StoredStatusAlignment;
      };
      ULONG_PTR InformationToReturn;
    };
    IO_STATUS_BLOCK IoStatusBlock;
  };
  union {
    ULONGLONG ForceLonglongAligmentDummyField;
    PVOID     MRxContext[MRX_CONTEXT_FIELD_COUNT];
  };
  PVOID                  WriteOnlyOpenRetryContext;
  PMRX_CALLDOWN          MRxCancelRoutine;
  PRX_DISPATCH           ResumeRoutine;
  RX_WORK_QUEUE_ITEM     WorkQueueItem;
  LIST_ENTRY             OverflowListEntry;
  KEVENT                 SyncEvent;
  LIST_ENTRY             BlockedOperations;
  PFAST_MUTEX            BlockedOpsMutex;
  LIST_ENTRY             RxContextSerializationQLinks;
  union {
    struct {
      union {
        FS_INFORMATION_CLASS   FsInformationClass;
        FILE_INFORMATION_CLASS FileInformationClass;
      };
      PVOID   Buffer;
      union {
        LONG Length;
        LONG LengthRemaining;
      };
      BOOLEAN ReplaceIfExists;
      BOOLEAN AdvanceOnly;
    } Info;
    struct {
      UNICODE_STRING       SuppliedPathName;
      NET_ROOT_TYPE        NetRootType;
      PIO_SECURITY_CONTEXT pSecurityContext;
    } PrefixClaim;
  };
  union {
    struct {
      NT_CREATE_PARAMETERS NtCreateParameters;
      ULONG                ReturnedCreateInformation;
      PWCH                 CanonicalNameBuffer;
      PRX_PREFIX_ENTRY     NetNamePrefixEntry;
      PMRX_SRV_CALL        pSrvCall;
      PMRX_NET_ROOT        pNetRoot;
      PMRX_V_NET_ROOT      pVNetRoot;
      PVOID                EaBuffer;
      ULONG                EaLength;
      ULONG                SdLength;
      ULONG                PipeType;
      ULONG                PipeReadMode;
      ULONG                PipeCompletionMode;
      USHORT               Flags;
      NET_ROOT_TYPE        Type;
      UCHAR                RdrFlags;
      BOOLEAN              FcbAcquired;
      BOOLEAN              TryForScavengingOnSharingViolation;
      BOOLEAN              ScavengingAlreadyTried;
      BOOLEAN              ThisIsATreeConnectOpen;
      BOOLEAN              TreeConnectOpenDeferred;
      UNICODE_STRING       TransportName;
      UNICODE_STRING       UserName;
      UNICODE_STRING       Password;
      UNICODE_STRING       UserDomainName;
    } Create;
    struct {
      ULONG   FileIndex;
      BOOLEAN RestartScan;
      BOOLEAN ReturnSingleEntry;
      BOOLEAN IndexSpecified;
      BOOLEAN InitialQuery;
    } QueryDirectory;
    struct {
      PMRX_V_NET_ROOT pVNetRoot;
    } NotifyChangeDirectory;
    struct {
      PUCHAR  UserEaList;
      ULONG   UserEaListLength;
      ULONG   UserEaIndex;
      BOOLEAN RestartScan;
      BOOLEAN ReturnSingleEntry;
      BOOLEAN IndexSpecified;
    } QueryEa;
    struct {
      SECURITY_INFORMATION SecurityInformation;
      ULONG                Length;
    } QuerySecurity;
    struct {
      SECURITY_INFORMATION SecurityInformation;
      PSECURITY_DESCRIPTOR SecurityDescriptor;
    } SetSecurity;
    struct {
      ULONG                       Length;
      PSID                        StartSid;
      PFILE_GET_QUOTA_INFORMATION SidList;
      ULONG                       SidListLength;
      BOOLEAN                     RestartScan;
      BOOLEAN                     ReturnSingleEntry;
      BOOLEAN                     IndexSpecified;
    } QueryQuota;
    struct {
      ULONG Length;
    } SetQuota;
    struct {
      PV_NET_ROOT VNetRoot;
      PSRV_CALL   SrvCall;
      PNET_ROOT   NetRoot;
    } DosVolumeFunction;
    struct {
      ULONG         FlagsForLowIo;
      LOWIO_CONTEXT LowIoContext;
    };
  };
  PWCH                   AlsoCanonicalNameBuffer;
  PUNICODE_STRING        LoudCompletionString;
  __volatile LONG        AcquireReleaseFcbTrackerX;
  __volatile ULONG       TrackerHistoryPointer;
  RX_FCBTRACKER_CALLINFO TrackerHistory[RDBSS_TRACKER_HISTORY_SIZE];
  ULONG                  ShadowCritOwner;
} RX_CONTEXT, *PRX_CONTEXT;