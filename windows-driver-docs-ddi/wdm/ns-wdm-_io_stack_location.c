typedef struct _IO_STACK_LOCATION {
  UCHAR                  MajorFunction;
  UCHAR                  MinorFunction;
  UCHAR                  Flags;
  UCHAR                  Control;
  union {
    struct {
      PIO_SECURITY_CONTEXT     SecurityContext;
      ULONG                    Options;
      USHORT POINTER_ALIGNMENT FileAttributes;
      USHORT                   ShareAccess;
      ULONG POINTER_ALIGNMENT  EaLength;
    } Create;
    struct {
      PIO_SECURITY_CONTEXT          SecurityContext;
      ULONG                         Options;
      USHORT POINTER_ALIGNMENT      Reserved;
      USHORT                        ShareAccess;
      PNAMED_PIPE_CREATE_PARAMETERS Parameters;
    } CreatePipe;
    struct {
      PIO_SECURITY_CONTEXT        SecurityContext;
      ULONG                       Options;
      USHORT POINTER_ALIGNMENT    Reserved;
      USHORT                      ShareAccess;
      PMAILSLOT_CREATE_PARAMETERS Parameters;
    } CreateMailslot;
    struct {
      ULONG                   Length;
      ULONG POINTER_ALIGNMENT Key;
      ULONG                   Flags;
      LARGE_INTEGER           ByteOffset;
    } Read;
    struct {
      ULONG                   Length;
      ULONG POINTER_ALIGNMENT Key;
      ULONG                   Flags;
      LARGE_INTEGER           ByteOffset;
    } Write;
    struct {
      ULONG                   Length;
      PUNICODE_STRING         FileName;
      FILE_INFORMATION_CLASS  FileInformationClass;
      ULONG POINTER_ALIGNMENT FileIndex;
    } QueryDirectory;
    struct {
      ULONG                   Length;
      ULONG POINTER_ALIGNMENT CompletionFilter;
    } NotifyDirectory;
    struct {
      ULONG                                                Length;
      ULONG POINTER_ALIGNMENT                              CompletionFilter;
      DIRECTORY_NOTIFY_INFORMATION_CLASS POINTER_ALIGNMENT DirectoryNotifyInformationClass;
    } NotifyDirectoryEx;
    struct {
      ULONG                                    Length;
      FILE_INFORMATION_CLASS POINTER_ALIGNMENT FileInformationClass;
    } QueryFile;
    struct {
      ULONG                                    Length;
      FILE_INFORMATION_CLASS POINTER_ALIGNMENT FileInformationClass;
      PFILE_OBJECT                             FileObject;
      union {
        struct {
          BOOLEAN ReplaceIfExists;
          BOOLEAN AdvanceOnly;
        };
        ULONG  ClusterCount;
        HANDLE DeleteHandle;
      };
    } SetFile;
    struct {
      ULONG                   Length;
      PVOID                   EaList;
      ULONG                   EaListLength;
      ULONG POINTER_ALIGNMENT EaIndex;
    } QueryEa;
    struct {
      ULONG Length;
    } SetEa;
    struct {
      ULONG                                  Length;
      FS_INFORMATION_CLASS POINTER_ALIGNMENT FsInformationClass;
    } QueryVolume;
    struct {
      ULONG                                  Length;
      FS_INFORMATION_CLASS POINTER_ALIGNMENT FsInformationClass;
    } SetVolume;
    struct {
      ULONG                   OutputBufferLength;
      ULONG POINTER_ALIGNMENT InputBufferLength;
      ULONG POINTER_ALIGNMENT FsControlCode;
      PVOID                   Type3InputBuffer;
    } FileSystemControl;
    struct {
      PLARGE_INTEGER          Length;
      ULONG POINTER_ALIGNMENT Key;
      LARGE_INTEGER           ByteOffset;
    } LockControl;
    struct {
      ULONG                   OutputBufferLength;
      ULONG POINTER_ALIGNMENT InputBufferLength;
      ULONG POINTER_ALIGNMENT IoControlCode;
      PVOID                   Type3InputBuffer;
    } DeviceIoControl;
    struct {
      SECURITY_INFORMATION    SecurityInformation;
      ULONG POINTER_ALIGNMENT Length;
    } QuerySecurity;
    struct {
      SECURITY_INFORMATION SecurityInformation;
      PSECURITY_DESCRIPTOR SecurityDescriptor;
    } SetSecurity;
    struct {
      PVPB           Vpb;
      PDEVICE_OBJECT DeviceObject;
      ULONG          OutputBufferLength;
    } MountVolume;
    struct {
      PVPB           Vpb;
      PDEVICE_OBJECT DeviceObject;
    } VerifyVolume;
    struct {
      struct _SCSI_REQUEST_BLOCK *Srb;
    } Scsi;
    struct {
      ULONG                       Length;
      PSID                        StartSid;
      PFILE_GET_QUOTA_INFORMATION SidList;
      ULONG                       SidListLength;
    } QueryQuota;
    struct {
      ULONG Length;
    } SetQuota;
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
    struct {
      SYSTEM_POWER_STATE PowerState;
    } WaitWake;
    struct {
      PPOWER_SEQUENCE PowerSequence;
    } PowerSequence;
#if ...
    struct {
      union {
        ULONG                      SystemContext;
        SYSTEM_POWER_STATE_CONTEXT SystemPowerStateContext;
      };
      POWER_STATE_TYPE POINTER_ALIGNMENT Type;
      POWER_STATE POINTER_ALIGNMENT      State;
      POWER_ACTION POINTER_ALIGNMENT     ShutdownType;
    } Power;
#else
    struct {
      ULONG                              SystemContext;
      POWER_STATE_TYPE POINTER_ALIGNMENT Type;
      POWER_STATE POINTER_ALIGNMENT      State;
      POWER_ACTION POINTER_ALIGNMENT     ShutdownType;
    } Power;
#endif
    struct {
      PCM_RESOURCE_LIST AllocatedResources;
      PCM_RESOURCE_LIST AllocatedResourcesTranslated;
    } StartDevice;
    struct {
      ULONG_PTR ProviderId;
      PVOID     DataPath;
      ULONG     BufferSize;
      PVOID     Buffer;
    } WMI;
    struct {
      PVOID Argument1;
      PVOID Argument2;
      PVOID Argument3;
      PVOID Argument4;
    } Others;
  } Parameters;
  PDEVICE_OBJECT         DeviceObject;
  PFILE_OBJECT           FileObject;
  PIO_COMPLETION_ROUTINE CompletionRoutine;
  PVOID                  Context;
} IO_STACK_LOCATION, *PIO_STACK_LOCATION;