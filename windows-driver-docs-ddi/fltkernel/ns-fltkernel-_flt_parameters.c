typedef union _FLT_PARAMETERS {
  struct {
    PIO_SECURITY_CONTEXT     SecurityContext;
    ULONG                    Options;
    USHORT POINTER_ALIGNMENT FileAttributes;
    USHORT                   ShareAccess;
    ULONG POINTER_ALIGNMENT  EaLength;
    PVOID                    EaBuffer;
    LARGE_INTEGER            AllocationSize;
  } Create;
  struct {
    PIO_SECURITY_CONTEXT     SecurityContext;
    ULONG                    Options;
    USHORT POINTER_ALIGNMENT Reserved;
    USHORT                   ShareAccess;
    PVOID                    Parameters;
  } CreatePipe;
  struct {
    PIO_SECURITY_CONTEXT     SecurityContext;
    ULONG                    Options;
    USHORT POINTER_ALIGNMENT Reserved;
    USHORT                   ShareAccess;
    PVOID                    Parameters;
  } CreateMailslot;
  struct {
    ULONG                   Length;
    ULONG POINTER_ALIGNMENT Key;
    LARGE_INTEGER           ByteOffset;
    PVOID                   ReadBuffer;
    PMDL                    MdlAddress;
  } Read;
  struct {
    ULONG                   Length;
    ULONG POINTER_ALIGNMENT Key;
    LARGE_INTEGER           ByteOffset;
    PVOID                   WriteBuffer;
    PMDL                    MdlAddress;
  } Write;
  struct {
    ULONG                                    Length;
    FILE_INFORMATION_CLASS POINTER_ALIGNMENT FileInformationClass;
    PVOID                                    InfoBuffer;
  } QueryFileInformation;
  struct {
    ULONG                                    Length;
    FILE_INFORMATION_CLASS POINTER_ALIGNMENT FileInformationClass;
    PFILE_OBJECT                             ParentOfTarget;
    union {
      struct {
        BOOLEAN ReplaceIfExists;
        BOOLEAN AdvanceOnly;
      };
      ULONG  ClusterCount;
      HANDLE DeleteHandle;
    };
    PVOID                                    InfoBuffer;
  } SetFileInformation;
  struct {
    ULONG                   Length;
    PVOID                   EaList;
    ULONG                   EaListLength;
    ULONG POINTER_ALIGNMENT EaIndex;
    PVOID                   EaBuffer;
    PMDL                    MdlAddress;
  } QueryEa;
  struct {
    ULONG Length;
    PVOID EaBuffer;
    PMDL  MdlAddress;
  } SetEa;
  struct {
    ULONG                                  Length;
    FS_INFORMATION_CLASS POINTER_ALIGNMENT FsInformationClass;
    PVOID                                  VolumeBuffer;
  } QueryVolumeInformation;
  struct {
    ULONG                                  Length;
    FS_INFORMATION_CLASS POINTER_ALIGNMENT FsInformationClass;
    PVOID                                  VolumeBuffer;
  } SetVolumeInformation;
  union {
    struct {
      ULONG                   Length;
      PUNICODE_STRING         FileName;
      FILE_INFORMATION_CLASS  FileInformationClass;
      ULONG POINTER_ALIGNMENT FileIndex;
      PVOID                   DirectoryBuffer;
      PMDL                    MdlAddress;
    } QueryDirectory;
    struct {
      ULONG                   Length;
      ULONG POINTER_ALIGNMENT CompletionFilter;
      ULONG POINTER_ALIGNMENT Spare1;
      ULONG POINTER_ALIGNMENT Spare2;
      PVOID                   DirectoryBuffer;
      PMDL                    MdlAddress;
    } NotifyDirectory;
    struct {
      ULONG                                                Length;
      ULONG POINTER_ALIGNMENT                              CompletionFilter;
      DIRECTORY_NOTIFY_INFORMATION_CLASS POINTER_ALIGNMENT DirectoryNotifyInformationClass;
      ULONG POINTER_ALIGNMENT                              Spare2;
      PVOID                                                DirectoryBuffer;
      PMDL                                                 MdlAddress;
    } NotifyDirectoryEx;
  } DirectoryControl;
  union {
    struct {
      PVPB           Vpb;
      PDEVICE_OBJECT DeviceObject;
    } VerifyVolume;
    struct {
      ULONG                   OutputBufferLength;
      ULONG POINTER_ALIGNMENT InputBufferLength;
      ULONG POINTER_ALIGNMENT FsControlCode;
    } Common;
    struct {
      ULONG                   OutputBufferLength;
      ULONG POINTER_ALIGNMENT InputBufferLength;
      ULONG POINTER_ALIGNMENT FsControlCode;
      PVOID                   InputBuffer;
      PVOID                   OutputBuffer;
      PMDL                    OutputMdlAddress;
    } Neither;
    struct {
      ULONG                   OutputBufferLength;
      ULONG POINTER_ALIGNMENT InputBufferLength;
      ULONG POINTER_ALIGNMENT FsControlCode;
      PVOID                   SystemBuffer;
    } Buffered;
    struct {
      ULONG                   OutputBufferLength;
      ULONG POINTER_ALIGNMENT InputBufferLength;
      ULONG POINTER_ALIGNMENT FsControlCode;
      PVOID                   InputSystemBuffer;
      PVOID                   OutputBuffer;
      PMDL                    OutputMdlAddress;
    } Direct;
  } FileSystemControl;
  union {
    struct {
      ULONG                   OutputBufferLength;
      ULONG POINTER_ALIGNMENT InputBufferLength;
      ULONG POINTER_ALIGNMENT IoControlCode;
    } Common;
    struct {
      ULONG                   OutputBufferLength;
      ULONG POINTER_ALIGNMENT InputBufferLength;
      ULONG POINTER_ALIGNMENT IoControlCode;
      PVOID                   InputBuffer;
      PVOID                   OutputBuffer;
      PMDL                    OutputMdlAddress;
    } Neither;
    struct {
      ULONG                   OutputBufferLength;
      ULONG POINTER_ALIGNMENT InputBufferLength;
      ULONG POINTER_ALIGNMENT IoControlCode;
      PVOID                   SystemBuffer;
    } Buffered;
    struct {
      ULONG                   OutputBufferLength;
      ULONG POINTER_ALIGNMENT InputBufferLength;
      ULONG POINTER_ALIGNMENT IoControlCode;
      PVOID                   InputSystemBuffer;
      PVOID                   OutputBuffer;
      PMDL                    OutputMdlAddress;
    } Direct;
    struct {
      ULONG                   OutputBufferLength;
      ULONG POINTER_ALIGNMENT InputBufferLength;
      ULONG POINTER_ALIGNMENT IoControlCode;
      PVOID                   InputBuffer;
      PVOID                   OutputBuffer;
    } FastIo;
  } DeviceIoControl;
  struct {
    PLARGE_INTEGER          Length;
    ULONG POINTER_ALIGNMENT Key;
    LARGE_INTEGER           ByteOffset;
    PEPROCESS               ProcessId;
    BOOLEAN                 FailImmediately;
    BOOLEAN                 ExclusiveLock;
  } LockControl;
  struct {
    SECURITY_INFORMATION    SecurityInformation;
    ULONG POINTER_ALIGNMENT Length;
    PVOID                   SecurityBuffer;
    PMDL                    MdlAddress;
  } QuerySecurity;
  struct {
    SECURITY_INFORMATION SecurityInformation;
    PSECURITY_DESCRIPTOR SecurityDescriptor;
  } SetSecurity;
  struct {
    ULONG_PTR ProviderId;
    PVOID     DataPath;
    ULONG     BufferSize;
    PVOID     Buffer;
  } WMI;
  struct {
    ULONG                       Length;
    PSID                        StartSid;
    PFILE_GET_QUOTA_INFORMATION SidList;
    ULONG                       SidListLength;
    PVOID                       QuotaBuffer;
    PMDL                        MdlAddress;
  } QueryQuota;
  struct {
    ULONG Length;
    PVOID QuotaBuffer;
    PMDL  MdlAddress;
  } SetQuota;
  union {
    struct {
      PCM_RESOURCE_LIST AllocatedResources;
      PCM_RESOURCE_LIST AllocatedResourcesTranslated;
    } StartDevice;
    struct {
      DEVICE_RELATION_TYPE Type;
    } QueryDeviceRelations;
    struct {
      const GUID *InterfaceType;
      USHORT     Size;
      USHORT     Version;
      PINTERFACE Interface;
      PVOID      InterfaceSpecificData;
    } QueryInterface;
    struct {
      PDEVICE_CAPABILITIES Capabilities;
    } DeviceCapabilities;
    struct {
      PIO_RESOURCE_REQUIREMENTS_LIST IoResourceRequirementList;
    } FilterResourceRequirements;
    struct {
      ULONG                   WhichSpace;
      PVOID                   Buffer;
      ULONG                   Offset;
      ULONG POINTER_ALIGNMENT Length;
    } ReadWriteConfig;
    struct {
      BOOLEAN Lock;
    } SetLock;
    struct {
      BUS_QUERY_ID_TYPE IdType;
    } QueryId;
    struct {
      DEVICE_TEXT_TYPE       DeviceTextType;
      LCID POINTER_ALIGNMENT LocaleId;
    } QueryDeviceText;
    struct {
      BOOLEAN                                          InPath;
      BOOLEAN                                          Reserved[3];
      DEVICE_USAGE_NOTIFICATION_TYPE POINTER_ALIGNMENT Type;
    } UsageNotification;
  } Pnp;
  struct {
    FS_FILTER_SECTION_SYNC_TYPE    SyncType;
    ULONG                          PageProtection;
    PFS_FILTER_SECTION_SYNC_OUTPUT OutputInformation;
    ULONG                          Flags;
    ULONG                          AllocationAttributes;
  } AcquireForSectionSynchronization;
  struct {
    PLARGE_INTEGER EndingOffset;
    PERESOURCE     *ResourceToRelease;
  } AcquireForModifiedPageWriter;
  struct {
    PERESOURCE ResourceToRelease;
  } ReleaseForModifiedPageWriter;
  struct {
    PIRP                   Irp;
    PVOID                  FileInformation;
    PULONG                 Length;
    FILE_INFORMATION_CLASS FileInformationClass;
  } QueryOpen;
  struct {
    LARGE_INTEGER             FileOffset;
    ULONG                     Length;
    ULONG POINTER_ALIGNMENT   LockKey;
    BOOLEAN POINTER_ALIGNMENT CheckForReadOperation;
  } FastIoCheckIfPossible;
  struct {
    PIRP                           Irp;
    PFILE_NETWORK_OPEN_INFORMATION NetworkInformation;
  } NetworkQueryOpen;
  struct {
    LARGE_INTEGER           FileOffset;
    ULONG POINTER_ALIGNMENT Length;
    ULONG POINTER_ALIGNMENT Key;
    PMDL                    *MdlChain;
  } MdlRead;
  struct {
    PMDL MdlChain;
  } MdlReadComplete;
  struct {
    LARGE_INTEGER           FileOffset;
    ULONG POINTER_ALIGNMENT Length;
    ULONG POINTER_ALIGNMENT Key;
    PMDL                    *MdlChain;
  } PrepareMdlWrite;
  struct {
    LARGE_INTEGER FileOffset;
    PMDL          MdlChain;
  } MdlWriteComplete;
  struct {
    ULONG DeviceType;
  } MountVolume;
  struct {
    PVOID         Argument1;
    PVOID         Argument2;
    PVOID         Argument3;
    PVOID         Argument4;
    PVOID         Argument5;
    LARGE_INTEGER Argument6;
  } Others;
} FLT_PARAMETERS, *PFLT_PARAMETERS;